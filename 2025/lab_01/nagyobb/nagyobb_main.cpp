// Fájl: nagyobb_main.cpp
// Egyszerű demo program.
// Bekér két egész számot és kiírja a nagyobbat.

#include <iostream>
#include <iomanip>
#include "fuggvenyeim.h"
using namespace std;

int main() {

     cout << "Kerek ket egesz szamot:";

     int i, j;
     cin >> i >> j;                    // i és j értékének beolvasása
     int k  = max(i,  j);
     cout << "A nagyobb: " << k  << endl; // nagyobb kiírása
}
