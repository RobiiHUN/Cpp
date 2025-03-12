#include <iomanip>
#include <stdio.h>

class Ido{
int ora;
int perc;

public:
Ido(){ora = 0; perc = 0;}
Ido(int h, int m){ora = h; perc = m;}
Ido operator+(int h)const{
    if ((ora + h) > 24){throw "F9ILEX";}

    Ido uj(ora+h, perc);
    return uj;
}
};