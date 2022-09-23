#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

void removeAC(string v)
{
  stack<char> s;
  int size;
  for(int i=0;i<v.size();i++)
  {
    if(s.empty())
    {
      s.push(v[i]);
    }
    else
    {
      if(v[i] == s.top())
      {
        s.pop();
      }
      else
      {
        s.push(v[i]);
      }
    }
  }
  string t = "";
  while(!s.empty())
  {
    t.push_back(s.top());
    s.pop();
  }
  cout<<t;



}

int main()
{
  string s;
  cin>>s;
  removeAC(s);
}
