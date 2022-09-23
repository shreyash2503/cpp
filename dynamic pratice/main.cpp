#include <iostream>

using namespace std;

class Dynamic
{
    int *data;
    int index;
    int capacity;
public:
    Dynamic()
    {
        this->data = new int[5];
        this->capacity=5;
        this->index=0;
    }

    Dynamic(Dynamic const& d)
    {
        this->data = new int[d.capacity];
        this->capacity = d.capacity;
        this->index = d.index;
        for(int i=0;i<d.index;i++)
        {
            this->data[i]=d.data[i];
        }

    }
    Dynamic operator=(Dynamic const&d)
    {
        this->capacity = d.capacity;
        this->index = d.index;
        this->data = new int[d.capacity];
        for(int i=0;i<d.index;i++)
        {
            this->data[i] = d.data[i];
        }
    }

    void add(int a)
    {
        if(index==capacity)
        {
            int *newData=new int[capacity*2];
            for(int i=0;i<this->capacity;i++)
            {
                newData[i]=data[i];
            }
           delete []data;
           data = newData;
           capacity*=2;

        }
        data[index]=a;
        index++;
    }

    void print()
    {
        for(int i=0;i<this->index;i++)
        {
            cout<<data[i]<<endl;
        }
    }



};

int main()
{
    Dynamic d1;
    d1.add(5);
    d1.add(10);
    d1.add(15);
    d1.add(30);
    d1.add(100);
    d1.print();
}
