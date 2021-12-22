// ********************************************************
// Header file TreeException.h for the ADT binary tree.
// ********************************************************
#ifndef _TreeException_h_
#define _TreeException_h_

#include <exception>
#include <string>

class TreeException : public std::exception
{
public:
    TreeException(const std::string& message = "")
        : exception()
    {
        m_Message = message;
    };

    ~TreeException() throw(){};

    const char* what() const throw() { return m_Message.c_str(); };

private:
    std::string m_Message;
};

#endif