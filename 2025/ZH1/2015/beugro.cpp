#include <iostream>

class Osztaly{
public:
    Osztaly(){std::cout << "Hello" << std::endl;}
    Osztaly(const Osztaly& osz){std::cout << "Masol" << std::endl;}
    Osztaly& operator=(const Osztaly& osz){std::cout << "Assign" << std::endl; return *this}
    ~Osztaly(){std::cout << "Destruktor" << std::endl;}
    

};


int main(){
    Osztaly obj;
    Osztaly masik = obj;
    Osztaly harmadik(obj);
    return 0;
}