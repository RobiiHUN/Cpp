#include <iostream>

class SzamLista{
    size_t meret;
    int* tomb;
public:
    SzamLista():meret(0), tomb(nullptr){}
    SzamLista(const SzamLista& masik){
        meret = masik.meret;
        tomb = new int[meret];
        for (size_t i = 0; i < meret; i++)
        {
            tomb[i] = masik.tomb[i];
        }
    }
    int getMeret()const{return meret;}
    int gedIDX(const int idx)const{
        if (idx >= meret) throw "errpr";
        return tomb[idx];
    }
    void hozzaad(int szam){
        int* uj = new int [meret + 1];
        for (size_t i = 0; i < meret; i++)
        {
            uj[i] = tomb[i];
        }
        uj[meret] = szam;
        meret++;
        delete[] tomb;
        tomb = uj;         
    }
    int& operator[](int i )const{return tomb[i];}
    void listaz(){
        for (size_t i = 0; i < meret; i++)
        {
            std::cout << tomb[i] << " ";
        }
        std::cout << std::endl;
    }
    int osszeg()const{
        int osszeg = 0;
        for (size_t i = 0; i < meret; i++)
        {
            osszeg += tomb[i];
        }
        return osszeg;
    }
    
    void torol(size_t idx){
        if(idx > meret) throw "baj van";
        int* uj = new int[meret - 1];
        size_t ujidx = 0;
        for (size_t i = 0; i < meret; i++)
        {
            if (i == idx)
            {
                continue;
            }
            uj[ujidx] = tomb[i];
            ujidx++;
        }
        meret--;
        delete[] tomb;
        tomb = uj;
        
    }

};


int main(){
    SzamLista l;
    l.hozzaad(3);
    l.hozzaad(5);
    l.listaz();
    l.torol(0);
    l.listaz();
}