#include <iostream>
using namespace std;

void insertionSort(int a[],int n)
{
  for(int i=1;i<n;i++)
  {
    int key = a[i];
    int j=i-1;
    while(j>=0 && a[j]>key)
    {
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
  }
}

void selectionSort(int a[],int n)
{
  for(int i=0;i<=n-2;i++)
  {
    int smallest = i;
    for(int j=i+1;j<n;j++)
    {
     if(a[j]<a[smallest])
     {
       smallest = j;
     } 
     swap(a[smallest],a[i]);
    }
  }
}

void merge(int a[],int x[],int y[],int s, int e)
{
  int mid = (s+e)/2;
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
  while(j<=mid)
  {
    a[k]=y[j];
    k++;
    j++;
  }
}

void mergeSort(int a[],int s, int e)
{
  if(s>=e)
  {
    return;
  }
  int mid=(s+e)/2;
  int x[100];
  int y[100];
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
  merge(a,x,y,s,e);
}

int partition(int a[],int s,int e)
{
  int key = a[e];
  int count = 0;
  for(int i=0;i<=e;i++)
  {
    if(key>a[i])
    {
      count++;
    }
  }
  swap(a[count],a[e]);
  int i = s;
  int j = count+1;
  while((i<=count && j>count))
  {
    if(a[i]>a[count] && a[j]<a[count])
    {
      swap(a[i],a[j]);
      i++;
      j++;
    }
    else
    {
      i++;
      j++;
    }
  }
  return count;
}
void quickSort(int a[],int s,int e)
{
  if(s>=e)
  {
    return;
  }
  int p = partition(a,s,e);
  quickSort(a,s,p-1);
  quickSort(a,p+1,e);
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
 // insertionSort(a,n);
  //  selectionSort(a,n);
   //mergeSort(a,0,n-1);
   quickSort(a,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
}
