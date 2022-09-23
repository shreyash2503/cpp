#include <iostream>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

int main()
{
  int flag = 0;
  string s;
  cin>>s;
  stack<char> s1;
  for(int i=0;i<s.length();i++)
  {
    if(s[i] == '{' || s[i] == '(' || s[i] == '[')
    {
      s1.push(s[i]);
    }
    else
    {
      if((s[i] == '}' && s1.top() == '{') || (s[i] == ')' && s1.top() == '(') || (s[i] == ']' && s1.top() =='['))
      {
        s1.pop();
      }
      else
      {
        flag = 1;
        break;
      }
    }
  }
if(s1.empty())
{
  cout<<"Balanced"<<endl;
}
else
{
 cout<<"Not a Balamced Paranthesis"<<endl; 
}


  
}
