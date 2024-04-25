#ifndef MYSET_HPP
#define MYSET_HPP


template <typename T>
class Set{
    private:
        T* elements;
        size_t capacity;

    public:
        Set():capacity(10){
            elements = new T[capacity];
        }
        size_t size() const{
            return capacity;
        }
        void insert(const T& elem){
            
            for(int i = 0; i < capacity; i++){
                if(elements[i] == elem){
                    return;
                }
            }
            elements[capacity] = elem;
            capacity++;
        }
        bool isElement(const T& elem) const{
            for(int i = 0; i < capacity; i++){
                if(elements[i] == elem){
                    return true;
                }
            }
            return false;
        }







};
#endif
