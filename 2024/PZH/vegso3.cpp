#include <iostream>
#include <vector>

template <typename T, class C>

class MyVector:public C{
    public:
        MyVector(){}

        template <typename I>
        MyVector(I elso, I utolso):C(elso, utolso){}

        typedef typename C::iterator it;
        it begin(){return C::begin();}
        it end(){return C::end();}
};