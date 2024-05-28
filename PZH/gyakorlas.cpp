#include <vector>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void ki(const T& mat){

    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout<<endl;
    }
}



template <typename T>
void kiir(const T& list){
    for (auto i = list.begin(); i!= list.end(); i++)
    {
        cout<< *i <<" ";
    }

}

bool keres(const std::vector<int> lista, int mit){
    for(int i = 0; i < lista.size(); i++){
            if (mit == lista[i])
            {
                return true;
            }
            
    }
    return false;
}




int main(){
         

    std::vector <std::vector<int>    > d2(5, std::vector<int>(10, 3));

    //ki(d2);
    cout<<endl;
    cout<<endl;

    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);

    kiir(nums);
    keres(nums, 3);
    



    



    return 0;
}