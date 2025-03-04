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
        int result = 0;
        while(isspace(*p)){
            p++;
        }
        while(isdigit(*p)){
            if(*p - '0' >= base){
                throw "F9ILEX";
            }
            result = result * base + (*p - '0');
            p++;
        }
        return result;
    }

    char *strcat(const char *p1, const char *p2) {
        char *result = new char[strlen(p1) + strlen(p2) + 1];
        strcpy(result, p1);
        strcpy(result + strlen(p1), p2); 
        return result;
    }

    char *unique(char *first, char *last){
        if (first == last) return last;

        char *result = first;
        while(first != last){
            if(*first != *result){
                result++;
                *result = *first;
            }
            first++;
        }
        return result;
    }
}