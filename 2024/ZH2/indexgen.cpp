#include <algorithm>
#include <iostream>
#include <vector>


std::vector <int> indexgen(int a, int b){
    std::vector<int> index;
    for (int i = a; i < b; i++)
    {
        index.push_back(i);
    }
    return index;
    
}


int main(){
    std::vector<int> t = indexgen(0,4);
    for (int k :t){
        std::cout << k << ',';
    }

    return 0;
}