#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node* next;
    Node(int data)
    {
      this->data = data;
      this->next = NULL;
    }
};

Node* takeInput()
{
  int data;
  int count = -1;
  cin>>data;
  Node* head = NULL;
  Node* tail = NULL;
  while(data != -1)
  {
    Node* n = new Node(data);
    if(head == NULL)
    {
      head = n;
      tail = n;
      count++;
    }
    else
    {
      tail->next = n;
      tail = n;
      count++;
    }
    cin>>data;
  }
  return head;
}

void print(Node* head)
{
  while(head != NULL)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
}
int main()
{
  int m;
  cout<<"Enter the gap after which the men will be executed::";
  cin>>m;
  Node* head = takeInput();
  Node* temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = head;
  while(1)
  {
    for(int i=1;i<m-1;i++)
    {
      head = head->next;
    }
    Node* n = head->next;
    head->next = head->next->next;
    n->next = NULL;
    delete n;
    head = head->next;
    if(head->next == head)
    {
      break;
    }


  }
  cout<<"The person that will be alive will be at the position::"<<head->data;

}
