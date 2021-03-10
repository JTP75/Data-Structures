// Project 2 -- XML Parsing Project

/** XMLParsing class
    @file XMLParse.hpp  */

#ifndef XMLPARSE_HPP
#define XMLPARSE_HPP

#include <string>
#include "Bag.hpp"
#include "Stack.hpp"

/** enum definition for possible string token types. */
typedef enum {START_TAG=1, END_TAG, EMPTY_TAG, CONTENT, DECLARATION} StringTokenType;

/** TokenStruct definition. Used to store tokens and their corresponding types. */
typedef struct _TokenStruct_ {
	StringTokenType tokenType;
	std::string tokenString;
} TokenStruct;

class XMLParser
{
private:
	/** Bag to store the XML element names. Uses the book's Bag implementation. */
	Bag<std::string>* elementNameBag;
	/** Stack to store XML tag names while parsing. Uses your stack implementation. */
	Stack<std::string>* parseStack;
	/** Vector to store the tokenized input string and the token types */
	std::vector<TokenStruct> tokenizedInputVector;
  
  // You can add or change the private fields.

public:
	/** The class constructor.
		@post  Creates an instance of the class that can be used to tokenize and parse an input string . */
	XMLParser();
	/** Scans and tokenizes the input string into XML markup and content. Returns true if all markup (tokens) 
	    in the input string are valid. Valid markup (tokens) are the characters included in a '<' '>' character 
		delimiter pair. The delimiter pairs may not be nested, and the first delimiter in the input string
		must be '<', and the final delimiter must be '>'. If the input string is non-valid (i.e., the function
		returns false, the internal data structure should be empty on exit).
		@post  If successful, the input string is tokenized, the tokens are stored internally.
		@param inputString  The input string.
		@return  true if tokenization was successful, or false if not. */
	bool tokenizeInputString(const std::string &inputString);
	/** Parses a valid tokenized string (stored internally after a successful call to tokenizeInputString)
	    and returns true if the tokenized input is valid XML.  Valid XML satisfies the BPG discussed 
		in the Project Description, where open braces are replaced with a start tag, 
		and the closed brace is replaced by the corresponding end tag. For tag matching, the start tag
		has all white space and attributes removed. For example, the start tag with attributes 
		"<note date="02/22/2017">" matches with the end tag "</note>".  The restriction on the characters 
		that can be used in a tag are given in the Project Description; the method should return false
		if any tag is not valid. To be a valid XML file, the tokenized string must also follow the other
	    constraints noted in the Project Description (e.g., must have one parent element).	If the tokenized 
		data is empty (e.g., we just called clear()), this method should return false.
		@pre  A successfully tokenized input string is stored internally. 
		@post If successful, the tokenized input string is determined to be valid XML.
		@param None.
		@return True if the tokenized string is valid XML, or false if not. */
	bool parseTokenizedInput();
	/** Empties and then fills a given vector with the tokenized input string. This
	    method returns a vector whether or not the tokenized input string was valid XML or not.
	    The vector elements are of type TokenStruct. This data type has two fields,
	    "tokenString" and "tokenType". The types for "tokenType" is an enum
	    with the possible values: START_TAG, END_TAG, EMPTY_TAG, CONTENT, and DECLARATION.
	    These values are available to the application programmer through including the 
	    "XMLParser.h" header file. The token strings corresponding to markup do not
	    include the '<', '>', "<?", "?>", "</", and "/>" delimiters.
		@return  A vector containing all the tokenized input as a vector of type "TokenStruct". */
	std::vector<TokenStruct> returnTokenizedInput() const;
	/** Determines if an element name is contained in valid XML input string.
	    Only finds element names if both the tokenizeInputString() and
		parseTokenizedInput() methods have returned true.
		@pre  A valid XML tokenized input string is stored internally. 
		@param A string containing the element name (case sensitive!).
		@return True if the element name is in the valid XML, or false if not. */
	bool containsElementName(const std::string &inputString) const;
	/** Returns the number of times an element name is contained in valid XML input string.
	    Only returns non-zero frequencies if both the tokenizeInputString() and
		parseTokenizedInput() methods have returned true.
		@pre  A valid XML tokenized input string is stored internally. 
		@param A string containing the element name (case sensitive!).
		@return An int representing the frequency of the element name in the 
		valid XML string. */
	int frequencyElementName(const std::string &inputString) const;
	/** Clears the internal data structures for a instance of the class.
	    @post  The class instance can be used to tokenize a new input string. */
	void clear();
	/** The class destructor. Must free all allocated memory. */
	~XMLParser();
}; // end XMLParser

#endif
