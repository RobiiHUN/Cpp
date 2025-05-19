#include <iostream>
#include <vector>


template <typename T>

class Tomb{
    std::vector<T> data;
public:
    //Masolo konstruktor
    Tomb(size_t meret, const T& ertek): data(meret, ertek){}


    //Iteratoros konstruktor
    template<typename Iter>
    Tomb(Iter elso, Iter utolso):data(elso, utolso){}

    //operator []
    T& operator[](int index){
        if (idx >= 0)
        {
            if (index >= static_cast<int>(data.size()))
            {
                throw "tul nagy idx";
            }
            return data[index];
            
        }else{
            int poz_idx = static_cast<int>(data.size()) + index;
            if (poz_idx <  0)
            {
                throw "gatya"
            }
            return data[poz_idx];
            }
        
    }

    const T& operator[](int idx)const{
        if (index >= 0) {
            if (index >= static_cast<int>(data.size()))
                throw std::out_of_range("Index out of range (positive)");
            return data[index];
        } else {
            int realIndex = static_cast<int>(data.size()) + index;
            if (realIndex < 0)
                throw std::out_of_range("Index out of range (negative)");
            return data[realIndex];
        }
    }



    
};