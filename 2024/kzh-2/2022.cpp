#include <iostream>

class Sum{
    double s;

    public: 
        Sum(): s(0){}
        virtual double getVal() const { return s;}
        virtual void operator+=(double d){ s += d;}
        virtual ~Sum(){}

};

class Avarange: public Sum{
    double atlag;

    public:
    Avarange():atlag(0){}
    double getVal()const{return atlag;}
    void operator+=(double d){
        Sum::operator+=(d);
        atlag = atlag + d;
    }

};

std::ostream& operator<<(std::ostream& os, const Avarange& integ){
     return os << integ.getVal() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Sum& integ){
     return os << integ.getVal() << std:: endl;
}



int main(){
    std::cout << Avarange();
    std::cout << Sum();
    Sum *s1 = new Avarange;
    *s1 += 2.0;
    std::cout << s1 ->getVal() <<std::endl;
    std::cout << *s1;
    Sum s0 = *s1;
    std::cout << s0;
    delete s1;
    return 0;
}