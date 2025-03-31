/**
 *
 * \file string5.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
String::String(const char ch){
   len = 1;
   pData = new char[len+1];
   pData[0] = ch;
   pData[1] = '\0';
}

///                egy nullával lezárt char sorozatból (createString)

String::String(const char *str){
  len = strlen(str);
  pData = new char[len + 1];
  strcpy(pData, str);

}

/// Másoló konstruktor: String-ből készít (createString)

String::String(const String& s1) {
    len = s1.len;
    pData = new char[len + 1];
    strcpy(pData, s1.pData); 
}

/// Destruktor (disposeString)

/// operator=
String& String::operator=(const String& s) {
    if (this != &s) { 
        delete[] pData; 
        len = s.len;
        pData = new char[len + 1]; 
        strcpy(pData, s.pData); 
    }
    return *this; 
}



char& String::operator[](unsigned int idx) {
    if (idx >= len) throw "F9ILEX";
    return pData[idx];
}


const char& String::operator[](unsigned int idx) const {
    if (idx >= len) throw "F9ILEX";
    return pData[idx];
}
std::ostream& operator<<(std::ostream& os, const String& s0){
  os << s0.pData;
  return os;
}
String String::operator+(const char ch) const {
    String uj;
    uj.len = len + 1; 
    uj.pData = new char[uj.len + 1]; 
    strcpy(uj.pData, pData); 
    uj.pData[len] = ch; 
    uj.pData[uj.len] = '\0'; 
    return uj; 
}

String String::operator+(const String& s) const {
    String uj;
    uj.len = len + s.len;
    uj.pData = new char[uj.len + 1];
    strcpy(uj.pData, pData);
    strcat(uj.pData, s.pData);
    return uj;
}

String operator+(const char ch, const String& s) {
    String uj;
    uj.len = s.len + 1; 
    uj.pData = new char[uj.len + 1]; 
    uj.pData[0] = ch; 
    strcpy(uj.pData + 1, s.pData); 
    uj.pData[uj.len] = '\0'; 
    return uj; 
}





