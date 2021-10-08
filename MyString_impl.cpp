#include "MyString.hpp"

std::ostream& operator<<(std::ostream& os, const MyString& arg)
{
    const char* pbuf = arg.c_str();

    // Be nice
    if (pbuf == nullptr) {
       os << "(null)";
    }
    // Oh we got a string, print it.
    else {
       os << pbuf;
    }
    // Return the stream
    return os;
}
   
