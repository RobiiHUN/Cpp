#include <iostream>
#include <iomanip>
#include <vector>
#include <cstddef>

template <typename T, size_t M = 10>
class MySet{
    T* elements;
    size_t meret;

public:
    MySet(){elements = new T [M]; meret = 0;}
    ~MySet(){delete[] elements;}

    bool contains(T keres)const{
        if (meret == 0) return false;
        for (size_t i = 0; i < meret; i++)
        {
            if (keres == elements[i])
            {
                return true;
            }
            
        }
        return false;
    }

    void insert(T elem){
        if (contains(elem) ||  (meret == M))
        {
            throw "F9ILEX";
        }
        
        elements[meret] = elem;
        meret++;
    }

    size_t size()const{return meret;}
    size_t capacity()const{return M;}

};

int main(){
    MySet<char, 5>t;
    std::cout << t.contains('a');
    t.insert('a');
    std::cout << t.contains('a');



    return 0;
};
