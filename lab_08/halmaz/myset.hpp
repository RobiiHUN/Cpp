#ifndef MYSET_HPP
#define MYSET_HPP

#define ELKESZULT 3


template <typename T>

bool equal(const T& a, const T& b){
    return a == b;
}

template<>
bool equal <Point>(const Point& a, const Point& b){
    return a.getX() == b.getX() && a.getY() == b.getY();
}


template <typename T, size_t s = 10>

class Set{
    private:
        T array[s];
        size_t capacity;

    public:
        Set():capacity(0){}
        virtual ~Set(){}
        size_t size() const{
            return capacity;
        }
        void insert(const T& elem){
                if (capacity == s)
                {
                    throw"Ez tele van mar";
                }
                else if (!isElement(elem))
                {
                    array[capacity] = elem;
                    capacity++;
                }

        }

        bool isElement(T elem){
            for(size_t i = 0; i < capacity; i++){
                if(equal(array[i], elem)){
                    return true;
                }
            }
            return false;
        }









};
bool operator==(const Point& p, const Point& q){
            return p.getX() == q.getX() && p.getY() == q.getY();
        }
#endif
