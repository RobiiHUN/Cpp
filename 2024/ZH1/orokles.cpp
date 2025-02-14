#include <iostream>

class Alap{
    private:
        int szam;
    public:
        Alap():szam(10){};
        int getSzam()const{return szam;}
        //virtual int getDarab(){return szam;}
};

class Leszarmazott : public Alap{
        int darab;
    public:
        Leszarmazott():darab(20){};
        int getDarab()const{return darab;}
};

int main(){
    Leszarmazott test;
    //std::cout<<test.getSzam()<<std::endl;
    //std::cout<<test.getDarab()<<std::endl;

    Alap test2;
    std::cout<<test.getDarab();

}