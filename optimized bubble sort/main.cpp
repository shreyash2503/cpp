#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
vector <int> spiralMatrix(vector <vector<int>>& v)
{
  int sr=0,sc=0;
  int m=v.size();
  int n=v[0].size();
  int er=m-1;
  int ec=n-1;
  int count=0;
  vector <int> ans;

  while(sr<=er && sc<=ec){


  for(int i=sc;i<=ec;i++){
    ans.push_back(v[sr][i]);
    count++;
  }
  sr++;
  if(count==m*n) return ans;
  for(int i=sr;i<=er;i++)
    {
      ans.push_back(v[i][ec]);
      count++;
    }
  ec--;
  if(count==m*n) return ans;
  for(int i=ec;i>=sc;i--)
    {
      ans.push_back(v[er][i]);
      count++;
    }
  er--;
  if(count==m*n) return ans;
  for(int i=er;i>=sr;i--)
    {
      ans.push_back(v[i][sc]);
      count++;
    }
  sc++;
  if(count == m*n) return ans;


}
}
};

int main() {

  vector <vector<int>>t{
    {1,2,3},
{3,4,5},
{6,7,8}
  };

  Solution s;
  vector<int> ans = s.spiralMatrix(t);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }

}
