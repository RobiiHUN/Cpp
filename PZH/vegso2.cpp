#include <iostream>
#include <vector>

class Diak {
        std::string nev;
        double atlag;
public:
        Diak(const std::string& n = "", double a = 0);
        double getAtlag() const;
        std::string getNev() const;
        void setAtlag(double a);
        void setNev(const std::string& n);
        virtual ~Diak();
};

struct Serializable {
        virtual void write(std::ostream& os) const = 0;
        virtual void read(std::istream& is) = 0;
        virtual ~Serializable() {}
};

struct PDiak: public Diak, public Serializable{
    PDiak(const std::string& n ="", double a = 0): Diak(n,a){}
    void write(std::ostream& os){
        os << "PDiak" << std::endl;
        os << getNev() << std::endl;
    }
    void read(std::ostream& is){
        std::string sor;
        (is >> sor).ignore(1);

        if(sor != "PDiak") throw "out of range";
        getline(is, sor);
        setNev(sor);
        double a;
        (is >> a).ignore(1);
        setAtlag(a);



    }
};