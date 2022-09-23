#include <iostream>
using namespace std;

int searchInRotatedSortedArray(int a[],int n,int key) //3 4 5 1 2--->Rotated Sorted Array 
{
  int s=0;
  int e=n;
  while(s<=e)
  {
    int mid = (s+e)/2;
    if(a[mid]==key)
    {
      return mid;
    }
    if(a[mid]<a[e])
    {
      if(a[mid]<key && key<a[e])
      {
        s=mid+1;
      }
      else
      {
        e=mid-1;
      }
    }
    if(a[mid]>a[s])
    {
      if(a[mid]<key && key>a[s])
      {
        s=mid+1;
      }
      else
      {
        e=mid-1;
      }
    }
  }
}



int  main()
{
  int n;
  cout<<"Enter the size of the array you want to search the key::";
  cin>>n;
  int a[n];
  int key;
  cout<<"Enter the key::";
  cin>>key;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];

  }
  int index = searchInRotatedSortedArray(a,n,key);
  cout<<"The index of the element is ::"<<index;

}
