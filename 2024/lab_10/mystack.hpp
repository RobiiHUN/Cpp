#ifndef MYSTACK_HPP
#define MYSTACK_HPP


/**
 * \file: mystack.hpp
 *
 */
//#error "itt keszitse el a stack adaptert!"


#include <vector>
#include <stdexcept>

template <typename T, typename Container = std::vector<T>>
class MyStack {
    Container data;
    size_t max_size;
public:

    MyStack(): data(), max_size(0) {}

    
    T& top() {
        if(empty()){
            throw std::out_of_range("MyStack::top(): ures");
        }
        return data.at(max_size - 1);
    }


    ~MyStack() {}

    void push(const T& val){
        data.at(max_size++) = val;
    }

    
    void pop(){
        if(empty()){
            throw std::out_of_range("MyStack::pop(): ures");
        }
        --max_size;
    }


    bool empty() const {
        return data.empty();
    }

};


#endif // MYSTACK_HPP