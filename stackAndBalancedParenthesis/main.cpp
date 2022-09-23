
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template<typename T>
class Stack{
  T* array;
  int top;
  int capacity;
  public:
  Stack()
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
  Stack<int> s;
  for(int i=0;i<strlen(a);i++)
  {
    if(a[i] == '+' || a[i] == '-' || a[i] =='*' || a[i] == '/')
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
      if(a[i]>='0' && a[i] <='9')
      {
      s.push(a[i] - '0');
      }
    }
  }
  return s.topElement();


}


//Infix to postfix
int priority(char a)
{
  if(a == '/' || a=='*')
  {
    return 2;
  }
  else if (a == '+' || a=='-')
  {
    return 1;
  }
  else if(a == '^')
  {
    return 3;
  }
  return 0;
}

void infixToPostfix(string a)
{
  Stack<int> s;
  string t;
  for(int i=0;i<a.size();i++)
  {
    if((a[i]>='a' && a[i]<='z') || (a[i]>='0' && a[i]<='9') || (a[i]>='A' && a[i]<='Z'))
    {
      t+=a[i];
    }
    else if(a[i] == '(')
    {
      s.push(a[i]);
    }
    else if(a[i] == ')')
    {
      while(s.topElement()!='(')
      {
        t+=s.topElement();
        s.pop();
      }
      s.pop();
    }
    else
    {
      while(!s.isEmpty() && priority(a[i]) <= priority(s.topElement()))
      {
        t+=s.topElement();
        s.pop();
      }
      s.push(a[i]);
    }
  }
  while(!s.isEmpty())
  {
    t+=s.topElement();
    s.pop();
  }

cout<<"\n<-------------------------------------------------------------------->"<<endl;
cout<<"The postfix of the operation is ::"<<t;
cout<<"\n<-------------------------------------------------------------------->"<<endl;
}

int main()
{
  // string s;
  // int i =0;
  // int k;
  // char a[100];
  // cin>>s;
  // if(balancedParanthesis(s))
  // {
  //   cout<<"Balanced Paranthesis::";
  // }
  // else
  // {
  //   cout<<"Not a Balanced Paranthesis::";
  // }
  // cin>>a;
  // for(int i=0;i<strlen(a);i++)
  // {
  //   cout<<a[i]<<" ";
  // }
  // cout<<endl;
  // cout<<resolvePE(a);

  // string s;
  // cin>>s;
  // infixToPostfix(s);
  int option;
  do{
    cout<<"\n1).Perform Balanced Paranthesis\n\n2).Convert Infix expression to Postfix expression\n\n3).Evaluate Postfix expression\n\n4).Exit"<<endl;
    cout<<endl;
    cout<<"Choose from one of the option above::";
    cin>>option;
    if(option == 1)
    {
      string s;
      cout<<"Enter the paranthesis to check if it is balanced::";
      cin>>s;
      cout<<endl;
      if(balancedParanthesis(s))
      {
        cout<<"<---------The parathesis is balanced--------->"<<endl;
        cout<<endl;
      }
      else
      {
        cout<<"---------The paranthesis is NOT balanced--------->"<<endl;
        cout<<endl;
      }
    }
    else if(option == 2)
    {
      string a;
      cout<<"Enter the infix expression here::";
      cin>>a;
      infixToPostfix(a);
    }
    else if(option == 3)
    {
      char a[100];
      cout<<endl;
      cout<<"Enter the postfix expression you want to evaluate here::";
      cin>>a;
      cout<<endl<<endl;

      cout<<"\n<-------------------------------------------------------------------->"<<endl;
      cout<<"The value of the postfix expression is::"<<resolvePE(a)<<endl<<endl;

      cout<<"\n<-------------------------------------------------------------------->"<<endl;
    }
    else if(option == 4)
    {
      break;
      exit(0);
    }
  }
  while(true);
}
