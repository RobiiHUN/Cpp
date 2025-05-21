/**
 * \file pirodistak.h
 * Minden származtatott irodista osztály perzisztens változatának deklarációját ebbe a fájlba tegye!
 * Az egyszerűség kedvéért minden tagfüggvényt inline valósítson meg!
 *
 */
#ifndef PIRODISTAK_H
#define PIRODISTAK_H

#include <stdexcept>
#include "palkalmazott.h"
#include "irodistak.h"


//#error " itt készitse el a PCsopVez, PHatIdeju, PHatIdCsV és PHatIdCsVezH, osztályokat!"

/**
 * Perzisztens csoportvezető
 */
class PCsopVez : public CsopVez {
public:
    using CsopVez::CsopVez;

    
         PCsopVez(const CsopVez& c)
        : Alkalmazott(c.getNev(), c.getFiz()), 
          CsopVez(c.getNev(), c.getFiz(), c.getCs()) {}

    void write(std::ostream& os) const {
        os << getNev() << '\n' << getFiz() << '\n' << getCs() << '\n';
    }

    void read(std::istream& is) {
        std::string n;
        double f;
        csop_t cs;
        std::getline(is, n);
        is >> f;
        is >> cs;
        is.ignore(1); // '\n'
        setNev(n);
        setFiz(f);
        setCs(cs);
    }
};

/**
 * Perzisztens Határozott idejű alkalmazott
 * 
 * 
 */

class PHatIdeju : public HatIdeju {
public:
    using HatIdeju::HatIdeju;

    
    PHatIdeju(const HatIdeju& h)
        : Alkalmazott(h.getNev(), h.getFiz()), HatIdeju(h.getNev(), h.getFiz(), h.getIdo()) {}

    void write(std::ostream& os) const {
        os << getNev() << '\n' << getFiz() << '\n' << getIdo() << '\n';
    }

    void read(std::istream& is) {
        std::string n;
        double f;
        time_t t;
        std::getline(is, n);
        is >> f;
        is >> t;
        is.ignore(1); // '\n'
        setNev(n);
        setFiz(f);
        setIdo(t);
    }
};



/**
 * Perzisztens Határozott idejű csoportvezető
 */


/**
 * Perzisztens Határozott idejű csoportvezető helyettes
 */

#endif // IRODISTAK_H

