#include "header.h"


int main(){
    Ido t0;
    Ido t10(10, 3);
    Ido t23(23, 5);

    t0 = t10 + 1;
    t0.show();
    const Ido tc;
    (tc + 1).show();



return 0;
};