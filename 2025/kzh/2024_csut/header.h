#include <iostream>
#include <iomanip>

class Datum{
    int ho;
    int nap;
public:
    Datum(){
        ho = 9;
        nap = 1;
    }
    
    void set(int h, int n){
        ho = h;
        nap = n;
    }
    int getho()const{return ho;}

    int getnap()const{return nap;}

    Datum operator+(int h)const{
        if((h + ho) > 12){throw "F9ILEX";}

        Datum uj;
        uj.set(h + ho, nap);
        return uj;
    }
};