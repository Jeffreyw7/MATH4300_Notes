#include <iostring>
#include <utility>
#include "string.h"

String::String(const char *s): len_(std::strlen(s)),data_(new chat(len_ + 1)){
    std::strcpy(data_,s);
}

//Copy Constructor
String::String(const String& other)
    : len_(other.len_), data_(new char[len_ + 1]) {
    std::strcpy(data_, other.data_);
}

//Move Constructor
String::String(String&& other) noexcept
    : len_(other.len_), data_(other.data_) {
    other.len_  = 0;        // leave source in a valid but empty state
    other.data_ = nullptr;  // prevent double-free when source is destroyed
}

//Copy Assignment Operator
tring& String::operator=(const String& other) {
    if (this == &other) return *this; // self-assignment guard
    delete[] data_;                   // free current buffer
    len_  = other.len_;
    data_ = new char[len_ + 1];
    std::strcpy(data_, other.data_);
    return *this;
}

//Move Assignment Operator
String& String::operator=(String&& other) noexcept {
    if (this == &other) return *this;

    delete[] data_;         // free current resource

    len_  = other.len_;
    data_ = other.data_;

    other.len_  = 0;
    other.data_ = nullptr;

    return *this;
}

int main(){
    String a("Hello");
    std:cout << a.c_str() << std::endl;

    //Invoke move constructor
    String b = std::move(a);

    //Now empty
    std:cout << a.c_str() << std::endl;


    //Invokes the copy constructor
    String c(b);
    std:cout << "b:" << b.c_str() << std::endl;
    std:cout << "c:" << c.c_str() << std::endl;


    String d(std::move(b));
    std:cout << "b:" << b.c_str() << std::endl;
    std:cout << "c:" << c.c_str() << std::endl;
    std:cout << "d:" << c.c_str() << std::endl;

    String e("foo");
    e = std::move(0);


    return 0;

}