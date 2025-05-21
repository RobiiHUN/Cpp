#include <iostream>
#include <vector>

class Complex{
protected:
    float r, i;
public:
    Complex(float ri, float ir):r(ri), i(ir){}
    float getI()const{return i;}
    float getR()const{return r;}
};

struct Serializable
{
    virtual void write(std::ostream& os)const = 0;
    virtual void read(std::istream& is) = 0;
};

struct SComplex: public Complex, public Serializable{

    SComplex(float ri, float ii):Complex(ri, ii){}  
    void write(std::ostream& os)const{
        os << "SComplex " << getR() << '+' << getI() << std::endl;
    }
    void read(std::istream& is){
        
        if (!(is >> r)) throw "errir";
        if (!(is >> i)) throw "error";
        
        
    }

};


int main(){
    SComplex sc(3.14f,2.4f);
    sc.write(std::cout);




    return 0;
}

