#include <iostream>

using namespace std;
int lasttIndex(int a[],int n, int key)
{
    if(a[n]==key)
    {
        return n;
    }
    if(n==-1)
    {
        return -1;
    }
    return lasttIndex(a,n-1,key);

}
int firstIndex(int a[],int n,int key,int i)
{
    if(a[i]==key)
    {
        return i;
    }
    if(i==n)
    {
        return -1;
    }
    return firstIndex(a,n,key,i+1);
}
int lasttIndex2(int a[],int n,int key,int i)
{
    if(i==n)
    {
        return -1;

    }
    int indexInRem = lasttIndex2(a,n,key,i+1);
    if(indexInRem==-1)
    {
        if(a[i]==key)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
    else{
        return indexInRem;
    }
}


int main()
{
    int n,key;
    cout<<"Enter the size of the array::";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element whose first and last occurence you want to find:: ";
    cin>>key;
    cout<<lasttIndex(a,n,key)<<endl;
    cout<<firstIndex(a,n,key,0)<<endl;
    cout<<lasttIndex2(a,n,key,0);
}
