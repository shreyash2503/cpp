#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data)
    {
      this->data = data;
      this->next = NULL;
    }
};
class Stack{
  Node* head;
  Node* tail;
  int size;
  public:
  Stack()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }
    void push(int data)
      {
        
        Node* n = new Node(data);
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
      Node* temp = head->next;
      delete head;
      head = temp;
      size--;
      
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
    int sizeOfStack()
    {
      return size;
    }
    int top()
    {
      return head->data;
    }
    void print()
    {
      Node* temp = head;
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
  Stack s;
  s.push(5);
  s.push(7);
  s.push(9);
  s.push(100);
  s.pop();
  cout<<"The size of the stack is "<<s.sizeOfStack()<<endl;
  s.print();
  cout<<s.isEmpty()<<endl;
  cout<<s.top();
}
