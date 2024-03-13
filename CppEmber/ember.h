#ifndef EMBER_H
#define EMBER_H

#include "memtrace.h"
#include <string.h>

class Ember{
protected:
    char* nev;
    int szulEv;

public:
    Ember(){
        nev = new char[7];
        strcpy(nev, "F9ILEX");
        szulEv = 2004;
    }
    Ember(const char* n, int ev);
    Ember(const Ember& e);
    Ember& operator=(const Ember& e);
    const char* getNev() const;
    virtual int getKor(int ev) const;
    virtual const char* foglalkozas() const;
    virtual ~Ember();

};





#endif