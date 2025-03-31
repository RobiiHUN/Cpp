#include <iostream>
#include <cstring>


class String_2{
    char* str;
    size_t len;
public:
    String_2(){str = nullptr; len = 0;}
    String_2& operator=(const String_2& st){
        if(this == &st) return *this;

        delete[] str;
        len = st.len;
        str = new char[len + 1];
        strcpy(str, st.str);
        return *this;
    }

    String_2& operator+=(const char masik){
        *this = *this + masik;
        return *this;
    }

    String_2 operator+(const char masik)const{
        String_2 uj;
        return *this + String_2(masik);
    }

    
};