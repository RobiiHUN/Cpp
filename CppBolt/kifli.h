#ifndef KIFLI_H
#define KIFLI_H


#include "aru.h"

class Kifli :public Aru
{
private:
    String fajta;
public:
    Kifli(double ar, const char *tipus = ""): Aru("Kifli", "db", ar), fajta(tipus){};
    //~Kifli();

    std::ostream& print(std::ostream& os) const
    {
        return os << megnevezes << " " << fajta << "; " << ar << "Ft/" << egyseg;
    }
};









#endif