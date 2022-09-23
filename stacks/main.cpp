#include <iostream>
using namespace std;

template<typename T>
class Stack{
  T *array;
  int top;
  int capacity;
  public:
  Stack()
  {
    this->capacity = 5;
    array = new T[5];
    top = -1;
  }
  void push(T data)
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
      cout<<"Stack underflow"<<endl;
    }
    else
    {
      top--;
    }
  }
  void print()
  {
    for(int i=0;i<=top;i++)
    {
      cout<<array[i]<<endl;
    }
  }
  void size()
  {
    cout<<"The size of the stack is "<<top+1<<endl;
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

  T topElement()
  {
    if(isEmpty()) return 0;//Any type of function with any data type can return zero
    else return array[top]; 
  }

};

int main()
{
  // s1.push(2);
  // s1.push(3);
  // s1.push(56);
  // s1.push(100);
  // s1.print();
  //
  //
  //
  // s1.pop();
  // s1.push(99);
  // cout<<endl;
  // s1.print();
  // s1.size();
  // cout<<endl;
  // s1.print();
  // cout<<s1.isEmpty()<<endl;
  // cout<<s1.topElement();
  // cout<<endl;
  // while(!s1.isEmpty())
  // {
  //   cout<<s1.topElement()<<endl;
  //   s1.pop();
  // }
  // s1.size();
  Stack<int> s1;
  for(int i=0;i<100;i++)
  {
    s1.push(i);
  }
  s1.print();
  for(int i=0;i<100;i++)
  {
    cout<<s1.topElement();
    s1.pop();
  }
}
