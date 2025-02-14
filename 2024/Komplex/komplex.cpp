/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója.
 *
 * Folytassa a megvalósítást sorrendben a komplex.h fájlban levő feladatoknak megfelelően!
 *
 */


#include <iostream>         // Valószínű, hogy a kiíráshoz majd kell
#include <iomanip>          // ... és ez is.
#include <cmath>            // az sqrt miatt kell.

#include "komplex.h"        // Ebben van a Komplex osztály, és néhány globális függvény deklarációja

///using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret, a headerben soha!

/// Előre elkészített tagfüggvények

/// 0, 1 és 2 paraméteres konstruktor
/// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
/// adtuk meg!
Komplex::Komplex(double r, double im) {
    re = r; // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}



///---- Egy példa a konstans tagfüggvényre, ehhez hasonlóan kell
///     elkészíteni a gettereket az 1. feladatban (ELKESZULT=1)
/// Abszolút érték lekérdezése
/// @return - abszolút érték
double Komplex::abs() const 
{ 
    return sqrt(re*re + im*im); 
}

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false
bool Komplex::operator!=(const Komplex& rhs_k) const {  // visszavezetjük az egyenlőség vizsgálatra
    return !(*this == rhs_k);
}
#endif

#if ELKESZULT >= 6
// 6. feladathoz (ELKESZULT 6)
// a += művelet viszont módosítja önmagát!
/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
    re += rhs_d;
    return *this;
}
#endif

// ------------------------ Eddig elkészítettük -------------------------
// TODO: A hiányzó tag- és globális függvények itt következnek

double Komplex::getRe()const
{
    return re;
}

double Komplex::getIm()const
{
    return im;
}

void Komplex::setRe(double re){
    this->re = re;
}

void Komplex::setIm(double im)
{
    this->im = im;
}

bool Komplex::operator==(const Komplex& right_komplex)const
{
    return re == right_komplex.re && im == right_komplex.im;
}

#if ELKESZULT >=4
Komplex Komplex::operator+(const Komplex& right_komplex)const
{
    return Komplex(re+right_komplex.re, im+right_komplex.im);
}

Komplex Komplex::operator+(double right_komplex)const{
    return *this + Komplex(right_komplex, 0);
}


#endif
#if ELKESZULT >= 5
Komplex operator+(double left_double, const Komplex& right_komplex)
{
    return right_komplex + left_double;
}
#endif  

#if ELKESZULT >= 6
Komplex& Komplex::operator+=(const Komplex& right_komplex)
{
    return *this = *this + right_komplex;
}
#endif  
