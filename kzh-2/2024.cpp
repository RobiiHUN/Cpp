#include <iostream>


class DinIntArray{
    int *pData;
    int len;
public:
    void printDbg()const{
        for (size_t i = 0; i <len; i++)
        {
            std::cout << pData[i] << std::endl;
        }
        
    };
    DinIntArray(): pData(NULL), len(0){};
    int size()const{return len;};
    DinIntArray(const int* arr, int len): pData(const_cast<int*>(arr)), len(len) {};
    DinIntArray(const DinIntArray& arr){
        pData = new int[arr.size()];

        for (size_t i = 0; i < arr.size(); i++)
        {
            pData[i] = arr.pData[i];
        }
        len = arr.size();
    }
    DinIntArray& operator=(const DinIntArray& arr);
    void push_back(int k){
        int *nData = new int[len + 1];
        for (size_t i = 0; i < len; i++)
        {
            nData[i]  = pData[i];
        }
        nData[len] = k;
        len++;
        delete[] pData;
        pData = nData;
        
    };
    void push_front(int k){
        int *nData = new int[len + 1];
        for (size_t i = 1; i < len + 1; i++)
        {
            nData[i]  = pData[i - 1];
        }
        nData[0] = k;
        len++;
        delete[] pData;
        pData = nData;
    };
    int pop_back(){
        int *nData = new int[len - 1];
        for (size_t i = 0; i < len - 1; i++)
        {
            nData[i]  = pData[i];
        }
        int temp = pData[len];
        nData[len] = pData[len - 1]; 
        len--;
        delete[] pData;
        pData = nData;
        return temp;
        
    }
    int pop_front(){
        int *nData = new int[len - 1];
        for (size_t i = 1; i < len; i++)
        {
            nData[i - 1]  = pData[i];
        }
        int temp = pData[0];
        len--;
        delete[] pData;
        pData = nData;
        return temp;
    }

    
    int& operator[](int idx)const{
        for (size_t i = 0; i < len; i++)
        {
            if (i == idx)
            {
                return pData[i];
            }
            
        }
        return pData[0];
    };
    ~DinIntArray(){};

};

int main(){
  // csak a teszteles miatt vannak itt

    int arr[] = {1,2,5};
    DinIntArray dinnar(arr,3);
    //std::cout << dinnar.size() << std::endl;
    //dinnar.printDbg();
    //DinIntArray test(dinnar);
   // test.printDbg();
   // std::cout << test.size() << std::endl;
   dinnar.push_back(3);
   std::cout << dinnar[2] << std::endl;



    return 0;
}