/**
 * \file: clonable_hetero_store.hpp
 *
 */

#ifndef CLONABLE_HETERO_STORE_HPP
#define CLONABLE_HETERO_STORE_HPP


template <class Base, class Container = std::vector<Base *>, class Exception = std::out_of_range>
class ClonableHeteroStore{          // ClonableHeteroStore osztály template-je
    Container container;
public:
    typedef Base value_type;         // value_type typedef
    typedef typename Container::const_iterator const_iterator;      // const_iterator typedef a Container típusból
    typedef typename Container::iterator iterator;          // iterator typedef a Container típusból

    ClonableHeteroStore() : container(Container()){}        // ClonableHeteroStore konstruktor

    void copy(ClonableHeteroStore const& c){            // copy függvény
        container.clear();
        for (const_iterator existingchs = c.container.begin() ; existingchs != c.container.end(); existingchs++) {
            this->container.push_back((*existingchs)->clone());
        }
    }

    ClonableHeteroStore(ClonableHeteroStore const& c) : container(c.container){     // ClonableHeteroStore copy konstruktor
        copy(c);
    }

    ClonableHeteroStore& operator=(ClonableHeteroStore const& c){       // ClonableHeteroStore értékadó operátor
        if(this == &c){
            return *this;
        }
        this->container = c.container;
        copy(c);
        return *this;
    }
    const_iterator begin() {            // első elem iterator függvény
        return container.begin();
    }
    const_iterator end() {          // utolsó elem iterator függvény
        return container.end();
    }
    void add(Base * a){         // hozzado függvény
        try{
            container.push_back(a);
        }catch (...){
            delete a;
            throw Exception("túlindexelés");
        }
    }
    void clear(){           // clear függvény
        for (iterator i = container.begin(); i != container.end(); i++) {
            delete *i;
        }
        container.clear();
    }
    size_t size() const {       // size függvény
        return container.size();
    }
    ~ClonableHeteroStore(){     // ClonableHeteroStore destruktor
        for (iterator i = container.begin(); i != container.end(); i++) {
            delete *i;
        }
    }





};
#endif // CLONABLE_HETERO_STORE_HPP
