#include <iostream>

using namespace std;
bool isSorted(int a[],int n)
{
    if(n==1 || n==0)
    {
        return true;
    }
    if(a[0]>a[1])
    {
        return false;
    }
    bool sorted = isSorted(a+1,n-1);
    if(sorted)
    {
        return true;
    }
    else{
        return false;
    }
}
bool isSorted2(int a[],int n)
{
    if(n==1 or n==0)
    {
        return true;
    }
    if(a[n-2]>a[n-1])
    {
        return false;
    }
    bool sorted = isSorted(a,n-1);
    if(sorted){
        return true;
    }
    else{
        return false;
    }
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
    cout<<isSorted(a,n)<<endl;
    cout<<isSorted2(a,n);
}
