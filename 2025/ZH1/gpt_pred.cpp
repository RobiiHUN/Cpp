#include <iostream>

template <typename T, typename Pred>
bool ellenoriz(const T ertek, const Pred pre){
    return pre(ertek);
}

bool pozitiv(int x) {
    return x > 0;
}

int main() {
    using namespace std;
    cout << ellenoriz(5, pozitiv) << endl;     // true (1)
    cout << ellenoriz(-3, pozitiv) << endl;    // false (0)

    
}