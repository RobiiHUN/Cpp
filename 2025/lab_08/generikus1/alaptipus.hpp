#ifndef ALAPTIPUS_HPP
#define ALAPTIPUS_HPP

#include <iostream>


template <typename Iterator>
void kiir(Iterator first, Iterator last) {
    while (first != last) {
        std::cout << *first << " ";
        ++first;
    }
    std::cout << std::endl;
}

template <typename T>
class Alaptipus {
    T adat;
public:
    Alaptipus() : adat(0) {}
    Alaptipus(T value) : adat(value) {}
    operator T&() { return adat; }          
    operator T() const { return adat; }     
    T* operator&() { return &adat; }
    const T* operator&() const { return &adat; }
    virtual ~Alaptipus() {}
};





#endif