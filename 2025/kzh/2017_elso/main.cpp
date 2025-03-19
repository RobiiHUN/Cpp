#include "header.hpp"
#include <iostream>


int main(){
    Ido t0, t10, t13;
    t10.set(10); // 10 óra 00 percet állít be
    t13.set(13,21); // 13 óra 21 percet állít be
    if (t13 != t10) std::cout << "elter"; // elter-t ír ki

    return 0;
}