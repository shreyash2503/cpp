#include <iostream>
using namespace std;


int main()
{
  int max = INT_MIN;
  int n;
  cout<<"Enter the size of the array::";
  cin>>n;
  int a[n];
  int b[n];
  int ans = 0;
  cout<<"Enter the array::";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int count = 0;
  for(int i=0;i<n;i++)
  {
    count = 0;
    for(int j=0;j<n;j++)
    {
        if(a[i]==a[j])
        {
          count++;
        }
    }
    b[i]=count;
    if(b[i]>max)
    {
      max = b[i];
      ans = a[i];
    }
  } 
  cout<<"The majority element in the array is "<<ans;
}
