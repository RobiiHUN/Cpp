#include <iostream>


class Halmaz{
    int *pData;
    size_t siz;
public:
    Halmaz():pData(nullptr), siz(0){}
    size_t size()const{return siz;}
    
    bool isElement(int a)const{
        if (siz != 0)
        {
            for (size_t i = 0; i < siz; i++)
            {
                if(pData[i] == a) return true;
            }
            
        }
        return false;
    }
    bool empty()const{
        if (siz == 0)
        {
            return true;
        }
        return false;
    }

    bool operator==(const Halmaz& masik)const{
        if (siz != masik.siz) return false;

        for(size_t i = 0; i < siz; i++){
            if (pData[i] != masik.pData[i])
            {
                return false;
            }
            
        }
        return true;
    }

    void insert(int a){
        if(isElement(a)){return;}

        int *uj = new int[siz + 1];
        for(size_t i = 0; i < siz; i++){
            uj[i] = pData[i];
        }
        uj[siz] = a;
        delete[] pData;
        pData = uj;
        siz++;
        

        
        

    }
    
    void kiir()const{
        for (size_t i = 0; i < siz; i++){
            std::cout << pData[i];
        }
        std::cout << std::endl;
    }

    ~Halmaz(){
        delete[] pData;
    }

    void erase(int a){
        if(!isElement(a)) return;

        int *uj = new int[siz - 1];
        size_t index = 0;
        for(size_t i = 0; i < siz; i++){
            if(pData[i] != a){
                uj[index++] = pData[i];
            }
        }
        delete[] pData;
        pData = uj;
        siz--;
    }

    Halmaz operator=(const Halmaz& halmaz)const;

};


class Halmazom:public Halmaz{
public:
    Halmazom(){}
    Halmazom(const Halmaz& h):Halmaz(h){}
    Halmazom& operator+=(const Halmazom& h){
        *this = *this + h;
    }
};


std::ifstream& operator>>(std::ifstream& is, Halmazom h){
    int j;
    for (size_t i = 0; i < 10; i++)
    {
        if (cin>>j)
        {
            h.insert(j);
        } throw "valami";

        
    }
    return is;
    
}