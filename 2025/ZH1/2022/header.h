#include <iostream>
#include "string.h"



class SBS{
    size_t siz;
    int *seg;
public:
    SBS():siz(0), seg(new int[siz]){}
    SBS(const int* addr, int num);
    void add(int);
    SBS& operator=(const SBS&);
    
    SBS(const SBS& rhs){
        siz = rhs.siz;
        seg = new int[siz];
        for (size_t i = 0; i < siz; i++)
        {
            seg[i] = rhs.seg[i];
        }
        
    }
    size_t size()const{return siz;}
    const int* getseg()const{return seg;}
    bool operator= (const SBS& rhs) const{
        if (siz != rhs.siz)
        {
            return false;
        }
        for (size_t i = 0; i < siz; i++)
        {
            if (seg[i] != rhs.seg[i])
            {
                return false;
            }
            
        }
        return true;
    }
        void write(std::ostream& os) const {
        os << "SBS objektum tartalma: ";
        for (size_t i = 0; i < siz; ++i) {
            os << seg[i];
            if (i + 1 < siz) {
                os << ", ";
            }
        }
        os << std::endl;
    }
    virtual ~SBS(){
        delete[] seg;
    }

};





void SBS::add(int a){
    int* uj = new int[siz + 1];
    for (size_t i = 0; i < siz; i++)
    {
        uj[i] = seg[i];
    }
    uj[siz] = a;
    delete[] seg;
    seg = uj;
    siz++;
         
}

std::ostream& operator<<(std::ostream& os, const SBS& obj) {
    os << "SBS objektum tartalma: ";
    for (size_t i = 0; i < obj.size(); ++i) {
        os << obj.getseg()[i];
        if (i + 1 < obj.size()) {
            os << ", ";
        }
    }
    return os;
}



class Series:public SBS{
    char* name;
public:
    Series(const char* nev,  int* szamok, size_t hossz){
        SBS(szamok, hossz);
        name = new char[strlen(nev) + 1];
        strcpy(name, nev);
    }
    void write(std::ostream& os)const{
        os << name << ':';
        SBS::write(os); 
    }
    int operator[](int idx)const{
       if(idx > size()) throw "error";
       return getseg()[idx];
    }
};