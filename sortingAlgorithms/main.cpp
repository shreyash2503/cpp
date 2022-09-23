#include <iostream>
using namespace std;


void mergeArray(int a[],int x[],int y[],int s,int e)
{
  int mid = (s+e)/2;
  int i = s;
  int j = mid+1;
  int k = i;
  while (i<=mid && j<=e)
  {
    if(x[i]<y[j])
    {
      a[k] = x[i];
      k++;
      i++;
    }
    else
    {
      a[k] = y[j];
      k++;
      j++;
    }
  }
  while(i<=mid)
  {
    a[k] = x[i];
    k++;
    i++;
  }
  while(j<=e)
  {
    a[k] = y[j];
    k++;
    j++;
  }
}

void mergeSort(int a[],int s, int e)
{
  int mid = (s+e)/2;
  int x[100];
  int y[100];
  if(s==e)
  {
    return;
  }
  for(int i=0;i<=mid;i++)
  {
    x[i] = a[i];
  }
  for(int i=mid+1;i<=e;i++)
  {
    y[i] = a[i];
  }
  mergeSort(x,s,mid);
  mergeSort(y,mid+1,e);
  mergeArray(a,x,y,s,e);
}


int main()
{
  int n;
  cout<<"Enter the length of the array::";
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
