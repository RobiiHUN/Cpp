#include <iostream>
#include <vector>

template <typename T>
class PyTomb{
    std::vector <T> tomb;
public:
    PyTomb(){}
    PyTomb(int a){
        tomb = std::vector <T> (a);
    }

    operator std::vector<T>() const {
        return std::vector<T>(tomb.begin(), tomb.end());
    }

    T& operator[](int a){
        if (a < 0 )
        {
            return *(tomb.rbegin() - 1 - a);
        }else if (a < tomb.size())
        {
            return tomb.at(a);
        }
        else{
            throw "Nem jo";
        }
        
    }

    PyTomb(T* begin, T* end){
        for (T* i = begin; i < end; i++)
        {
            tomb.push_back(*i);
        }
    }

    typename std::vector<T>::iterator begin(){
        return tomb.begin();
    }

    void insert(typename std::vector<T>::iterator kezd, double d){
        tomb.insert(kezd, d);
    }








};


int main(){
    PyTomb<int> vi(3);
    vi[0] = 1;
    vi[1] = 2;
    vi[2] = 201;
    std::cout << vi[0] << std::endl;

    int t[] = {1,2,3,4,5};
    PyTomb<int> vt (t, t+5);

    std::vector <int> v = vi;
    PyTomb<double> dd;
    dd.begin();
    
    dd.insert(dd.begin(), 3.14);
    std::cout << dd[0] << "  "<< dd[-1];
    dd[-3];




    return 0;
}