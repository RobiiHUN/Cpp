#ifndef USTRING_H
#define USTRING_H

#include "string5.h"

//!error "itt deklarálja az UString osztályt"

class UString:public String{
    static bool all;

public:
    UString(char a):String(a){}
    UString() : String(){}
    UString(const char* str):String(str){}
    UString(const String& s1) : String(s1){}

    bool UCase()const;
    static void UCase(bool);






};

std::ostream& operator<<(std::ostream& os, const UString& s);








#endif // USTRING_H
