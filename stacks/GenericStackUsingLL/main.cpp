#include <iostream>
using namespace std;


template <typename T>
class Node{
  public:
    T data;
    Node<T> *next;
    Node(T data)
    {
      this->data = data;
      this->next = NULL;
    }

};

template <typename T>
class Stack
{
  Node<T> *head;
  Node<T> *tail;
  int size;
  public:
  Stack()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }
  void push(T data)
  {
    Node<T> *n = new Node<T>(data);
    if(head == NULL)
    {
      head = n;
      size++;
    }
    else
    {
      n->next = head;
      head = n;
      size++;
    }


  }
  void pop()
  {
    Node<T> *temp = head->next;
    delete head;
    head = temp;
    size--;
  }
  int sizeOfStack()
  {
    return size;
  }

  bool isEmpty()
  {
    if(head == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  T top()
  {
    return head->data;
  }
  void print()
  {
    Node<T>* temp = head;
    while(temp != NULL)
    {
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
};

int main()
{
  Stack<int> s;
  s.push(2);
  s.push(4);
  s.push(5);
  s.print();
  s.pop();
  s.print();



}
