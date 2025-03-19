#include <iomanip>


class Ido{
    int ora;
    int perc;
public:
    Ido(){ora = 12; perc = 0;}
    void set(unsigned int ora, unsigned int perc = 0){
        if(ora > 23 || perc > 59) throw "F9ILEX";

        this->ora = ora;
        this->perc = perc;
    }
    int getOra()const{
        return ora;
    }
    int getPerc()const{
        return perc;
    }
    bool operator!=(const Ido& other) const {
        return ora != other.getOra() || perc != other.getPerc();
    }





};