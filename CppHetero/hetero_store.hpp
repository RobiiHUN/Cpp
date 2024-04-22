/**
 * \file: hetero_store.hpp
 *
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>


////#error "Itt készítse el a HeteroStore sablont!"

template <typename T, size_t N = 100, class E = std::out_of_range>

class HeteroStore
{
private:
    T* store[N];
    size_t db;    

public: 
    HeteroStore() : db(0) {}
    
    size_t size() const{return db;}
    size_t capacity() const{return N;}

    void add(T* t)
    {
        if (db == N){ delete t; throw E("nem jo, nincs hely");}
        store[db++] = t;
    }
    template<typename Z>
    void traverse(Z f)
    {
        for(size_t i = 0; i < db; i++)
        {
            f(store[i]);
        }
        
    }
    void clear()
    {
        for(size_t i = 0; i < db; i++)
        {
            delete store[i];
        }
        db = 0;
    }
    ~HeteroStore(){clear();}



};






#endif // HETEROSTORE_HPP
