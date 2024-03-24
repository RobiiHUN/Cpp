#include <iostream>


class Ido{
    int ora;
    int perc;

public:
    //konstruktorok
    Ido(): ora(12), perc(23){};
    Ido(int h, int min): ora(h), perc(min){};

    //destruktor;
    ~Ido(){}

    //operator +
    Ido operator+(int h)const{
        if (this ->ora + ora > 24){throw "NEPTUN";}
        return Ido(this->ora + h, perc);
    };

    //operator-
    Ido operator-(int h)const{
        if(this->ora - h <= 0)throw "NEPTUN";
        return Ido(this->ora - h, perc );
    };

    //kiiro
    void kiir()const{std::cout << getOra() << ":" << getPerc() << std::endl;}

    //getterek
    int getOra()const{return ora;}
    int getPerc()const{return perc;}

    //setterek
    void set(int h, int min){
            //ez csak hibakezeles
        if(h>24 || min > 60) throw "NEPTUN";
    
        this-> ora = h;
        this-> perc = min;

    }
};//class vege

//balrol hozzaado 
Ido operator+(int h, const Ido& rhs){
    if (h + rhs.getOra() > 24)throw "NEPTUN";
    return Ido(h + rhs.getOra(), rhs.getPerc());
    
}

//balrol kivono
Ido operator-(int h, const Ido& rhs){
    if (h - rhs.getOra() < 1)throw "NEPTUN";
    return Ido(h - rhs.getOra(), rhs.getPerc());

}

//kiiro, de nagyjabol folosleges
std::ostream& operator<<(std::ostream& os, const Ido& rhs){
    os << rhs.getOra() << ":" << rhs.getPerc() <<std::endl;
    return os;
}

template <typename T>
T max(T a, T b){
    if(a > b) return a;
    return b;
}

