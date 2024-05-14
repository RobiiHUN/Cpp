#include <iostream>

template <typename T, size_t a = 10>
class MySet{
    T* tomb;
    size_t meret;
public:
    MySet(){
        tomb = new T[a];
        meret = a;
    };
    ~MySet(){
        delete[] tomb;
    };
    bool contains(T elem){
        for(size_t i = 0; i < meret; i++){
            if(tomb[i] == elem){
                return true;
            }
        }
        return false;
    }
    void insert(T elem){
        if (contains(elem)){
            return;
        }
        for(size_t i = 0; i < meret; i++){
            if(tomb[i] == 0){
                tomb[i] = elem;
                return;
            }else{
                throw "Nincs hely";
            }
        }
    }
    size_t size(){
        size_t db = 0;
        for(size_t i = 0; i < meret; i++){
            if(tomb[i] != 0){
                db++;
            }
        }
        return db;
    }
    size_t capacity(){
        return meret;
    }

};

int main(){
    MySet<char,5> t;
    std::cout << t.contains('a') << std::endl;
    t.insert('a');  
    std::cout << t.contains('a') << std::endl;



    return 0;
}


