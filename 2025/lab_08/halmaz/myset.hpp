#ifndef MYSET_HPP
#define MYSET_HPP



#ifndef CPORTA
#define ELKESZULT 3
#endif



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
    T Array[s];
    size_t kapacitas;
public: 
    Set():kapacitas(0){}
    int size()const{
        return kapacitas;
    }
    bool isElement(T elem)const{
        for(size_t i = 0; i < kapacitas; i++){
            if(equal(Array[i], elem)){
                return true;
            }
        }
        return false;
    }
    void insert(T elem){
        if (isElement(elem))
        {
            return;
        }

        if (kapacitas == s)
        {
            throw "F9ILEX";
        }
        
        Array[kapacitas] = elem;
        kapacitas++;
        
    }
    virtual ~Set(){}
};





#endif
