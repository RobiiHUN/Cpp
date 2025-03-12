#include <iomanip>


class Tort{
    int szaml;
    int nev;
public:
    Tort(){szaml = 0; nev = 1;}
    Tort(int s, int n){
        szaml = s;
        nev = n;
    }
    Tort operator/(int n)const{
        if (n == 0) throw "F9ILEX";
        return Tort(szaml, nev * n);
    }
};