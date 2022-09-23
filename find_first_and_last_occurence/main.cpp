#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int getfirst(vector <int>& v,int target)
    {
     int s = 0;
     int e = v.size()-1;
     int ans;
     while(s<=e)
     {
       int mid = (s+e)/2;
       if(v[mid]==target)
       {
        ans = mid;
         e = mid-1;
       }
       else if(v[mid]>target)
       {
         e = mid-1;
       }
       else{
         s = mid+1;
       }
     }
    return ans;
    }
    int getLast(vector <int>& v,int target)
    {
      int s=0;
      int ans;
      int e = v.size()-1;
      while(s<=e)
      {
        int mid = (s+e)/2;
        if(v[mid]==target)
        {
          ans = mid;
          s=mid+1;
        }
        else if(v[mid]<target)
        {
          s = mid+1;
        }
        else
        {
          e = mid-1;
        }
      }
      return ans;


    }
};
int main(){

  vector <int> v;
  int n;
  int target;
  int ans;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>ans;
    v.push_back(ans);
  }
  cin>>target;
  Solution s;
  cout<<s.getfirst(v,target)<<endl;
  cout<<s.getLast(v,target)<<endl;
}
