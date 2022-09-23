#include <iostream>

using namespace std;

int towerOfHanoi(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    return towerOfHanoi(n-1)+1+towerOfHanoi(n-1);
}
int main()
{
    int n;
    cout<<"Enter the no of disks in tower of hanoi::";
    cin>>n;
    cout<<towerOfHanoi(n);
}
