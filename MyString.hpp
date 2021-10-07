#ifndef _MYSTRING_H__
#define _MYSTRING_H__

#include <memory.h>
#include <ostream>

class MyString
{
public:
  MyString()
  { 
     innerString = nullptr;
     size = 0;
  };

  MyString(const char *pstr) : MyString()
  {
     // User-intervention:
     // make innerString big enough to hold pstr
     // copy pstr into innerString
     // set length size
     // Implement.
  }

  MyString(const MyString& rhs)
  {
     // User-intervention:
     // MyString needs a copy constructor.

     if (this != &rhs)
     {
        // Implement.
     }
  }

  // This is the so-called move constructor
  MyString(MyString&& other)
  {
     // User-intervention:
     // "other" is not const because we're going to release it.
     if (this != &other)
     {
        // Implement.
     }
  }


  MyString& operator=(MyString &rhs) 
  {
     // User-intervention:
     if (this != &rhs)
     {
        // Implement.
     }
     return *this;
  }

  MyString& operator=(MyString&& other)
  {
     if (this != &other)
     {
        // Implement.
     }
     return *this;
  }

  bool operator==(MyString &rhs) 
  {
    // Are we both null?
    bool isNull = (innerString == nullptr);
    bool rhsNull = (rhs.innerString == nullptr);

    // If only one is null, can't be equal.
    if ( isNull ^ rhsNull) {
         return false;
    }

    // If both are null, they are technically equal.
    if ( isNull && rhsNull ) 
    {
         return true;
    }

    // if their sizes don't match, can't be equal.
    if (size != rhs.size)
    {
        return false;
    }

    // Same size, both not null, then compare them:
    return ( 0 == strcmp(rhs.innerString, innerString));
  }

  MyString operator+(const MyString &rhs) 
  {
    // the new string will be totalSize long
    size_t totalSize = size + rhs.size;

    // the new string is therefore larger.
    char* tmp = new char[totalSize];
    // clear it
    bzero(tmp, totalSize);

    // copy the original into the temporary
    my_memcpy(tmp, innerString, size);

    // copy the appendage to the temporary
    my_memcpy(&tmp[size], rhs.innerString, rhs.size);
    
    // set the new innerString
    innerString = tmp;

    // update length
    size = totalSize;

    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const MyString& arg);


  const char* c_str() const 
  { 
      return innerString; 
  }

private:
  char* innerString;
  size_t size;


  void *my_memcpy(void *dest, const void *src, size_t n)
  {
        if (dest == nullptr) {
             return nullptr;
        }

        if (src == nullptr) {
             return dest;
        }

        if ( n == 0 ) {
            return dest;
        }

        // we got something to copy.
        void* ptmp = dest;
        unsigned char* pdst = (unsigned char*) dest;
        unsigned char* psrc = (unsigned char*) src;
      
        for(size_t i = 0; i < n; i++) 
        {
             *pdst++ = *psrc++; 
        }
        return ptmp; 
  }

};

#endif
