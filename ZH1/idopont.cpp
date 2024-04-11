#include <iostream>


class Idopont{
    int ora;
    int perc;

    public:
        Idopont():ora(0), perc(0){}
        Idopont(int ora_a, int perc_a): ora(ora_a), perc(perc_a){}

        int oraget(){return ora;}

        //friend bool operator==(const Idopont& rhs, const Idopont& test ){} 

        void print(std::ostream& os)const{
            os<<ora<<":"<<perc<<std::endl;

        char operator[](size_t i ){
            if (i > this->ora)
            {
                throw "out of range";
            }
            return this->ora;
            
        }
    }


};




int main(){
    Idopont ido(12,10);
    Idopont ido2;
    
    //std::cout<<ido2.oraget();
    ido.print(std::cout);

}