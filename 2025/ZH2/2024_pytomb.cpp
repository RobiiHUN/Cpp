#include <iostream>
#include <iomanip>
#include <vector>

template <typename T>
class PyTomb{
    std::vector<T> tomb;
public:
    PyTomb(int meret, const T& adat):tomb(meret, adat){}
    PyTomb(int meret):tomb(meret){}

    template<typename Iter>
    PyTomb(Iter first, Iter last):tomb(first, last){}

    T& operator[](int idx) {
        if (idx >= 0) {
            return tomb.at(idx);
        } else {
            int pozitiv = static_cast<int>(tomb.size()) + idx;
            return tomb.at(pozitiv);
        }
    }
};

int main(){
    PyTomb<int> v(3);
    v[0] = 1;
    v[1] = 4;
    v[2] = 8;

    std::cout << v[-1] << v[-2] << v[-3];
    return 0;
}