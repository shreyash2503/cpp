#include <iostream>

using namespace std;
int count=0;
int numberOfDigits(float n)
{

    if(n<1){
        return count;
    }
    n=n/10;
    cout<<n<<endl;
    count = count+1;
    numberOfDigits(n);
}

int main()
{
    float n;
    cin>>n;
    cout<<numberOfDigits(n);
}
