#include <iostream>

template <typename T, typename Predikatum>
bool mind_igaz(const T* tomb, const int size, Predikatum pred){
    for (size_t i = 0; i < size; i++)
    {
        if(pred(tomb[i]) == 0) return false;
    }
    return true;
    
}






bool pozitiv(int x) {
    return x > 0;
}

int main() {
    const int a[] = {1, 2, 3, 4};
    int b[] = {1, -2, 3, 4};

    std::cout << mind_igaz(a, 4, pozitiv) << std::endl; // true
    std::cout << mind_igaz(b, 4, pozitiv) << std::endl; // false

  

    return 0;
}