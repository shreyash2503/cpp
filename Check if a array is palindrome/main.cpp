#include <iostream>

using namespace std;
bool checkPalindrome(int a[],int s,int e)
{
   if(s>e)
   {
       return true;
   }
   if(a[s]==a[e])
   {
       return checkPalindrome(a,s+1,e-1);
   }
   else{
    return false;
   }
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
   cout<<checkPalindrome(a,0,n-1);
}
