#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int n,int key)
{
    int s=0,e=n-1;
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }

    }
    return -1;
}

int main()
{
   int n;
   cin>>n;
   int a[n];
   int key;
   cout<<"Enter key:: ";
   cin>>key;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   sort(a,a+n);
   int pos=binarySearch(a,n,key);
   if(pos>0){
    cout<<"Your entered key was found at "<<pos<<endl;
   }
   else
   {
       cout<<"The key entered by the user is not present"<<endl;
   }

}
