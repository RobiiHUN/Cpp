#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> indexgen(int also, int felso){
    std::vector<int> eredmeny(felso-also);

    int kivalaszt = also;

    std::generate(also, felso, [&kivalaszt]() {
        return kivalaszt++;
    });

    return eredmeny;


}