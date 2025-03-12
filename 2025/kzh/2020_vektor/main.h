#include <iomanip>

class Vektor{
    double x;
    double y;
public:
    Vektor(){x = 0; y = 0;}
    Vektor(double a, double b){x = a, y = b;}

    Vektor operator/(int os)const{
        if (os == 0) throw "NWJSJ";

        return Vektor(x / os, y / os);
    }
};