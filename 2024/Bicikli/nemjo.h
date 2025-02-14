class Bicikli : public Jarmu{
    Kerek elso;
    Kerek hatso;
public:
    Bicikli(double v, int d) : Jarmu(v), elso(d), hatso(d) {
        std::cout<<"\tBicikli ctor ";
        elso.kiir();
    }
    Bicikli(const Bicikli& rhs) : Jarmu(rhs), elso(rhs.elso), hatso(rhs.hatso) {
        std::cout<<"\tBicikli copy ";
    }

    ~Bicikli(){
        std::cout<<"\tBicikli dtor ";
        elso.kiir();
    };
};