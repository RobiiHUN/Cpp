#include <algorithm>
#include <iostream>
#include <vector>


std::vector<int> indexgen(int start, int end){
    std::vector<int> index;
    for ( int i = start; i < end; i++){
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