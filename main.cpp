#include <iostream>
#include "MyString.hpp"

int main(int argc, char** argv) 
{
    const char* h = "hello";

    MyString str(h);                       // init with const char * lvalue
    MyString otherStr("hello");            // init with rvalue ref to std::string

    bool isSame = (str == otherStr);       // equality check
    std::cout << isSame << '\n';

    MyString cat = str + otherStr;         // concatenation
    std::cout << cat.c_str() << std::endl; // output of concatenation

    return 0;
}
