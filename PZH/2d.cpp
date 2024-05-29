#include <vector>
#include <iostream>

template <typename T, int A, int B>
class KetD
{

    std::vector<std::vector<T>> matrix;

public:
    KetD()
    {
        matrix = std::vector<std::vector<T>>(A, std::vector<T>(B, 0));
    }

    KetD(T a)
    {
        matrix = std::vector<std::vector<T>>(A, std::vector<T>(B, a));
    }

    void kiir()
    {
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < B; j++)
            {
                std::cout << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }

    void csere(int sor, int oszlop, T csere)
    {
        if (sor <= A && oszlop <= B)
        {
            matrix[sor].insert(matrix[sor].begin() + oszlop, csere);
        }
    }

    void van_benne(T mit_keres)
    {
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < B; i++)
            {
                if (matrix[i][j] == mit_keres)
                {
                    std::cout << "Megvan a keresett elem!" << std::endl;
                    return;
                }
            }
        }
        std::cout << "nincs benne" << std::endl;
    }

    void torol(int sor, int oszlop)
    {
        matrix[sor].erase((matrix[sor].begin() + oszlop));
    }
};

int main()
{
    KetD<int, 3, 4> tomb;
    KetD<char, 5, 5> tomb2('q');

    tomb2.csere(0, 0, 'z');

    // tomb.kiir();
    tomb2.kiir();
    std::cout << std::endl;

    // tomb2.van_benne('z');
    tomb2.torol(0, 0);
    tomb2.kiir();

    return 0;
}