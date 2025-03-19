/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"

double alap_ertek = 999999;

#ifndef NO_STATIC
void Resistor::setDef(double r)
{
    alap_ertek = r;
}
#endif

Resistor::Resistor(){R = alap_ertek;}


Resistor::Resistor(double R){
    this->R = R;
}

Resistor Resistor::operator+(const Resistor& r) const{
    Resistor soros(r.getR() + R);
    return soros;
}


Resistor Resistor::operator%(const Resistor& r)const{
    return Resistor(1/((1/R)+(1/r.getR())));
}

Resistor operator* (int n, const Resistor& r)
{
    if (n <= 0)
        throw "F9ILEX";

    return Resistor(n*r.getR());
}


Resistor::Resistor(const Resistor& rhs){
    R = rhs.getR();
}

Resistor::~Resistor(){}

Resistor& Resistor::operator=(const Resistor& rhs){
    R = rhs.getR();
    return *this;
}

double Resistor::getI(double u) const{
    return (u / R);
}

double Resistor::getU(double i) const{
    return R*i;
}