#include <iostream>




template <typename T>
T atlag(const T* tomb, int meret){
    T sum = 0;
    for (size_t i = 0; i < meret; i++)
    {
        sum = tomb[i] + sum;
    }
    return sum / meret;
}

template <typename T>
bool egyenlo(const T* elso, const T* masodik, int meret){
    for(int i = 0; i < meret; i++){
        if(elso[i] != masodik[i]) return false;
    }
    return true;
}



int main(){
    int tomb1[] = {1,2,3,4,5};
    double tomb2[] = {1.5, 2.2, 4.3};
    std::cout << "Int tomb atlaga: " << atlag(tomb1, 5) << std::endl;
    std::cout << "Double tomb atlaga: " << atlag(tomb2, 3) << std::endl;


    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4};
    int c[] = {1, 2, 3, 5};

    std::cout << egyenlo(a, b, 4) << std::endl; // true
    std::cout << egyenlo(a, c, 4) << std::endl; // false



};
