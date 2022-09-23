#include <iostream>
using namespace std;

class Dynamic
{
    int *data;
    int capacity;
    int index;
    public:
    Dynamic()
    {
        data = new int[5];
        capacity=5;
        index=0;

    }
    //parameterized copy constructor
    Dynamic(int c)
    {
        this->capacity = c;
    }
    // your copy constructor
    Dynamic(Dynamic const& d)
    {
        this->capacity = d.capacity;
        this->index = d.index;
        this->data = new int[d.capacity];
        for(int i=0;i<d.index;i++)
        {
            data[i]=d.data[i];
        }
    }
    //your own copy assignment operator
    Dynamic operator=(Dynamic const& d)
    {
       this->capacity = d.capacity;
       this->index = d.index;
       this->data = new int[d.capacity];
       for(int i=0;i<d.index;i++)
       {
           data[i]=d.data[i];
       }
    }
    void add(int i)
    {
        if(capacity==index)
        {
           int *newData=new int[capacity*2];
            for(int j = 0;j<index;j++)
            {
                newData[j]=data[j];
            }
            delete []data;
           data = newData;
           capacity = capacity*2;

        }
        data[index] = i;
        index++;
    }

    int add(int i, int index)
    {
        if(index<this->index)
        {
            data[index]=i;
        }
        else if(index==this->index)
        {
            add(i);
        }
        else
        {
            return -1;
        }
    }
    int get(int index) const
    {
        if(index>=0 && index<this->index)
        {
            return data[index];
        }
        else
        {
            return -1;
        }
    }
    void print() const
    {
        for(int i=0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }

    void getCapacity()
    {
        cout<<capacity<<endl;
    }

};

int main()
{
    Dynamic d1;
    d1.add(10);
    d1.add(11);
    d1.add(12);
    d1.add(23);
    d1.add(90);
    d1.add(45);
    d1.print();
    Dynamic d2;
    d2=d1;
    d2.add(100,0);
    d2.print();
    d1.print();

}

