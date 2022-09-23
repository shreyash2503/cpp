#include <iostream>

using namespace std;
int sumOfDigits(int n)
{
    if(n<1){
        return 0;
    }
    return (n%10)+sumOfDigits(n/10);
}

int main()
{
   int n;
   cout<<"Enter the number whose sum of the digits you want to find:: ";
   cin>>n;
   cout<<sumOfDigits(n);


}
