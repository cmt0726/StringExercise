#include <iostream>
#include "MyString.hpp"
#include <string>

int main() {

    using namespace std::string_literals;


    const char * h = "hello";

    MyString str(h); //init with const char * lvalue
    MyString otherStr("hello"s); //init with rvalue ref to std::string

    bool isSame = (str == otherStr); //equality check
    std::cout << isSame << '\n';

    MyString cat = str + otherStr; //concatenation
    std::cout << cat.get() << std::endl; //output of concatenation
    
    return 0;
}