#include <iostream>
using namespace std;

int main()
{
  int n;
  cout<<"Enter the size of the array::";
  cin>>n;
  int a[n];
  cout<<"Enter the array::";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int cand = a[0];
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(cand!=a[i])
    {
      count--;
      if(count==0)
      {
        cand = a[i];
      }
    }
    else
    {
      count++;
    }
  }
  cout<<"The majority element in the array is "<<cand;
}
