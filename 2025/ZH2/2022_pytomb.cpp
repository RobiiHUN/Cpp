#include <vector>
#include <iostream>

template <typename T>
class PyArray:public std::vector<T>{
public:
    PyArray(size_t a):std::vector<T>(a){}
    
    PyArray():std::vector<T>(0){}

    template <typename Iter>
    PyArray(Iter begin, Iter end):std::vector<T>(begin, end){}

    T& operator[](int idx){
        int meret = static_cast<int>(this->size());
        if (idx < 0) idx = meret + idx;
        return this->at(idx);
    }

    const T& operator[](int idx)const{
        int meret = static_cast<int>(this->size());
        if (idx < 0) idx = meret + idx;
        return this->at(idx);
    }


};


int main(){
    PyArray<int> a;
    PyArray<int> vi(3); 
    
    int t[] = {1, 2, 3, 4};
    PyArray <int> vt(t, t+4);

    vi[0] = 1;
    vi[1] = 2;
    vi[2] = 3;

    std::cout << vi[-1] << vi[-2] << vi[-3] << std::endl;
    std::vector<int> v = vi;
    PyArray<double> dd;
    dd.insert(dd.begin(), 3.14);
    std::cout << dd[0] << ' ' << dd[-1];



    





return 0;
}