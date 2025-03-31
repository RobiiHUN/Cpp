#include <iostream>

class DinTomb{
    int* data;
    int kapacitas;
    int db;
public:
    DinTomb():kapacitas(10), db(0){
        data = new int[kapacitas];
    }
    DinTomb(const DinTomb& masik){
        kapacitas = masik.kapacitas;
        db = masik.db;
        data = new int[kapacitas + 1];
        for (size_t i = 0; i < db; i++)
        {
            data[i] = masik.data[i];
        }
    }
    DinTomb& operator=(const DinTomb& masik){
        if (this != &masik) return *this;

        delete[] data;
        kapacitas = masik.kapacitas;
        db = masik.db;
        data = new int[kapacitas];
        for (size_t i = 0; i < db; i++)
        {
            data[i] = masik.data[i];
        }
        return *this;
    }

    ~DinTomb(){
        kapacitas = 0;
        db = 0;
        delete[] data;

    }

    void hozzaad(const int a){
        if (db >= kapacitas)
        {
            int* uj = new int[kapacitas*2];
            for(size_t i = 0; i < db; i++){
                uj[i] = data[i];
            }
            delete[] data;
            data = uj;
            kapacitas *= 2;
            
        }
        data[db++] = a;
    }

    int& operator[](int a){
        if(a > db) throw "nagy az idx";

        return data[db];
    }

    int meret()const{
        return db;
    }

    void kiir(std::ostream& os)const{
        for (size_t i = 0; i < db; i++)
        {
            os << data[i] << " ";
        }
        std::cout<<std::endl;
        
    }

    
};


int main() {
    DinTomb tomb;
    for (int i = 0; i < 20; ++i)
        tomb.hozzaad(i * i);

    tomb.kiir(std::cout); // 0 1 4 9 16 ... 361

    DinTomb masolat = tomb;
    masolat.hozzaad(999);

    std::cout << "Eredeti:" << std::endl;
    tomb.kiir(std::cout);

    std::cout << "Masolat:" << std::endl;
    masolat.kiir(std::cout);

    return 0;
}