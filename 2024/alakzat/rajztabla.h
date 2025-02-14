#ifndef RAJZTABLA_H
#define RAJZTABLA_H

#include "alakzat.h"


class Rajztabla{
    Alakzat* alakzatok[100];
    size_t db;
    Rajztabla(const Rajztabla& r);
    Rajztabla& operator=(const Rajztabla& r);
    public:

        Rajztabla():db(0){}
        size_t size() const {return db;};
        void felrak(Alakzat *a){alakzatok[db++] = a;} 

        void rajzol()const{         //+
            for (size_t i = 0; i < db; i++)
            {
                alakzatok[i]->rajzol();
            }
            
        };

        void mozgat(const Pont& p)const{    //+
            for (size_t i = 0; i < db; i++)
            {
                alakzatok[i]->mozgat(p);
            }
            
        }

        void torol(){
            for (size_t i = 0; i < db; i++)
            {
                if (alakzatok[i] != nullptr)delete alakzatok[i];
            }
            db = 0; //beallitjuk alaphelyzetre
            
        }

        /* Rajztabla& operator=(const Rajztabla& r){
            torol();
            db = r.db;
            for (size_t i = 0; i < db; i++)
            {
                alakzatok[i] = r.alakzatok[i] -> clone();
            }
            return (*this);
        } */

         virtual ~Rajztabla(){torol();} //+
        

};

std::ostream& operator<<(std::ostream& os, const Rajztabla& r);

#endif  

