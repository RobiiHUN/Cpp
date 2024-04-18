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


String::String(const String& a){  
    this->len = a.len;
    this->pData = new char[len + 1]; //a lezaro 0-nak kell a plussz egy hely
    strcpy(this->pData, a.pData);
}



String& String::operator=(const String& adott_string){
  if(this != &adott_string){
    delete[] pData;
    this->len = adott_string.len;
    this->pData = new char[len + 1];
    strcpy(this->pData, adott_string.pData);
  }
  return *this;
  
  
  
}

String::String(char karakter): len(1){
  this->pData = new char[2]; //karakter + lezaro 0
  this->pData[0] = karakter; 
  this->pData[1] = '\0';
}

String::String(const char* str):len(strlen(str)){
  this->pData = new char[len + 1];
  strcpy(this-> pData, str);
  
  
}
