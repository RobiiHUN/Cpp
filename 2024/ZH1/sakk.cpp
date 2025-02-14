#include <iostream>

class Tabla{
    
    int sor;
    int oszlop;

    public:
    Tabla(int a, int b):sor(a), oszlop(b){}
    int getSor()const{return sor;}
    int getOszlop()const{return oszlop;}

    Tabla operator=(const Tabla& tabl){
        if (tabl.oszlop != oszlop && tabl.sor != sor)
        {
            oszlop = tabl.oszlop;
            sor = tabl.sor;
        }
        return *this;
    }
    int size(){return sor*oszlop;}

    
};

class Babu: public Tabla{
    int sorszam;

    public:
    Babu(int a, int b, int c):sorszam(a), Tabla(b,c){}

    int getSorszam()const{return sorszam;}
    void print(std::ostream& os)const{
        os<<"\n"<<sorszam<<"   "<<getSor()<< "   " <<getOszlop() <<"\n";}

    

};

void print(Babu& rs){
        std::cout<<rs.getSorszam()<<"   "<<rs.getSor()<< "   " << rs.getOszlop();
    }
void print(Tabla& rs){
        std::cout<<"   "<<rs.getSor()<< "   " << rs.getOszlop();
    }


int main(){
    Babu bab(1,2,3);
    print(bab);

    Tabla tab = bab;
    print(tab);
    std::cout<<"\n"<<bab.size();
    bab.print(std::cout);
    


}