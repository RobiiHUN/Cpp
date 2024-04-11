#ifndef USTRING_H
#define USTRING_H

#include "string5.h"
//#include "ustring.cpp"
using namespace std;




class UString: public String{
        static bool allapot;
    public:
        static void UCase(bool);
        bool UCase();
        bool UCase()const;

        

        //konstruktorok
        UString() : String(){};
        UString(char  ch) : String(ch){};
        UString(const char *p) : String(p){};
        UString(const String& s1) : String(s1){};
        //static bool Ucase(){return allapot;};
    

};

//void toUpperCase(string &s);
ostream& operator<<(ostream& os, const UString& s);




//#error "itt deklarálja az UString osztályt"

#endif// USTRING_H
