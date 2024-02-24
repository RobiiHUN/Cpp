#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */



/**
 * Saját atoi.
 * Számjegyeket tartalmazó karaktersorozat átalakítása int-re.
 * Helyes számjegysorozat végét white space, vagy sztring vége ('\0') jelzi.
 *   Ha a számjegysorozatban olyan számjegy, vagy betű fordul elő,
 *   ami nem érvényes az adott számrendszerben, az hiba.
 *   Pl. hármas számrendszerben nem fordulhat elő a 3-as számjegy, de az A betű sem.
 * Hiba esetén egy const char* típusú kivételt kell dobni, melynek értéke
 * az Ön neptun azonosítója!
 * @param p    - pointer a sztringre
 * @param base - számrendszer alapja (0-10)
 * @return     - base számrendszerben értelmezett szám
 */

int atoi(const char *p, int base = 10){
    if (base < 2 || base > 10)
    {
        throw "F9ILEX";
    }
    int eredmeny = 0;
    int i = 0;

    //white space kerules
    while (p[i] == ' ' || p[i] == '\t')
    {
        ++i;
    }
    //megfelelo bemenet kezelese
    int szamlalo = 1;
    if (p[i] == '+' || p[i] == '-')
    {
        szamlalo = (p[i++] == '+') ? 1 : -1;
    }

    //konvertalo resz
    while ('0' <= p[i] && p[i] <= '9')
    {
        int szam = p[i] - '0';
        if (szam >= base)
        {
            throw "F9ILEX";
        }
        eredmeny = eredmeny * base + szam;
        i++;
    }
    return szamlalo * eredmeny;
}
    
    
    