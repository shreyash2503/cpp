# include <bits/stdc++.h>
using namespace std;

template <typename T>
class dynamicArray{
    T* data;
    int size;
    int capacity;
public:
    // ! Contructor definitions
    dynamicArray() // -> Non parameterized Constructor
    {
        this->data = new T[5];
        this->size = 0;
        this->capacity = 5;

    }

    dynamciArray(int customSize) // -> Parameterized Constructo
    {
        this->data = new T[customSize];
        this->size = 0;
        this->capacity = customSize;
    }

    // ! Functions 
    void push_back(T data)
    {
        if(size == capacity)
        {
            T* newData = new T[capacity*2];
            for(int i=0;i<size;i++)
            {
                newData[i] = this->data[i];
            }
            delete []this->data;
            this->data = newData;
            this->capacity = capacity*2;
        }

        this->data[size]  = data;
        size++;
    }


    void getCapacity()
    {
        cout<<"The capacity of the array currently is ::"<<this->capacity<<endl;
    }


    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout<<this->data[i]<<endl;
        }
    }
};


int main()
{
    dynamicArray<int> vector;
    for(int i=0;i<1000;i++;)
    {
        vector.push_back(i);
    }
    vector.print();
    vector.getCapacity();
    return 0;


}