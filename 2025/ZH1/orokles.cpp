#include <iostream>
#include <string>

class Allat{
    std::string nev;
public:
    Allat(std::string n){
        nev = n;
    }
    virtual ~Allat(){}
    virtual void hang()const = 0;
    virtual void bemutatkozik()const{
        std::cout << "Nevem: " << nev << std::endl;
    }
};

class Kutya:public Allat{
    public:
    Kutya(std::string n) : Allat(n) {}
        void hang()const{
            std::cout << "Vau!" << std::endl;
        }
};

class Macska:public Allat{
public:
Macska(std::string n) : Allat(n) {}
void hang()const{
    std::cout << "Miau" << std::endl;
}
};

class Allatkert{
    Allat* allatok[10];
    int db;
public:
Allatkert(){db = 0;}
~Allatkert(){
    for(size_t i = 0; i < db; i++) delete allatok[i];
}
void felvesz( Allat* a){
    if(db >= 10) throw "Mar tele az allatkert!";
    allatok[db] = a;
    db++;
}

void bemutato()const{
    for (size_t i = 0; i < db; i++)
    {
        allatok[i]->bemutatkozik();
    }
    
}
};


int main() {
    Allatkert ak;

    ak.felvesz(new Kutya("Bodri"));
    ak.felvesz(new Macska("Cirmi"));
    ak.felvesz(new Kutya("Loki"));

    ak.bemutato();

    return 0;
}
