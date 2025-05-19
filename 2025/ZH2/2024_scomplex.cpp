#include <iostream>
#include <iomanip>
#include <vector>


class Complex{
    protected:
        float r, i;
    public:
        Complex(float rb, float ib):r(rb), i(ib){}
        float getR()const{return r;}
        float getI()const{return i;}
};

struct Serializable{
    virtual void write(std::ostream& os)const = 0;
    virtual void read(std::istream& is) = 0;
};

class SComplex:public Complex,public Serializable{
    public: 
    SComplex(float rb, float ib):Complex(rb, ib){}


    virtual void write(std::ostream& os)const{
        os << "SComplex " << getR() << " + " << getI() << "\n";
    }

    virtual void read(std::istream& is){
    if (!(is >> r)) throw "wrong";
    if (!(is >> i)) throw "wrong";
    }

};

int main(){
    SComplex s(3.14f, 0.0f);
    s.write(std::cout);
    s.read(std::cin);
    s.write(std::cout);


    return 0;
}