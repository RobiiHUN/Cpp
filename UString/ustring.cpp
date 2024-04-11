#include "ustring.h"


using namespace std;



//#error "itt valósítsa meg az UString osztály tagfüggvényeit!"
//#error "ne feledkezzen meg a statikus adattagról sem!"


bool UString::allapot = false;

void UString::UCase(bool igaz_ham){
    allapot = igaz_ham;
}

bool UString::UCase(){
    return allapot;
}
bool UString::UCase()const{
    return allapot;
}


//kiir

ostream& operator<<(ostream& os, const UString& s){
    if ((s.UCase()) == false)
    {
        os << s.c_str();
    }
    else{
        for (size_t i = 0; i < s.size(); i++)
        {
            os<<static_cast<char>(toupper(s[i]));
        }
        
    }
    return os;
    
}


