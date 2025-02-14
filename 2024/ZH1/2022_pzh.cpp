#include <iostream>

class Store{
    int* data;
    size_t nVal;
public:
    Store() : data(NULL), nVal(0){}
    
    
    Store(const Store& rhs){
        nVal = rhs.nVal;
        data = new int[nVal];
        for (size_t i = 0; i < nVal; i++)
        {
            data[i] = rhs.data[i];
        }
        
    }

    Store& operator=(const Store& rhs){
        if (this != &rhs)
        {
            delete[]data;
            nVal = rhs.nVal;
            for (size_t i = 0; i < rhs.nVal; i++)
            {
                data[i] = rhs.data[i];
            }
            
        }
        return *this;
    }

    void add(int szam){
        int* uj;
        uj = new int[nVal + 1];
        for (size_t i = 0; i < nVal; i++)
        {
            uj[i] = data[i];
        }
        uj[nVal + 1] = szam;
        delete[]data;
        data = uj;
        
    }

    void list(std::ostream& os) const{
        for (size_t i = 0; i < nVal; i++)
        {
            os <<data[i];
        }    
    }

    virtual ~Store(){delete[] data;}



};


// 2.feladat


std::ostream& operator<<(std::ostream& os, const Store& elem){
    elem.list(os);
    return os;
}