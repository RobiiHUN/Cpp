#include <iostream>
#include <iomanip>

class Num{
 int szam;

public:
    Num(){szam = 0;}
    Num(int s){szam = s;}
    int getszam()const{
        return szam;
    }
    void setter(int s){szam = s;}
    bool operator==(const Num n)const{
        if (n.getszam() == szam) return true;
        return false;
    }
    Num operator=(const Num n)const{
        Num uj;
        uj.setter(n.getszam());
        return uj;
    }

};