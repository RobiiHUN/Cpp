#include "vektor.h"

//Jportas megadott
size_t Vektor::defSize = 13;
double Vektor::defValue = 43;

//destruktor
Vektor::~Vektor(){delete[] pVec;}

//masolas
Vektor::Vektor(const Vektor& forras){
    pVec = new double[forras.nElements];
    nElements = forras.nElements;
    for (unsigned int i = 0; i < nElements; i++){pVec[i] = forras[i];}
}

//egyenloseg operator
Vektor& Vektor::operator=(const Vektor& vektor)
{
    if (pVec == vektor.pVec){return *this;}
    
    delete[] pVec;
    pVec = new double [vektor.nElements];

    nElements = vektor.nElements;
    for (unsigned int i = 0; i < nElements; i++){pVec[i] = vektor.pVec[i];}

    return *this;
}

//index operator
double & Vektor::operator[](size_t idx)
{
    if (idx >= nElements or idx < 0){throw "F9ILEX";}
    return pVec[idx];
}

const double& Vektor::operator[](size_t idx)const
{
    if (idx >= nElements or idx < 0){throw "F9ILEX";}
    return pVec[idx];
}

//szorzas fgv
Vektor operator*(double val, const Vektor& vec){
    Vektor vekt = vec;
    for(unsigned int i = 0; i < vekt.size(); i++){vekt[i]=vekt[i]*val;}
    return vekt;
}