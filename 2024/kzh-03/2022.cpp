#include <iostream>


class Summ{
    double s;
    public:
        Summ(): s(0){}
        virtual double getVal()const {return s;}
        virtual void operator+=(double d){s += d;}
        virtual ~Summ(){}
};

std::ostream& operator<<(std::ostream& os, const Summ s){
    os << s.getVal() << std::endl;
    return os; 
}

class Avarage:public Summ{
    double counter;
    public:
        Avarage(): counter(0){}
        double getAtl()const{return Summ::getVal()/ counter;}
        void operator+=(double d){
            counter += d;
            Summ::operator+=(d);
        }
};

std::ostream& operator<<(std::ostream& os, const Avarage s){
    os << s.getAtl() << std::endl;
    return os; 
}




int main(){
    std::cout << Summ();
    Summ* s1 = new Avarage;
    *s1 += 3.0;
    std::cout << s1->getVal();
    std::cout << *s1;
    *s1 += 2.0;
    std::cout << *s1;
    Summ s0 = *s1;
    std::cout << s0;
    delete s1;

    return 0;
}