
#include <iostream>

class Kerek{
    int atmero;
    
    public:
    Kerek(int i): atmero(i){std::cout<< "\tKerek ctor\n" << std::endl;};
    Kerek(){std::cout<< "\tKerek ctor\n" << std::endl;};
    ~Kerek(){std::cout<<"\tKerek dtor\n"<<std::endl;};


    void kiir(){ std::cout << "atmero=" << atmero << std::endl; }
    Kerek(Kerek& k)
        {
        atmero = k.atmero;
        std::cout << "\tKerek copy\n" << std::endl;
        }

};

class Monocikli{
    Kerek k;

    public:
    Monocikli(int i): k(i){std::cout<< "\tMonocikli ctor\n" << std::endl;};
    Monocikli(){std::cout<< "\tMonocikli ctor\n" << std::endl;};
    ~Monocikli(){std::cout<< "\tMonocikli dtor\n" << std::endl;};

    void kiir(){ std::cout << "\tk."; k.kiir();}
    Monocikli(Monocikli& m){

        std::cout << "\tMonocikli copy\n" << std::endl;
    }
    
};

//void kiir(){}; //TODO ezt meg kell csinalni
