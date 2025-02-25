/**
 * \file: clonable_hetero_store.hpp
 *
 */

#ifndef CLONABLE_HETERO_STORE_HPP
#define CLONABLE_HETERO_STORE_HPP


//#error "itt készítse el a ClonableHeteroStore sablont"

template <typename Base, typename Container = std::vector<Base*>, typename Exception = std::out_of_range>
class ClonableHeteroStore {
    Container container;
public:
    typedef typename Container::value_type value_type;
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    ClonableHeteroStore(){}
    ~ClonableHeteroStore() { clear(); }

    const_iterator begin() const { return container.begin(); }
    const_iterator end() const { return container.end(); }

    size_t size() const { return container.size(); }

    void clear(){
        for (iterator it = container.begin(); it != container.end(); it++)
            delete *it;
        container.clear();
    }

    void add(Base* p){
        try
        {
            container.push_back(p);
        }
        catch(const std::exception& e)
        {
            delete p;
            throw Exception("");
        }
        
    }

    ClonableHeteroStore(const ClonableHeteroStore& other) {
        for (typename Container::const_iterator it = other.container.begin(); it != other.container.end(); ++it) {
            container.push_back((*it)->clone());
        }
    }
    ClonableHeteroStore& operator=(const ClonableHeteroStore& other) {
        if (this != &other) {
            clear();
            for (typename Container::const_iterator it = other.container.begin(); it != other.container.end(); ++it) {
                container.push_back((*it)->clone());
            }
        }
        return *this;
    }

    
    
};

#endif // CLONABLE_HETERO_STORE_HPP
