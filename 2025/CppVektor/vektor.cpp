#include "vektor.h"


size_t Vektor::defSize = 13;
double Vektor::defValue = 43;

Vektor::Vektor(const Vektor& masik){
    pVec = new double[masik.nElements];
    nElements = masik.nElements;

    for (size_t i = 0; i < nElements; i++)
    {
        pVec[i] = masik[i];
    }

}

Vektor::~Vektor(){
    delete[] pVec;
}

Vektor& Vektor::operator=(const Vektor& masik){
    if (pVec == masik.pVec){return *this;}
    delete[] pVec;
    pVec = new double[masik.nElements];
    nElements = masik.nElements;
    for (size_t i = 0; i < nElements; i++)
    {
        pVec[i] = masik[i];
    }
    return *this;
    
}

double& Vektor::operator[](size_t idx){
    if (idx >= nElements or idx < 0){throw "F9ILEX";}
    return pVec[idx];
    
}

const double& Vektor::operator[](size_t idx) const{
    if (idx >= nElements or idx < 0){throw "F9ILEX";}
    return pVec[idx];
}


Vektor operator*(double val, const Vektor& vec){
    if (val == 1) return vec;
    Vektor vek = vec;
    for (size_t i = 0; i < vek.size(); i++)
    {
        vek[i] = vec[i] * val;
    }
    return vek;
    
}