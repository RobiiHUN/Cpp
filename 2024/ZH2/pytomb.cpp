#include <vector>
#include <iostream>

template<typename T>
class PyTomb{
   std::vector <T> tomb;
public:
    PyTomb(){}
    PyTomb(int a){
        tomb = std::vector<int>(a);
    }
    T& operator[](int i){
        if (i < 0){
        return *(tomb.rbegin() - i - 1);
    }
        
    if (i < tomb.size())
    {
        return tomb.at(i);
    }else{
        throw "exception";
    }
    }
    void size(){return tomb.size();}


    PyTomb(T* begin, T* end){
        for (T* i = begin; i != end ; i++)
        {
            tomb.push_back(*i);
        }
        
    }
    typename std::vector <T>::iterator begin(){
        return tomb.begin();
    }

    void insert(typename std::vector <T>::iterator pos, const T& ertek){
        tomb.insert(pos, ertek);
    }




};

int main(){  
    PyTomb<int> vi(3);
    vi[-1] = 1;
    vi[-2] = 2;
    vi[-3] = 3;
    std::cout << vi[0] << ',' << vi[1] << ',' << vi[2] << std::endl;
    int t[] = {1, 2, 3};
    PyTomb<int> vt(t, t+3);
    PyTomb<double> dd;
    dd.insert(dd.begin(), 3.14);
    std::cout << dd[0] << std::endl;
    dd[-2]; 



    return 0;
}  