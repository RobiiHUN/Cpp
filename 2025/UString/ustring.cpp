#include "ustring.h"

//!error "itt valósítsa meg az UString osztály tagfüggvényeit!"
//!error "ne feledkezzen meg a statikus adattagról sem!"

bool UString::all = false;

bool UString::UCase()const{
    return all;
}


void UString::UCase(bool a){
    all = a;
}

//kiir

std::ostream& operator<<(std::ostream& os, const UString& s){
    if ((s.UCase()) == false)
    {
        os << s.c_str();
    }
    else{
        for (size_t i = 0; i < s.size(); i++)
        {
            os << static_cast<char>(std::toupper(s[i]));
        }
        
    }
    return os;
    
}


