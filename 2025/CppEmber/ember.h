#ifndef EMBER_H
#define EMBER_H
#include <string.h>

class Ember{
protected:
    int szulEv;
    char* nev;
public:
    Ember(){
        szulEv = 2004;
        nev = new char[strlen("f9ilex") + 1];
        strcpy(nev, "F9ILEX");
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