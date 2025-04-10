#include <iostream>

class Halmaz{
    int* pData;
    size_t siz;
public:
    Halmaz():pData(NULL), siz(0){}
    Halmaz(int* tomb, size_t meret) : siz(meret) {
        pData = new int[siz];
        for (size_t i = 0; i < siz; i++) {
            pData[i] = tomb[i];
        }
    }
    
    size_t size()const{return siz;}

    bool isElement(int keres)const{
        if(siz == 0) return false;
        for (size_t i = 0; i < siz; i++)
        {
            if(pData[i] == keres){return true;}
        }
        return false;
    }

    bool empty()const{
        if(siz == 0) return true;
        return false;
    }

    bool operator==(const Halmaz& masik)const{
        for (size_t i = 0; i < masik.siz; i++)
        {
            if(!isElement(masik.pData[i])) return false;
        }
        return true;
    }

    void insert(int mit){
        int* tmp = new int[siz + 1];
        for (size_t i = 0; i < siz; i++)
        {
            tmp[i] = pData[i];
        }
        tmp[siz] = mit;
        delete[] pData;
        pData = tmp;
        siz++;
    }

    ~Halmaz(){delete[] pData;}

    void erase(int torles){
        if(!isElement(torles)) return; 

        int* tmp = new int[siz - 1];
        size_t uj = 0;

        for (size_t i = 0; i < siz; i++)
        {
            if(pData[i] != torles){
                tmp[uj] = pData[i];
                uj++;
            }
        }
        delete[] pData;
        pData = tmp;
        siz--;
    }

    Halmaz operator+(const Halmaz& masik)const{
        
        int* uj = new int[siz + masik.siz];
        for (size_t i = 0; i < siz; i++)
        {
            uj[i] = pData[i];
        }
        for (size_t i = 0; i < masik.siz; i++)
        {
            uj[siz + i] = masik.pData[i];
        }
        return Halmaz(uj,siz + masik.siz);
    }



    





};