#include <iostream>

using namespace std;

int sumOfArray(int a[],int n)
{
    if(n==-1)
    {
        return 0;
    }
    return a[n]+sumOfArray(a,n-1);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<sumOfArray(a,n)<<endl;
}
