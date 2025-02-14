#include <iostream>
class Integ{
protected:
    double s;
public:
    Integ() :s(0){}
    virtual double getVal() const{
        return s;
    }
    virtual void operator+=(double d) {
        s += d;
    }
    virtual ~Integ(){}

};
std::ostream& operator<<(std::ostream& os, const Integ& i){
    os<< i.getVal() << std::endl;
    return os;
}

class Avarange: public Integ{
    double szamlalo;
public:
    Avarange(): szamlalo(0){}
    double getVal()const{
        if (szamlalo == 0)
        {
            throw "No data";
        }
        else{
            return Integ::getVal()/ szamlalo;
        }    
    }
    void operator+=(double d){
        szamlalo++;
    }

};




int main(){
    std::cout<<Integ()<<std::endl;;
    Integ *s1=new Avarange;
    *s1+=3.0;
    std::cout<<s1->getVal()<<std::endl;;
    std::cout<<*s1<<std::endl;;
    *s1+=2.0;
    std::cout<<*s1<<std::endl;;
    Integ s0=*s1;
    std::cout<<s0<<std::endl;;
    delete s1;

}