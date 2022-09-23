#include <iostream>

using namespace std;
void mergeArray(int a[],int x[],int y[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    while(i<=mid && j<=e)
    {
        if(x[i]>y[j])
        {
            a[k]=y[j];
            j++;
            k++;
        }
        else
        {
            a[k]=x[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        a[k]=x[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        a[k]=y[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int s,int e)
{

    if(s==e)
    {
        return;
    }
    int mid = (s+e)/2;
    int x[100],y[100];
    for(int i=0;i<=mid;i++)
    {
        x[i]=a[i];
    }
    for(int i=mid+1;i<=e;i++)
    {
        y[i]=a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArray(a,x,y,s,e);

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
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
