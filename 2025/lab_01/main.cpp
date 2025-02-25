#include <iostream>
#include "gtest_lite.h"
 
int abs_osszeg(const int* ptr, size_t m) {
    if (ptr == nullptr)
        return 0;
    int ossz = 0;
    for(size_t i = 0; i < m; i++) {
        if(ptr[i] > 0)
            ossz += ptr[i];
        else
            ossz += -1 * ptr[i];
    }
    return ossz;
}
 
int main()
{

    
    TEST(osszeg, csak_pozitiv) { // Teszt eset kezdete. A paraméterekből csak kiírás lesz
        int t[] = { 2, 4, 1, 9 };
        int res = abs_osszeg(t, 4);
        EXPECT_EQ(16, res);      // a két paraméter azonosságát várjuk
    } END

    TEST(osszeg, csak_negativ) {
        int t[] = { -2, -4, -1, -9 };
        int res = abs_osszeg(t, 4);
        EXPECT_EQ(16, res);
    } END

    TEST(osszeg, nullptr) {
        int res = abs_osszeg(nullptr, 0);
        EXPECT_EQ(0, res);
    } END
    return 0;
}