#include <iostream>
using namespace std;

class Fraction{
    int numerator;
    int denominator;
    int num;

public:

    Fraction()
    {

    }
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;//this->numerator is same as (*Fraction).numerator
    }

    void setNumerator(int n){
        numerator = n;
    }

    void setDenominator(int d)
    {
        denominator = d;
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    void print(){

        cout<<this->numerator<<"/"<<this->denominator<<endl;
    }
    Fraction add(Fraction const& f2){
        int lcm = this->denominator*f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = this->numerator*x+f2.numerator*y;
        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;

    }
    Fraction operator+(Fraction const& f2){
        int lcm = this->denominator*f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;

        int num = this->numerator*x+f2.numerator*y;
        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;

    }

    void subtract(Fraction const& f2)
    {
        int lcm = this->denominator*f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;
        this->numerator = this->numerator*x-f2.numerator*y;
        this->denominator = lcm;
        simplify();
    }
    Fraction operator-(Fraction const& f2)
    {
        int lcm = this->denominator*f2.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f2.denominator;
        int num = this->numerator*x-f2.numerator*y;
        Fraction f3(num,lcm);
        f3.simplify();
        return f3;
    }

    void divide(Fraction const& f2)
    {
        this->numerator=this->numerator*f2.denominator;
        this->denominator=this->denominator*f2.numerator;
        simplify();
    }

    Fraction operator*(Fraction const& f2) const
    {

        Fraction f1(this->numerator*f2.numerator,this->denominator*f2.denominator);
        f1.simplify();
        return f1;
    }

    void operator==(Fraction const& f2) const
    {
        if(this->numerator==f2.numerator && this->denominator==f2.denominator)
        {
            cout<<"Equal"<<endl;
        }
        else
        {
            cout<<"Not equal"<<endl;
        }
    }

    void simplify(){

        int gcd = 1;
        int j = min(this->numerator,this->denominator);
        for(int i=1;i<=j;i++){
            if(numerator%i==0 && denominator%i==0){
                gcd=i;
            }
        }

        numerator=numerator/gcd;
        denominator=denominator/gcd;

    }
    Fraction& operator++()
    {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction fnew(this->numerator,this->denominator);
        this->numerator = this->numerator+this->denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    Fraction operator+=(int i)
    {
        this->numerator = this->numerator+this->denominator*i;
        simplify();
        return *this;
    }
    Fraction& operator+=(Fraction const& f)
    {
        int lcm = this->denominator*f.denominator;
        int x = lcm/this->denominator;
        int y = lcm/f.denominator;

        this->numerator = this->numerator*x+f.numerator*y;
        this->denominator = lcm;
        return *this;
    }



};

int main()
{
//    Fraction f1(15,4);
//    Fraction f2(15,8);
//    f1.add(f2);
//    f1.print();
//    f2.print();
//    Fraction f3(20,13);
//    Fraction f4(15,16);
//    f3.divide(f4);
//    f3.print();
//    Fraction f5(14,23);
//    Fraction f6(19,20);
//    f5.subtract(f6);
//    f5.print();
//    Fraction const f3;
//    cout<<f3.getDenominator()<<" "<<f3.getNumerator();
//    f1.print();
//    Fraction f2=++(++f1);
//    f1.print();
//    f2.print();
//    Fraction f3(15,4);
//    Fraction f4 = f3++;
//    f3.print();
//    f4.print();
    Fraction f1(10,2);
    f1+=5;
    f1.print();
    Fraction f2(10,1);
    Fraction f3(20,1);
    (f2+=f3)+=f3;
    f2.print();




    return 0;
}
