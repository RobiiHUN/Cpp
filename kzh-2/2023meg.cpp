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

class Average: public Integ{
    int db;
public:
    Average():db(0){}
    void operator+=(double d){
        Integ::operator+=(d);
        db++;
    }
    double getVal() const{
        return (Integ::getVal())/db;
    }
};

std::ostream& operator<<(std::ostream& os,const Integ &i){
    os<<i.getVal();
    return os;
}

std::ostream& operator <<(std::ostream& os,const Average& a){
    os<<a.getVal();
    return os;
}
int main(){
    std::cout<<Integ()<<std::endl;;
    Integ *s1=new Average;
    *s1+=3.0;
    std::cout<<s1->getVal()<<std::endl;;
    std::cout<<*s1<<std::endl;;
    *s1+=2.0;
    std::cout<<*s1<<std::endl;;
    Integ s0=*s1;
    std::cout<<s0<<std::endl;;
    delete s1;

}
