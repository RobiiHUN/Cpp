#include <iostream>
#include <iomanip>

class Ido{
    int ora;
    int perc;

public:
    Ido(){
        ora = 12;
        perc = 53;
    }
    Ido(int h, int m){
        ora = h;
        perc = m;
    }
    void show()const{
       std::cout << std::setfill('0') << std::setw(2) << ora << ":"
                 << std::setfill('0') << std::setw(2) << perc << std::endl;
    }
    Ido operator+(int h)const{
        if ((ora + h) > 23){throw "F9ILEX";}

        Ido uj(ora + h, perc);
        return uj;

    }


};