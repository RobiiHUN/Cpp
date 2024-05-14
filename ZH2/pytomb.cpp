#include <vector>
#include <iostream>

template <typename T>
class PyTomb{
    std::vector<T> tomb;
public:
    PyTomb(){}
    
    PyTomb(int n){
        for (int i = 0; i < n; i++){
            tomb.push_back(i);
        }
    }
    PyTomb(T* begin, T* end){
        for (T* p = begin; p != end; p++){
            tomb.push_back(*p);
        }
    }
    T& operator[](int i){
        if (i < 0 || i >= tomb.size()){
            throw std::out_of_range("Index out of range");
        }
        return tomb[i];
    }


    typename std::vector<T>::iterator begin() {
        return tomb.begin();
    }

    void insert(typename std::vector<T>::iterator pos, const T& value) {
        tomb.insert(pos, value);
    }

};


int main(){  
    PyTomb<int> vi(3);
    vi[0] = 1;
    vi[1] = 2;
    vi[2] = 3;
    std::cout << vi[0] << ',' << vi[1] << ',' << vi[2] << std::endl;
    int t[] = {1, 2, 3};
    PyTomb<int> vt(t, t+3);
    PyTomb<double> dd;
    dd.insert(dd.begin(), 3.14);
    std::cout << dd[0] << std::endl;
    dd[-2]; 



    return 0;
}  