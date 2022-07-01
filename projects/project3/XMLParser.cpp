// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"


// use directives
using std::string;

// helper fcns prototypes
static string deleteAttributes(string);
bool isValidName(string);
int charfreq(string,char);


// TODO: Implement the constructor here
XMLParser::XMLParser() : tkn_vec() {
	name_bag = new TAG_BAG;
	tag_stack = new TAG_STACK;
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser(){
	// call destructors (vector is not dynamic, dtor called automatically)
	name_bag->~Bag();
	tag_stack->~Stack();
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const string &str_in){
	size_t idx = 0;
	while(idx < str_in.length()){

		// if space is encountered, increment index and continue
		if(str_in[idx] == ' '){
			idx++;
		}

		// handles tags
		else if(str_in[idx] == '<'){
			TokenStruct ts;

			size_t closing_delimiter = str_in.find('>', idx), L;
			if(closing_delimiter == string::npos)
				return false;
			string tag = str_in.substr( (idx), (closing_delimiter+1) - (idx) );
			L = tag.length();

			ts.tagStruct.full_str = tag;

			bool
				QMS = tag[1] == '?',
				QME = tag[L-2] == '?',
				SLS = tag[1] == '/',
				SLE = tag[L-2] == '/';

			if		(!QMS && !QME && !SLS && !SLE){																		// start tag
				ts.tokenType = START_TAG;
				ts.tagStruct.name_str = deleteAttributes(tag);
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (1), (ts.tagStruct.name_str.length()-1) - (1) );
				ts.tokenString = ts.tagStruct.name;
			}else if(!QMS && !QME &&  SLS && !SLE){																		// end tag
				ts.tokenType = END_TAG;
				ts.tagStruct.name_str = tag;
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (2), (ts.tagStruct.name_str.length()-1) - (2) );
				ts.tokenString = ts.tagStruct.name;
			}else if(!QMS && !QME && !SLS &&  SLE){																		// mt tag
				ts.tokenType = EMPTY_TAG;
				ts.tagStruct.name_str = tag;
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (1), (ts.tagStruct.name_str.length()-2) - (1) );
				ts.tokenString = ts.tagStruct.name;
			}else if( QMS &&  QME && !SLS && !SLE){																		// dec tag
				ts.tokenType = DECLARATION;
				ts.tagStruct.name_str = deleteAttributes(tag);
				ts.tagStruct.name = ts.tagStruct.name_str.substr( (2), (ts.tagStruct.name_str.length()-2) - (2) );
				ts.tokenString = tag.substr( 2, tag.length()-2 - 2 );		// keep attributes for declarations (?)
			}else{
				return false;
			}
			
			if(!isValidName(ts.tagStruct.name))
				return false;
			
			idx += L; 
			tkn_vec.push_back(ts);
		}

		// handle content
		else{
			TokenStruct ts;

			ts.tokenType = CONTENT;
			size_t next_idx = str_in.find('<', idx);
			size_t i = next_idx;
			while(str_in[--i] == ' ');						// decrement index until it is not a space
			ts.tokenString = str_in.substr(idx, 1+i-idx);

			idx = next_idx;
			tkn_vec.push_back(ts);
		}

	}
	return true;
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput(){
	return recursiveParser(0,tkn_vec.size()-1);
}

// recursive variant of above fcn
bool XMLParser::recursiveParser(size_t start_idx, size_t end_idx){
	if(start_idx == end_idx)	// base
		return true;

	// tagstructs in stack are stored in reverse order
	for(size_t i=start_idx; i<=end_idx; i++)
	{	TokenStruct T = tkn_vec[i];

		if(T.tokenType == DECLARATION || T.tokenType == EMPTY_TAG){			// declaration or empty tag
			tag_stack->push(T.tagStruct);		// push struct to stack
		}
		else if(T.tokenType == START_TAG){									// start tag
			tag_stack->push(T.tagStruct);		// push start tag to stack
			int endtagidx = findEndTag(T,i,end_idx);
			if(endtagidx == -1 || !recursiveParser(i,endtagidx))
				return false;
			i = endtagidx + 1;
			tag_stack->push(tkn_vec[i].tagStruct);
		}
	}
	return true;
}

// find corresponding end tag for input start tag
int XMLParser::findEndTag(TokenStruct start_tag, std::size_t start_idx, std::size_t end_idx){
	if(start_tag.tokenType != START_TAG)	// make sure input is a start tag
		return -1;

	// count number of identical start/end tags, push to Identical Index Stack
	Stack<int> IIStack;
	unsigned int s_tag_count = 0, e_tag_count = 0;
	for(int i=start_idx; i<=end_idx; i++)
	{	TokenStruct T = tkn_vec[i];
		if(T.tokenType == START_TAG && T.tokenString == start_tag.tokenString){
			s_tag_count++;
			IIStack.push(i);
		}else if(T.tokenType == END_TAG && T.tokenString == start_tag.tokenString){
			e_tag_count++;
			IIStack.push(i);
		}
	}

	int nest_counter = 0, nest_counter_array[IIStack.size()], NCAidx = IIStack.size(), idxarr[IIStack.size()];
	while(!IIStack.isEmpty())
	{	int i = IIStack.peek();
		
		if(tkn_vec[i].tokenType == END_TAG)
			nest_counter_array[--NCAidx] = nest_counter++;
		else
			nest_counter_array[--NCAidx] = nest_counter--;

		idxarr[NCAidx] = i;

		IIStack.pop();
	}

	int NCA_ET_val = nest_counter_array[0]-1;
	for(int i=0; i < sizeof(nest_counter_array)/sizeof(nest_counter_array[0]); i++){
		if(nest_counter_array[i] == NCA_ET_val){
			return idxarr[i];						// first occurance of nest_count_at_start_tag_index minus one is end tag
		}
	}
	return -1;
	/* e.g.	=======================================================================
			<div> 					<-------- start_tag (input)
				shit 
				<div> 
					more shit 
				</div> 
				shit 2 
				<div> 
					<div> 
						deep shit 
						<notsame>
							not shit
						</notsame>
					</div> 
					more shit 
				</div> 
				last shit 
			</div> 					<-------- end_tag (should return 16)
			<div>
				anotha one
			</div>
		sc = 4
		ec = 4
		stack = [19 17 16 14 12 7 6 4 2 0] (top to bottom)
	*/
}

// TODO: Implement the clear method here
void XMLParser::clear(){
	// clear data members
	name_bag->clear();
	tag_stack->clear();
	tkn_vec.clear();
}

TOKEN_VECTOR XMLParser::returnTokenizedInput() const{
	return tkn_vec;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const string &str_in) const{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const string &str_in) const{
	return -1;
}

/** deletes attrs from tag
 * @param tag 	string of form "<[?/][tag name] [attribute list][?/]>" 
 * @return 		string of form "<[?/][tag name][?/]>" as a new string (to preserve orginal with attributes)	*/
static string deleteAttributes(string tag){
	size_t L = tag.length();
	if(tag[0] != '<' || tag[L-1]!= '>')
		return "";
	
	size_t space_idx = tag.find(' ');
	if(space_idx == string::npos)
		return tag;
	string back;
	if(tag[L-2] == '/' || tag[L-2] == '?')
		back = tag.substr(L-2,1) + ">";
	else
		back = ">";

	return tag.substr(0,space_idx) + back;
}

/** checks if name is valid 
 * @param s		string of the form "[name]" */
bool isValidName(string s){
	if
	(
		// check if string is empty
		s.size() == 0	 ||	
		// check for invalid characters
		s.find("!") != string::npos  || s.find("\"") != string::npos || s.find("#") != string::npos ||  s.find("$") != string::npos ||  
		s.find("%") != string::npos  || s.find("&") != string::npos  || s.find("'") != string::npos ||  s.find("(") != string::npos ||  
		s.find(")") != string::npos  || s.find("*") != string::npos  || s.find("+") != string::npos ||  s.find(",") != string::npos ||  
		s.find("/") != string::npos  || s.find(";") != string::npos  || s.find("<") != string::npos ||  s.find("=") != string::npos ||  
		s.find(">") != string::npos  || s.find("?") != string::npos  || s.find("@") != string::npos ||  s.find("[") != string::npos ||  
		s.find("\\") != string::npos || s.find("]") != string::npos  || s.find("^") != string::npos ||  s.find("`") != string::npos ||  
		s.find("{") != string::npos  || s.find("|") != string::npos  || s.find("}") != string::npos ||  s.find("~") != string::npos ||
		s.find(" ")	!= string::npos  ||
		// check for invalid first characters
		s[0] == '-'		 || s[0] == '.' 	 || s[0] == '0'		||  s[0] == '1'		||
		s[0] == '2'		 || s[0] == '3'		 || s[0] == '4'		||  s[0] == '5'		||
		s[0] == '6'		 || s[0] == '7'		 || s[0] == '8'		||  s[0] == '9'
	) return false;
	return true;
}

/** gets frequency of char c in string str */
int charfreq(string str, char c){
	int count = 0;
	for(char x : str)
		if(x == c)
			count++;
	return count;
}