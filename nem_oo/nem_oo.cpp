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

namespace sajat{

int atoi(const char *p, int base){
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
    

char *strcat(const char *p1, const char *p2){
    char *eredmeny = new char[strlen(p1) + strlen(p2) + 1];
    strcpy(eredmeny, p1);
    strcpy(eredmeny + strlen(p1), p2);
    
    return eredmeny;
}


char *unique(char *first, char *last){
    char *eredmeny = first;
    while (first < last)
    {
        *eredmeny = *first;
        char jelenlegibetu = *first;
        while (first < last && *first == jelenlegibetu)
        {
            ++first;
        }
        eredmeny++;
    }
    return eredmeny;
    
}

}