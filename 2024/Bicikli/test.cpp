#include <iostream>
//#include "memtrace.h"
#include "bicikli.h"


/// Utasítást kiíró és végrehajtó makró
/// Utasítás kiíró és végrehajtó makró
#define _(x)  std::cout << #x << std::endl; x
 
int main() {
#if 0
_(    Szan sz1_obj(1.1, 1);         )
#else
_(    Jarmu *jp = new Szan(2.2, 2); )
_(    delete jp;                    )
#endif
_(    return 0;                     )
}
