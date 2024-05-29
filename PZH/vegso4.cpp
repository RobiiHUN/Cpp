#include <iostream>
#include <vector>

struct Serializable {

        virtual void read(std::istream&) = 0;
        virtual void write(std::ostream&) = 0;
};

class Pont {

protected:
        double x, y;
public:
        Pont(double x = 0, double y = 0):x(x), y(y) {}

};

struct PPont:public Pont, public Serializable{
    PPont(double a = 0, double b = 0):Pont(a,b){}
    double getX()const{return x;}
    double getY()const{return y;}

    void write(std::ostream& os){
        os << x << std::endl;
        os << y << std::endl;
    }

    void read(std::istream& is){
        char buf[100];
        is >> buf;
        if (strcmp(buf, "Pont:") != 0)throw std::out_of_range("nana");
        
        is >> x;
        (is >> y).ignore(10, '\n');
            
        
        
    }

};