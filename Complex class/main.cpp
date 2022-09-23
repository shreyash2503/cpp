#include <iostream>

using namespace std;

class complex
{
    int real;
    int imaginary;

public:
    complex(int real,int imaginary)
    {
        this->real=real;
        this->imaginary=imaginary;
    }

    void print()
    {
        cout<<this->real<<"+"<<this->imaginary<<"i"<<endl;
    }

    void add(complex const& c1)
    {
        this->real=this->real+c1.real;
        this->imaginary=this->imaginary+c1.imaginary;
    }

    void multiply(complex const& c1)
    {
        this->real=(this->real*c1.real)-(this->imaginary*c1.imaginary);
        this->imaginary=(this->real*c1.imaginary)+(this->imaginary*c1.real);
    }
};

int main()
{
    complex c1(5,-2);
    complex c2(-5,7);
    c1.add(c2);
    c1.print();
    complex c3(1,1);
    complex c4(-3,4);
    c3.multiply(c4);
    c3.print();
}
