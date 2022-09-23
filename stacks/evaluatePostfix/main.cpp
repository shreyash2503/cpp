
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<char>&v)
{
  stack<int> s;
  for(int i=0;i<v.size();i++)
  {
    if(v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
    {
      int ele1 = s.top();
      s.pop();
      int ele2 = s.top();
      s.pop();
      if(v[i] == "+")
      {
        s.push(ele1 + ele2);
      }
      else if(v[i] == "-")
      {
        s.push(ele1 - ele2);
      }
      else if(v[i] == "*")
      {
       s.push(ele1 * ele2);
      }
      else
      {
        s.push(ele1 / ele2);
      }

    }
    else
    {
      s.push(atoi(v[i].c_str()));
    }
  }
  return s.top();
}


 int main()
{
  string s;
  vector<char> v;
  cin>>s;
  for(int i=0;s.size();i++)
  {
    v.push_back(s[i]);
  }
  cout<<evalRPN(v);

}
