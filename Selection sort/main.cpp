#include <iostream>

using namespace std;

void Selectionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int smallest = i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[smallest])
            {
                smallest=j;
            }
        }
        swap(a[i],a[smallest]);
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
    Selectionsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}



