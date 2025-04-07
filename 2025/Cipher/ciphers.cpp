/**
 * \file ciphers.cpp
 *
 * Ebben a fájlban kell megvalósítania az CaesarCipher, MyCipher, CipherQueue osztályok metódusait.
 * 
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include "memtrace.h"
#include "ciphers.h"

/* ========================================================================== */
//!                               CAESAR CIPHER                               */
/* ========================================================================== */

CaesarCipher::CaesarCipher(int eltolas){
    shift = eltolas % 26;
    if (shift < 0)
    {
        shift += 26;
    }
    
}

std::string CaesarCipher::encode(const std::string& uzenet) {
    for (char c : uzenet) {
        if (!std::islower(c) && c != ' ') { 
            throw "F9ILEX"; 
        }
    }



    std::string eredmeny = uzenet;
    for (size_t i = 0; i < eredmeny.size(); i++) {
        if (std::isalpha(eredmeny[i])) // csak betukkel foglalkozunk
        {
            eredmeny[i] = (eredmeny[i] - 'a' + shift) % 26 + 'a';       // megnezem hogy a karakter milyen messze van az 'a' betutol majd shift es veszem a mod 26-ot es visszalakitom betuve
        }
        
        }
    return eredmeny;
}

std::string CaesarCipher::decode(const std::string& uzenet) {
    for (char c : uzenet) {
        if (!std::islower(c) && c != ' ') { 
            throw "F9ILEX"; 
        }
    }


    std::string eredmeny = uzenet;
    for (size_t i = 0; i < eredmeny.size(); i++) {
        if (std::isalpha(eredmeny[i])) // csak betukkel foglalkozunk
        { 
            eredmeny[i] = (eredmeny[i] - 'a' - shift + 26) % 26 + 'a';  // hasonlo mint a kodolo csak visszafele shiftelek, +26 azert kell, hogy ne legyen negativ a mod 26 elott
        }
           }
    return eredmeny;
}

Cipher* CaesarCipher::clone() const {
    return new CaesarCipher(*this);
}




/* ========================================================================== */
//!                                 MYCIPHER                                  */
/* ========================================================================== */


MyCipher::MyCipher(std::string str){
    key = str;
}


MyCipher::MyCipher(std::string str, int a){
    key = str;
    offset = a;
}


Cipher* MyCipher::clone() const {
    return new MyCipher(*this);
}


std::string MyCipher::encode(const std::string& uzenet) {
    for (char c : uzenet) {
        if (!std::islower(c) && c != ' ') { 
            throw "F9ILEX"; 
        }
    }


    std::string eredmeny = uzenet;
    size_t szoveg_hossza = key.size();
    for (size_t i = 0; i < eredmeny.size(); i++) {
        if (std::isalpha(eredmeny[i])) { 
            
            char kivalasztott = key[i % szoveg_hossza]; // ha a titkositando szoveg hosszabb, mint a kulcs, akkor a kulcs karakterei idmetlodnek
            int ossz_eltolas = offset + i + (kivalasztott - 'a'); // mennyit kell ossz eltolni
            eredmeny[i] = (eredmeny[i] - 'a' + ossz_eltolas) % 26  + 'a';
        }
    }
    return eredmeny;
}

// Dekódolás
std::string MyCipher::decode(const std::string& uzenet) {
    for (char c : uzenet) {
        if (!std::islower(c) && c != ' ') { 
            throw "F9ILEX"; 
        }
    }

    std::string eredmeny = uzenet;
    size_t szoveg_hossza = key.size();
    for (size_t i = 0; i < eredmeny.size(); i++) {
        if (std::isalpha(eredmeny[i])) { 

            char kivalasztott = key[i % szoveg_hossza]; // ha a titkositando szoveg hosszabb, mint a kulcs, akkor a kulcs karakterei idmetlodnek
            int ossz_eltolas = offset + i + (kivalasztott - 'a');    // mennyit kell ossz eltolni
            eredmeny[i] = (((eredmeny[i] - 'a' - ossz_eltolas) % 26 + 26) % 26 + 'a');
            // a fentebbi keplet megadja elosszor az adott betu sorszamat az abc-ben, majd kovetkezik az eltolas, aztan a mod 26, igy az abc-ben maradunk, +26, hogy pozitivak legyunk, majd megint mod 26, hogy vegul az abc-ben maradjunk, aztan atirjuk betuve
        }
    }
    return eredmeny;
}


/* ========================================================================== */
//!                                CIPHERQUEUE                                */
/* ========================================================================== */

CipherQueue::CipherQueue() : tomb(nullptr), meret(0) {}



CipherQueue::CipherQueue(const CipherQueue& other) : tomb(nullptr), meret(0) {
    if (other.meret > 0) {
        meret = other.meret;
        tomb = new Cipher*[meret];
        for (size_t i = 0; i < meret; ++i) {
            tomb[i] = other.tomb[i]->clone(); 
        }
    }
}

void CipherQueue::add(Cipher* elem) {
    Cipher** uj_tomb = new Cipher*[meret + 1];
    for (size_t i = 0; i < meret; ++i) {
        uj_tomb[i] = tomb[i];
    }

    uj_tomb[meret] = elem;
    delete[] tomb;
    tomb = uj_tomb;
    ++meret;
}    

CipherQueue::~CipherQueue() {
    for (size_t i = 0; i < meret; ++i) {
        delete tomb[i]; 
    }
    delete[] tomb; 
}


std::string CipherQueue::encode(const std::string& uzenet) {
    std::string eredmeny = uzenet; 
    for (size_t i = 0; i < meret; ++i) {
        eredmeny = tomb[i]->encode(eredmeny); 
    }
    return eredmeny; 
}

std::string CipherQueue::decode(const std::string& ciphertext) {
    std::string eredmeny = ciphertext; 
    for (size_t i = meret; i > 0; --i) {
        eredmeny = tomb[i - 1]->decode(eredmeny); 
    }
    return eredmeny; 
}



Cipher* CipherQueue::clone() const {
    return new CipherQueue(*this);
}

