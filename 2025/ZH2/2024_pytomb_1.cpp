#include <iostream>
#include <vector>

template<typename T>
class PyTomb:public std::vector<T>{
public:
    PyTomb():std::vector<T>(){}
    PyTomb(int a):std::vector<T>(a){}

    template<typename Iter>
    PyTomb(Iter begin, Iter end):std::vector<T>(begin, end){}

    T& operator[](int a){
        int idx = static_cast<int>(this->size());
        if (a < 0)
        {
            a = idx + a;
        }
        return this->at(a);
    }

    const T& operator[](int a)const{
        int idx = static_cast<int>(this->size());
        if (a < 0)
        {
            a = idx + a;
        }
        return this->at(a);
    }
    


};

int main(){
    PyTomb<int> v(3);
    v[0] = 1;
    v[1] = 4;
    v[2] = 8;

    std::cout << v[-1] << v[-2] << v[-3];
    int tomb[] = {1,2,3,4,5};
    PyTomb<int> vt(tomb, tomb+5);

    std::vector<int> vi = v;
    PyTomb<double> dd;
    dd.insert(dd.begin(), 3.14);
    std::cout << dd[0] << ' ' << dd[-1];
    return 0;
}