/**
 * \file vektor.hpp
 *
 * Előadáson bemutatott generikus tömbből Vektort készítünk.
 *
 */
#ifndef GEN_VEKTOR
#define GEN_VEKTOR

#include "gen_array_iter3.hpp"

template<typename T, size_t maxsiz = 6>
class Vektor : public Array<T, maxsiz> {
public:
    /// minden tagfüggvény jó, nem kell átdefiniálni
    /// csak a konstruktorokat kell megfelelően paraméterezve továbbhívni

	/// default és konstans értékkel feltöltő konstruktor
	/// @param n - méret
	/// @param value - érték, amivel feltölt
	explicit Vektor(size_t n = 0, const T& value = T())
        : Array<T, maxsiz>(n, value) {}      // alaposztály konstruktora

/// ----------------------------------------------------
/// A további tagfüggvényeket Önnek kell megvalósítani
///-----------------------------------------------------
    /// konstruktor sorozatból
    /// @param first - sorozat elejére mutat
    /// @param last - utolsó elem után
    template <class InputIterator>
    Vektor(InputIterator first, InputIterator last){
        for(InputIterator it = first; it != last; ++it){
            push_back(*it);
        }
    }

    /// push_back
    /// vektor végéhez adatot ad
    /// @param val - adat
    void push_back(const T& val){
        
        Array<T, maxsiz>::setsize(Array<T, maxsiz>::size() + 1);

        Array<T, maxsiz>::at(Array<T, maxsiz>::size() - 1) = val;
        
    }

    /// back
    /// vektor utolsó adatának elérése
    /// @return referencia az utolsó adat
    T& back(){
        return Array<T, maxsiz>::at(Array<T, maxsiz>::size() - 1);
    }

    /// pop_back
    /// vektor utolsó adatának eldobása
    void pop_back(){
        Array<T, maxsiz>::setsize(Array<T, maxsiz>::size() - 1);
    }

    /// empty
    /// @return true, ha nincs adat
    bool empty() const{
        return this->size() == 0;
    }

    /// A továbbiakban egyszerűbben hivatkozhassunk az iterator-ra, mint típusra
    typedef typename Array<T, maxsiz>::iterator iterator;

    /// törli az adott pozíción levő elemet
    /// @param pos - a törlendő elemre mutató iterátor
	/// @return az első nem törölt elemre mutató iterátor, ha végéig törölt, akkor end()
    iterator erase(iterator pos){
        iterator it = pos;
        for(iterator it2 = pos + 1; it2 != this->end(); ++it2){
            *it = *it2;
            ++it;
        }
        this->resize(this->size() - 1);
        return it;
    }

    /// törli az adott intervallumba eső elemeket
    /// @param first - a törlendő intervalum eleje
    /// @param last - a törlendő intervallum vége
	/// @return az első nem törölt elemre mutató iterátor, ha végéig törölt, akkor end()
    iterator erase(iterator first, iterator last){
        iterator it = first;
        for(iterator it2 = last; it2 != this->end(); ++it2){
            *it = *it2;
            ++it;
        }
        this->resize(this->size() - (last - first));
        return it;
    }

    
  

 }; // Vektor sablon vége

#endif
