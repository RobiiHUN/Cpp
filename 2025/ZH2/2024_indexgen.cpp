#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

std::vector<int> indexgen(int also, int felso){
    std::vector<int> eredmeny(felso - also);
    int kivalaszt = also;
    std::generate(eredmeny.begin(), eredmeny.end(), [&kivalaszt]() {
        return kivalaszt++;
    });
    return eredmeny;
}



int main(){
    std::vector<int> t = indexgen(0, 4);
    for(int k :t) std::cout<< k << ',';


    return 0;
};