#include <iostream>
#include <vector>


template<typename T>

class Indexelheto {
   std::vector<T> tomb;
public:
    Indexelheto(int a){
        tomb = std::vector<int>(a);
    }

    T& operator[](int a){
        return tomb.at(a);
    }





};

bool negativ (int a){ return a < 0;}

template<typename T, typename P>
T keres(T eleje, T vege, P pred){
    while (eleje != vege)
    {
        if (pred(*eleje))
        {
            return eleje;
            ++eleje;
        }
        return eleje;
    }
    return eleje;
}

int main(){
    Indexelheto<int> v10(2);
    v10[0] = 1;
    v10[1] = 54; 

    std::cout << v10[0] << std::endl;

    int sorozat[] = { 1, 4, 9, -16, 25, 0, 72, 100, 0};
    int* eredmeny = keres(sorozat, sorozat + 9, negativ);

    std::cout << *eredmeny << std::endl;

    return 0;
}