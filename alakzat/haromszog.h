#ifndef HAROMSZOG_H
#define HAROMSZOG

//haramszog -> kesz
//rajztabla
//ellipszis.h  -> ok 

#include "alakzat.h"

class Haromszog : public Alakzat{
    Pont egyik;
    Pont masik;

    public:
        Haromszog(const Pont& p0, const Pont& p2, const Pont& p3, Szin sz):
            Alakzat(p0, sz), egyik(p2), masik(p3){}

        Pont getEgyik() const {return egyik;}
        Pont getMasik() const {return masik;}
        void rajzol()const ;
        //Alakzat* clone(){return new Haromszog(*this);}
        friend std::ostream& operator<<(std::ostream& os, const Haromszog& i){
            return os<< "Haromszog " << (Alakzat&)i << ",p1=" << i.egyik << ",p2=" << i.masik;
        }
};



#endif