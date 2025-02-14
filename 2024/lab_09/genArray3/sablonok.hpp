

#define ELKESZULT 7

#include <iostream>

template<typename Iterator>
void printEach(Iterator begin, Iterator end, std::ostream& os = std::cout, const char* separator = ", ") {
    while (true)
    {
        os << *begin;
        if (++begin == end)
        {
            os<<std::endl;
            break;
        }else{
            os << separator;
        }
        
    }
    
    
}

template<typename Iterator>
int szamol_ha_negativ(Iterator begin, Iterator end) {
    int db = 0;
    while (begin != end)
    {
        if (*begin < 0)
        {
            db++;
        }
        begin++;
    }
    return db;
}

template<typename T>
class nagyobb_mint {
    T ertek;
public:
    nagyobb_mint(T ertek) : ertek(ertek) {}
    bool operator()(T ertek2) {
        return ertek2 > ertek;
    }
};

template <typename Iterator, typename Predicate>
int szamol_ha(Iterator begin, Iterator end, Predicate p) {
    int db = 0;
    while (begin != end)
    {
        if (p(*begin))
        {
            db++;
        }
        begin++;
    }
    return db;
}


/// Függvénysablon, ami kiírja egy generikus tömb adatait
/// Feltételezzük, hogy a generikus tömbnek van: 
///   - ForwardIteratora, size(), valamint capacity() tagfüggvénye
/// @param T   - sablon paraméter: iterátoros tömb típus
/// @param txt - kiírandó szöveg
/// @param arr - konkrét tömb
/// @param os  - output steram 
template <class T>
void PrintArray(const char *txt, const T& arr, std::ostream& os = std::cout) {
    os << txt << " size=" << arr.size()
         << " capacity=" << arr.capacity() << std::endl;
    os << "\t data=";
    // kiírjuk az adatokat
     
}
