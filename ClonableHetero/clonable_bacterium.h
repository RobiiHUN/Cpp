/**
 * \file: clonable_bacterium.h
 *
 */

#ifndef CLONABLE_BACTERIUM_H
#define CLONABLE_BACTERIUM_H

#include "bacterium.h"
#include "clonable.h"



/**
 * A ClonableBacterium, ClonableSalmonella, ClonableStreptococcus
 * osztályoknak kompatibilisnek kell lennie a Bacterium és Clonable osztályokkal.
 * A funkciókat tekintve meg kell egyezni a Bacterium, Salmonella, Streptococcus
 * osztályok funkcióival.
 */



class ClonableBacterium:public Bacterium, public Clonable{
public:
    ClonableBacterium(const char *a = "") : Bacterium(a){}

    ClonableBacterium* clone() const {
        return new ClonableBacterium(*this);
    }

    virtual ~ClonableBacterium() {};

};

class ClonableSalmonella:public ClonableBacterium{
    std::string species;
public:
    explicit ClonableSalmonella(const char *a) : ClonableBacterium("Salmonella"), species(a) {}

    void show(std::ostream& os) const {
        Bacterium::show(os);
        os << " Fajta: " << species;
    }

    ClonableSalmonella* clone() const {
        return new ClonableSalmonella(*this);
    }

    virtual ~ClonableSalmonella() {};
};

class ClonableStreptococcus:public ClonableBacterium{
    char group;
public:
    ClonableStreptococcus(char a) : ClonableBacterium("Streptococcus"), group(a) {}

    void show(std::ostream& os) const {
        Bacterium::show(os);
        os << " Csoport: " << group;
    }

    ClonableStreptococcus* clone() const {
        return new ClonableStreptococcus(*this);
    }

    virtual ~ClonableStreptococcus() {};
};


#endif // CLONABLE_BACTERIUM_H
