#include <iostream>

using namespace std;
int NoofTimes(int a[],int n,int key)
{
    if(n==-1)
    {
        return 0;
    }
    if(a[n]==key)
    {
        return 1+NoofTimes(a,n-1,key);
    }
    else
    {
        return NoofTimes(a,n-1,key);
    }

}

int main()
{
   int n,key;
   cout<<"Enter the size of the array::";
   cin>>n;
   int a[n];
   cout<<"Enter the key you want to find";
   cin>>key;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   cout<<NoofTimes(a,n,key);
}
