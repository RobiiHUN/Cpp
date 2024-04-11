#ifndef BICIKLI_H
#define BICIKLI_H
#include <iostream>


// KEREK

class Kerek{
    int atmero;
    
    public:
    Kerek(int i): atmero(i){std::cout<< "\tKerek ctor\n" << std::endl;};
    Kerek(){std::cout<< "\tKerek ctor\n" << std::endl;};
    //~Kerek(){std::cout<<"\tKerek dtor\n"<<std::endl;};


    void kiir(){ std::cout << "atmero=" << atmero << std::endl; }
    Kerek(const Kerek& k)
        {
            atmero = k.atmero;
            std::cout << "\tKerek copy\n" << std::endl;
        }

    virtual ~Kerek(){std::cout<< "\tKerek dtor\n";}
};

//MONO

class Monocikli{
    Kerek k;

    public:
    Monocikli(int i): k(i){std::cout<< "\tMonocikli ctor\n" << std::endl;};
    Monocikli(): k(16){std::cout<< "\tMonocikli ctor\n" << std::endl;};
    ~Monocikli(){std::cout<< "\tMonocikli dtor\n" << std::endl;};

    void kiir(){ std::cout << "\tk."; k.kiir();}
    Monocikli(const Monocikli&  m): k(m.k){

        std::cout << "\tMonocikli copy\n" << std::endl;
    }
    
    
};





//JARMU

class Jarmu {
protected:
    double vMax;
public:
    Jarmu(const double v) :vMax(v) {std::cout << "\tJarmu ctor vMax=" << vMax << std::endl;}
    Jarmu(const Jarmu& j): vMax(j.vMax){std::cout<< "\tJarmu copy vMax="  << vMax << std::endl;}
    virtual ~Jarmu(){std::cout << "\tJarmu dtor vMax=" << vMax <<  std::endl;}
};

//SZAAAN
 
class Szan : public Jarmu {
    int kutyakSzama;
public:
    Szan(double v = 0, int n = 0) :Jarmu(v), kutyakSzama(n)
        {std::cout << "\tSzan ctor kutyakSzama=" << kutyakSzama << std::endl;}
    ~Szan(){std::cout << "\tSzan dtor kutyakSzama=" <<  kutyakSzama << std::endl;};


    Szan(const Szan& sz): Jarmu(sz), kutyakSzama(sz.kutyakSzama)
    {
        std::cout << "\tSzan copy kutyakSzama=" << kutyakSzama << std::endl;
        }

};


//BICIKLI

class Bicikli: public Jarmu{
    Kerek elso;
    Kerek masodik;

    public:
    Bicikli(const double v = 0, const int d = 0): Jarmu(v), elso(Kerek(v)), masodik(Kerek(d))
        {std::cout << "\tBicikli ctor "; elso.kiir();};
    ~Bicikli()
    {
        std::cout << "\tBicikli dtor ";
        elso.kiir();
    }

    Bicikli(const Bicikli& b): Jarmu(b), elso(b.elso), masodik(b.masodik){
        std::cout << "\tBicikli copy "; 
        elso.kiir();
    }
};


#endif