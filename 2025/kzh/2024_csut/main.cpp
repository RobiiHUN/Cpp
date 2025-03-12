
#include "header.h"

int main(){
    Datum d11, d10;
    d10.set(10, 21);
    d11 = d10 + 1;
    std::cout << d10.getho() <<std::endl;
    std::cout << d10.getnap() <<std::endl;

    const Datum dc;
    (dc + 0).getho();
    dc.getnap();
    dc.getho();

    
    



    return 0;
};