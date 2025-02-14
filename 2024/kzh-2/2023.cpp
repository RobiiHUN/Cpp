#include <iostream>
#include <string>


class Integ{
    double s;
public:
    Integ() : s(0){}
    Integ(const Avarange& av): s(av.getVal()){}
    virtual double getVal()const{return s;}
    virtual void operator+=(double d){s +=d ;}
    virtual ~Integ(){}
};

class Avarange: public Integ{
    double counter;

public:
    Avarange(): counter(10){}
    double getVal()const {
        if (counter == 0)
        {
            throw "No data";
        }   else return getVal() / counter;
        
    }

    void operator +=(double d) {
        Integ::operator+=(d);
        counter++;
    }

    ~Avarange(){};

};

std::ostream& operator<<(std::ostream& os, const Integ& integ){
     os << integ.getVal() << std::endl;
     return os;
}


int main(){

    
    std::cout << Integ();
    Integ *s1 = new Avarange;
    //*s1 += 3.0;
    std::cout << s1->getVal();
    

    //std::cout << Integ();
    //Integ *s1 = new Avarange;
    //*s1 += 3.0;
    //std::cout << s1->getVal();


}