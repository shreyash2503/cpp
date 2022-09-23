#include <iostream>

using namespace std;

int partition(int a[],int s,int e)
{

    int i=s;
    int pivot = a[e];
    for(int j=s;j<=e-1;j++)
    {
        if(a[j]<pivot)
        {
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[i],a[e]);
    return i;
}


void QuickSort(int a[],int s ,int e)
{

    if(s>=e)
    {
        return;
    }
    int p = partition(a,s,e);
    QuickSort(a,s,p-1);
    QuickSort(a,p+1,e);

}

int main()
{
    int n;
    cout<<"Enter the size of the array you want to sort::";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {

        cout<<a[i]<<" ";
    }
}
