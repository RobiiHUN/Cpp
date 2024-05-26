#include <vector>
#include <iostream>

std::vector <int> szamgen(int kezdo, int bef){
    std::vector <int> szamok;

    for (int i = kezdo; i < bef; i++)
    {
        szamok.push_back(i);
    }
    szamok.pop_back();

    return szamok;
    
}

void kiir(std::vector <int> a){
    for (int i = 0; i < a.capacity(); i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
}




int main(){
    std::vector <int> szamok = szamgen(10, 20);
    kiir(szamok);





    return 0;
}