/**
 * \file ciphers.h
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#ifndef CipherS_H
#define CipherS_H

#include <string>
#include <vector>
#include "memtrace.h"



/* ========================================================================== */
/*                                   CIPHER                                   */
/* ========================================================================== */
/**
 * Az ős osztály interfésze
 */ 
class Cipher {
public:
    /**
     * Titkosítja a kapott stringet
     * @param   message titkosítandó üzenet
     * @return  a message szöveg titkosított változata
     */
    virtual std::string encode(const std::string& message) = 0;
    /**
     * Dekódolja a kapott stringet
     * @param   ciphertext titkosított üzenet
     * @return  a megfejtett nyílt szöveg
     */
    virtual std::string decode(const std::string& ciphertext) = 0;
    /**
     * Létrehoz egy másolatot dinamikusan
     * @return  a létrehozott objektumra mutató pointer
     */
    virtual Cipher* clone() const = 0;
    /**
     * Alap destruktor
     */ 
    virtual ~Cipher() { };
};


/* ========================================================================== */
/*                                CAESARCIPHER                                */
/* ========================================================================== */


//Osztályok, amiket meg kell csinálni a leírások és az osztálydiagram alapján
class CaesarCipher:public Cipher {
    int shift;
public: 
    CaesarCipher(int);
    std::string encode(const std::string&);
    std::string decode(const std::string&);
    Cipher* clone() const;

};

class MyCipher:public Cipher{
    std::string key;
    int offset;
public:
    MyCipher(std::string);
    MyCipher(std::string, int);
    Cipher* clone() const;
    std::string encode(const std::string&);
    std::string decode(const std::string&);

};


/* ========================================================================== */
/*                                 CIPHERQUEUE                                */
/* ========================================================================== */

class CipherQueue:public Cipher {
    Cipher** tomb;
    size_t meret;

public:
    CipherQueue();
    CipherQueue(CipherQueue const &);
    void add(Cipher* chipher);
    ~CipherQueue();

    std::string encode(const std::string&);
    std::string decode(const std::string&);

    Cipher* clone() const;
    



};

#endif
