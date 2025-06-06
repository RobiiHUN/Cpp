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

/* ----------------------------- FILE BEOLVASAS ----------------------------- */

void Allapotgep::konfigural(const char* file_name){
    std::ifstream file(file_name);

    if (file.is_open() == false)    //ha nem sikerulne megnyitni
    {
        throw "F9ILEX";
    }

    alaphelyzet(); //kezdoallapotba rakjuk
    file.close();
    
}



