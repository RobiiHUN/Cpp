#include <vector>
#include <iostream>

template<typename T, int N = 0>
class ArrayLB:public std::vector<T>{
public:
    ArrayLB():std::vector<T>(){}

    template<typename Iter>
    ArrayLB(Iter first, Iter last):std::vector<T>(first, last){}

    ArrayLB(int a):std::vector<T>(a){}

    T& operator[](int idx){
        return this->at(idx - N);
    }

    const T& operator[](int idx)const{
        return this->at(idx - N);
    }
};


int main(){
    ArrayLB<int, -1> vi(3);
    vi[-1] = 12;
    vi.push_back(15);

    int t[] = {1,2,3,4,5};
    ArrayLB<int, -5> vt(t, t+5);

    std::vector<int> v = vi;
    ArrayLB<double, 10> dd;
    dd.insert(dd.begin(), 3.14);
    std::cout << dd[10];




    return 0;
}