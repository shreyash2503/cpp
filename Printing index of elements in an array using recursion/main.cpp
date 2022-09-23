#include <bits/stdc++.h>

using namespace std;

void printIndex(int a[], int n, int key)
{
    if(n==-1)
    {
        return;
    }
    printIndex(a,n-1,key);
    if(a[n]==key)
    {
        cout<<n<<endl;
    }
}

int main()
{
   int n,key;
   cout<<"Enter the size of the array::";
   cin>>n;
    int a[n];
    cout<<"Enter the key whose indexes you want to find in the array::";
    cin>>key;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    printIndex(a,n,key);
}
