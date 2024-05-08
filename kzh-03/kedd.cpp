#include <iostream>

class Szamlalo{
    int ertek;
public: 
    Szamlalo(): ertek(0){}
    int get()const{return ertek;}
    void set(int v){ertek = v;}
    virtual void novel(){ertek++;}
    virtual ~Szamlalo(){}
};

std::ostream& operator<<(std::ostream& os, const Szamlalo& b){
    os << b.get() << std::endl;
    return os;
}

class Ora: public Szamlalo{
    int ertek;
public:
    Ora(int o): ertek(10){}
    void novel(){
        Szamlalo::novel();
        if (Szamlalo::get() > ertek){
            std::cout << "Felkelni\n" << std::endl;
            Szamlalo::set(0);
        }
    }

};



int main(){
    std::cout << Szamlalo() << std::endl;

    return 0;
}
