#include <iostream>

class DinIntArray{
    int *pData;
    size_t len;
public:
    void printDbg()const{
        if (len == 0) return;
        for (size_t i = 0; i < len; i++){
            std::cout << pData[i] << std::endl;
        }
    }
    DinIntArray():pData(NULL), len(0){}
    size_t size()const{
        return len;
    }
    DinIntArray(const int* arr, size_t hossz){
        len = hossz;
        pData = new int[hossz];
        for (size_t i = 0; i < len; i++)
        {
            pData[i] = arr[i];
        }
    }
    DinIntArray& operator=(const DinIntArray& arr){
        if (this == &arr)
        {
            return *this;
        }
        

        len = arr.len;
        delete[] pData;
        pData = new int[len];
        for (size_t i = 0; i < len; i++)
        {
            pData[i] = arr.pData[i];
        }
        return *this;
    }

    void push_back(int k){
        int* tmp = new int[len + 1];
        for (size_t i = 0; i < len; i++)
        {
            tmp[i] = pData[i];
        }
        tmp[len] = k;
        delete[] pData;
        pData = tmp;
        len++;
    }

    void push_front(int k){
        int* tmp = new int[len + 1];
        tmp[0] = k;
        for (size_t i = 0; i < len; i++)
        {
            tmp[i + 1] = pData[i];
        }
        delete[] pData;
        pData = tmp;
        len++;
    }

    int& operator[](size_t idx)const{
        if (idx > len)
        {
            std::cout << "tulindexelt" << std::endl;
        }

        return pData[idx];
    }
    ~DinIntArray(){
        delete[] pData;
    }
};

