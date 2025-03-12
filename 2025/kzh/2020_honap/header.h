#include <iomanip>


class Honap{
    int sorszam;
public:
    Honap(){sorszam = 3;}
    Honap(int h){sorszam = h;}

    Honap operator+(int h)const{
        if((sorszam + h) > 12){throw "F9ILEX";}

        Honap uj(sorszam + h);
        return uj;
    }


};