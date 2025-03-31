#ifndef BICIKLI_H
#define BICIKLI_H

#include <iostream>

class Jarmu {
private:
    double vMax;
public:
    Jarmu(double v) : vMax(v) {std::cout << "\tJarmu ctor vMax=" << vMax << std::endl;}
    Jarmu(const Jarmu& masik):vMax(masik.vMax){std::cout << "\tJarmu copy vMax=" << vMax << std::endl;}
    virtual ~Jarmu(){std::cout << "\tJarmu dtor vMax=" << vMax << std::endl;}

};

class Szan : public Jarmu {
    int kutyakSzama;
public:
    Szan(double v, int n) : Jarmu(v), kutyakSzama(n) {}
    Szan(const Szan& masik):kutyakSzama(masik.kutyakSzama){std::cout << "\tSzan copy kutyakSzama=" << kutyakSzama << std::endl;}
    ~Szan(){std::cout << "\tSzan dtor kutyakSzama=" << kutyakSzama << std::endl;}

};

class Kerek{
    int atmero;
public:
    Kerek(int d = 16):atmero(d){std::cout << "\tKerek ctor\n" << std::endl;}
    void kiir(){ std::cout << "atmero=" << atmero << std::endl; }
    Kerek(const Kerek& masik){
        atmero = masik.atmero;
        std::cout << "\tKerek dtor\n" << std::endl;
    }
    
};


class Bicikli:public Jarmu{
    Kerek elso;
    Kerek hatso;
public:
    Bicikli(double v, int d):Jarmu(v), elso(d), hatso(d){}
};

#endif

