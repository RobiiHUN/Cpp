#include <iostream>


template <typename T, int N>
class Tarolo{
    T* elemek[N];
    int db;
public:

    Tarolo():db(0){
        for(size_t i = 0; i < N; i++){
            elemek[i] = nullptr;
        }
    }
    ~Tarolo(){
        for(size_t i = 0; i < N; i++){
            delete[] elemek[i];
        }
    }

    void hozzaad(T* elem){
        if(db >= N) throw "tele van";
        db++;
        elemek[db] = elem;
    }

       // Listázás
       void listaz(std::ostream& os) const {
        for (int i = 0; i < db; ++i)
            if (elemek[i])
                elemek[i]->print(os);
    }

};


struct Ember {
    std::string nev;
    Ember(std::string n) : nev(n) {}
    void print(std::ostream& os) const {
        os << "Nev: " << nev << std::endl;
    }
};

int main() {
    Tarolo<Ember, 3> t;
    t.hozzaad(new Ember("Aladár"));
    t.hozzaad(new Ember("Béla"));
    t.listaz(std::cout);
}