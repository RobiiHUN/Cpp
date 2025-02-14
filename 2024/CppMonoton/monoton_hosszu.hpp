#ifndef _MONOTON_HPP_
#define _MONOTON_HPP_

template<typename I, typename P>
bool monoton(I first, I last, P pred) {
    if (first == last) return true;
    I next = first++;
    while (first != last) {
        if (!pred(*first, *next)) return false;
        next = first++;
    }
    return true;
}
#endif