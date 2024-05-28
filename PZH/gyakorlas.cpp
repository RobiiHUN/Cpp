#include <vector>
#include <iostream>


std::vector <int> indexgen(int also, int felso){
    std::vector<int> minden(felso - also);
    for (int i = 0; i < felso - also; i++)
    {
        minden[i] = also + i;
    }
    return minden;
    
}

template<typename T, size_t M>
class MySet{
    T tomb[M];
    
public:
    
    MySet(){}

    size_t getSize(){
        return M;
    }

    bool contains(char a){
        for (size_t i = 0; i < getSize(); i++)
        {
            if(tomb[i] == a){
                return true;
            }
        }
        return false;
    }

    void insert(char a){
        for (size_t i = 0; i < getSize(); i++)
        {
            if (!contains(a))
            {
                tomb[i] = a;
                break;
            }
        }
    }

    

};

int main(){
         
    std::vector <int> a = indexgen(10, 13);
    //std::cout << a[0] << ',' << a[1] << ',' << a[2] << std::endl;
    
    MySet<char, 5> t;
    std::cout << t.contains('a') << std::endl;
    t.insert('a');
    std::cout << t.contains('a') << std::endl;

    

    return 0;
}
