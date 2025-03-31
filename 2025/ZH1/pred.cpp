#include <iostream>

bool paros(int x){
    return x % 2 == 0; 
}

template <typename T, typename Pred>
int szamol_ha(T* tomb, int meret, Pred p){
    int db = 0;
    for(int i = 0; i < meret; i++){
        if(p(tomb[i])) db++;
    }
    return db;
}


struct NagyobbMint5 {
    bool operator()(int x) const {
        return x > 5;
    }
};

int main() {
    int tomb[] = {1, 2, 3, 6, 7, 8};

    std::cout << szamol_ha(tomb, 6, paros) << std::endl;         // 3
    std::cout << szamol_ha(tomb, 6, NagyobbMint5()) << std::endl; // 3

    return 0;
}