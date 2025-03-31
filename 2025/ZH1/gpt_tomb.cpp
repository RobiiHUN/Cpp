#include <iostream>

template <typename T>
T minimum(const T a, const T b){
    if(a < b)return a;
    return b;
}
int main(){
    using namespace std;
    cout << minimum(5, 8) << endl;          // 5
    cout << minimum(3.14, 2.71) << endl;    // 2.71
    cout << minimum('a', 'z') << endl;      // a

};
