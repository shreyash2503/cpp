#include <iostream>

using namespace std;
class A
{
    int i,j;
public:
    void set(int i , int j)
    {
        this->i=i;
        this->j=j;
    }
    void show()
    {
        cout<<i<<" "<<j<<endl;
    }
};

class B:public A
{
    int k;
public:
    B(int k)
    {
        this->k=k;
    }
    void showk()
    {
        cout<<k<<endl;
    }
};

int main()
{
    B f1(3);
    f1.set(3,4);
    f1.show();
    f1.showk();

}
