#include <iostream>
#include <vector>

template<typename T, size_t N = 10>
class MySet{
private:
    std::vector<T> elements;
public:
    MySet():elements(N){}
    MySet(size_t a):elements(a){}

    template <typename Iter>
    MySet(Iter elso, Iter utolso): elements(elso, utolso){}

    bool contains(T elem)const{
       auto eredmeny = std::find(elements.begin(), elements.end(), elem);
       if (eredmeny == elements.end())
       {
        return false;
       }
       return true;
    }
    void insert(T elem){
        int meret = elements.size();
        if (meret == N)
        {
            return;
        }
        elements.push_back(elem);
        
    }

    size_t size()const{
        size_t meret = static_cast<size_t>(elements.size());
        return meret;
    }


    

};

int main(){
    MySet<int> mx;
    mx.contains(4);
    std::cout << mx.size();


    
    return 0;
}