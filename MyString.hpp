#include <memory>
#include <string>
#include <cstring>

struct MyString {

    

    MyString() {};

    MyString(char * string) : innerString(string) {}

    MyString(const char * string) : innerString(string) {
        
        size = strlen(innerString.get());
        
    }

    MyString(std::string& string) : innerString(string.c_str()) {
        
        size = strlen(innerString.get());

    }

    MyString(std::string&& string) : innerString(string.c_str()) {
        size = strlen(innerString.get());
    }

    MyString(MyString& string); //lvalue copy constructor
    MyString(MyString&& string);//rvalue copy constructor

    MyString operator=(MyString& rhs) {

        MyString ret(rhs);

        return ret;
    }

    bool operator==(MyString& rhs) {
        if(size == 0)
            return false;
        if(size != rhs.size)
            return false;
        const char * myStr = get();
        const char * right = rhs.get();

        for(size_t i = 0; i < size; i++) {
            
            if(myStr[i] != right[i]) 
                return false;
        }
        
        return true;
    }

    MyString operator+(MyString& rhs) {

        size_t totalSize = size + rhs.size;

        char * cat;

        strcpy(cat, get());

        strcat(cat, rhs.get());

        MyString ret(cat);

        return ret;
    }

    const char * get() {
        return innerString.get();
    }

    
private:
    std::unique_ptr<const char> innerString;
    size_t size = 0;
};