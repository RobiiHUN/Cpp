#ifndef _MONOTON_HPP_
#define _MONOTON_HPP_

template<typename I, typename P>
bool monoton(I first, I last, P pred) {
    return std::adjacent_find(first, last, std::not_fn(pred)) == last;
}
#endif