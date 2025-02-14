#include <iostream>
//#include <stdio.h>



class Evfolyam{
    private:
        int ev;
        int honap;
        int nap;

    public:
        
        Evfolyam():ev(2023), honap(12), nap(12){};
        Evfolyam(int ev, int honap, int nap): ev(ev), honap(honap), nap(nap){};


        int getEv()const{return ev;}
        int getHo()const{return honap;}
        int getNap()const{return nap;}

        ~Evfolyam(){};

        Evfolyam operator+(int ujev)const{
            return Evfolyam(this->ev + ujev, this->honap, this-> nap);
        }

       




        


};

   void kiir(Evfolyam& datum){
            std::cout<<"Ev: "<< datum.getEv() << " Honap: " << datum.getHo()  << " Nap: " << datum.getNap() << std::endl;
        }

    Evfolyam operator+(Evfolyam egy, Evfolyam ketto){
            return Evfolyam(ketto.getEv() + egy.getEv(), egy.getHo(), egy.getNap());
        };
    
    Evfolyam operator+(int valami, Evfolyam egy){
            return Evfolyam(valami + egy.getEv(), egy.getHo(), egy.getNap());
        };




int main(){
    //std::cout << "test" << std::endl;
    Evfolyam evfolyam_obj(2023,3,4);
    Evfolyam evfolyam2(2022,11,10);
    Evfolyam evfolyam3 = 3 + evfolyam_obj;

    

    kiir(evfolyam_obj);
    kiir(evfolyam2);
    kiir(evfolyam3);
    
    
    


   //std::cout << evfolyam_obj.getEv() << evfolyam_obj.getNap() << std::endl ;
};
