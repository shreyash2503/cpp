#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(45);
  s.push(100);
  s.push(67);
  cout<<s.top();
  if(s.empty())
  {
    cout<<"Hi you called s.empty()"<<endl;
  }
  else
  {
    cout<<"Hi you called !s.empty()"<<endl;
  }
  while(!s.empty())
  {
    cout<<s.top()<<endl;
    s.pop();
  }
  return 0;
}
