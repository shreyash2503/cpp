#include <bits/stdc++.h>
#include <cstring>
#include <string>
using namespace std;
template<typename T>
class Stack{
  T* array;
  int top;
  int capacity;
  public:
  stack()
  {
    this->array = new T[5];
    top = -1;
    capacity = 5;
  }
  void push(int data)
  {
    int temp = top;
    if(++temp == capacity)
    {
      T* newArray = new T[capacity*2];
      for(int i=0;i<=top;i++)
      {
        newArray[i] = array[i];
      }
      delete []array;
      array = newArray;
      this->capacity = capacity*2;
    }
    array[++top] = data;
  }
  void pop()
  {
    if(top == -1)
    {
      cout<<"Stack underflow";
    }
    else
    {
      top--;
    }
  }
  bool isEmpty()
  {
    if(top == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  void print()
  {
    for(int i=0;i<=top;i++)
    {
      cout<<array[i]<<" ";
    }
    cout<<endl;
  }
  T topElement()
  {
    return array[top];
  }

};


bool balancedParanthesis(string a)
{
  Stack<char> s;
  for(int i=0;i<a.size();i++)
  {
    if(a[i] == '(' || a[i] == '{' || a[i] == '[')
    {
      s.push(a[i]);
    }
    else
    {
      if((a[i] == ')' && s.topElement() == '(') || (a[i] == '}' && s.topElement() == '{') || (a[i] == ']' && s.topElement() == '['))
      {
        s.pop();
      }
      else
      {
        s.push(a[i]);
        break;
      }
    }
  }

  if(s.isEmpty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

 int resolvePE(char a[])
{
  Stack<char> s;
  for(int i=0;i<strlen(a);i++)
  {
    if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
    {
        int element1 = s.topElement();
        s.pop();
        int element2 = s.topElement();
        s.pop();
        if(a[i] == '+')
        {
          s.push(element1+element2);
        }
        else if(a[i] == '-')
        {
          s.push(element2 - element1);
        }
        else if(a[i] == '*')
        {
          s.push(element2*element1);
        }
        else if(a[i] == '/')
        {
          s.push(element2/element1);
        }
    }
    else
    {
      s.push(atoi(&a[i]));
    }
  }
  return s.topElement();


}

int main()
{
  string s;
  char a[100];
  cin>>s;
  if(balancedParanthesis(s))
  {
    cout<<"Balanced Paranthesis::"<<endl;
  }
  else
  {
    cout<<"Not a Balanced Paranthesis::"<<endl;
  }
  cin>>a;
  cout<<resolvePE(a);
}
