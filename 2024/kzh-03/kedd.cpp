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

std::ostream& operator<<(std::ostream& os, const Szamlalo& s){
    os << s.get() << std::endl;
    return os;
}

class Ora: public Szamlalo{
    int t;
    public:
    Ora():t(0){}
    Ora(int a): t(0){}
    void novel(){
        Szamlalo::novel();
        if (Szamlalo::get() == t){
            throw "Felkelni\n";
            Szamlalo::set(0);
        }
    }
    void kivetel(int a){
        if (a == t){
            throw "kivetel";
        }
    }


};



int main(){
    std::cout << Szamlalo() << std::endl;

    return 0;
}
