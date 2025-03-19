#include <iostream>
#include <iomanip>

class Ido{
    int ora;
    int perc;

public:
    Ido(){ora = 12; perc = 53;}
    Ido(int h, int p){ora = h; perc = p;}
    void show(){
        std::cout << std::setfill('0') << std::setw(2) << ora <<":"<< std::setfill('0') << std::setw(2) << perc << std::endl;
    }

    Ido operator+(const int a)const{
        if((ora + a) > 23) throw "F9ILEX";

        return Ido(ora+a, perc);
    }
};