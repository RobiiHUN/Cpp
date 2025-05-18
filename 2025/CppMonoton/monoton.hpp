#ifndef MONOTON_HPP
#define MONOTON_HPP

#include <iterator>

template <typename Iterator, typename Pred>
bool monoton(Iterator first, Iterator last, Pred pred) {
    if (first == last) return true; //megnezzuk, hatha ures az intervallum
    for (Iterator prev = first++; first != last; ++first) {
        if (!pred(*first, *prev)) { // Lefuttatjuk a pred fgv-t
            return false;
        }
        prev = first;
    }
    return true;
}
// azert kell a first++, hogy mindig a prev elott jarjon egyel


#endif