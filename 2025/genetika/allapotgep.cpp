/**
 * \file allapotgep.cpp
 *
 * Ebben a fájlban kell megvalósítania az Allapotgep osztály
 * metódusait, valamint mindazon további osztályokat, melyek szükségesek
 * a feladat megvalósításához.
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include <iostream>
#include <fstream>

#include "allapotgep.h"
#include "memtrace.h"


void Allapotgep::konfigural(const char* fajlnev){
        std::ifstream file(fajlnev);
        if (!file.is_open()){
            throw std::runtime_error("F9ILEX");
        }

        //felépiti az allapotgepet, ha van benne valami akkor kitorli



        file.close();
    

}

