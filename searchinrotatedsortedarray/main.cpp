#include <iostream>
using namespace std;

int searchInArray(int a[],int n, int key)
{
  int s=0;
  int e=n;
  while(s<=e)
  {
    int mid=(s+e)/2;
    if(a[mid]==key)
    {
      return mid;
    }
    if(a[mid]<a[e])
    {
      if(a[mid]>key && key<a[e])
      {
        e=mid-1;
      }
      else
      {
        s=mid+1;
      }
    }
    if(a[mid]>a[s])
    {
      if(key<a[mid] && key>a[s])
      {
        e=mid-1;
      }
      else
      {
        s=mid+1;
      }
    }
  }
}

int main()
{
  int n;
  int key;
  cout<<"Enter the length of the array::";
  cin>>n;
  int a[n];
  cout<<"Enter the key you want to search in the array::";
  cin>>key;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int p = searchInArray(a,n,key);
  cout<<"The element was found at position::"<<p;
  


}
