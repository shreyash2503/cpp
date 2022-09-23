#include <iostream>
using namespace std;


template<typename T>
class queue
{
	T* data;
	int size;
	int firstIndex;
	int nextIndex;
	int capacity;
public:
	queue()
	{
		data = new T[5];
		this->capacity = 5;
		this->firstIndex = -1;
		this->nextIndex = 0;
		this->size = 0;

	}
	queue(int capacity)
	{
		data = new T[capacity];
		this->capacity = capacity;
		this->firstIndex = -1;
		this->nextIndex = 0;
		this->size = 0;
	}
	void push(T data)
	{
	
		if(size == capacity)
		{
			cout<<"The queue is full, you can no longer insert element::"<<endl;
			return;
		}	
		this->data[nextIndex] = data;
		nextIndex = (nextIndex+1)%capacity;
		size++;
		if(firstIndex == -1)
		{
			firstIndex = 0;
		}


	}
	void pop()
	{
		if(size == 0)
		{
			cout<<"Nothing left to pop the queue is empty"<<endl;
			firstIndex = -1;
			nextIndex = 0;
			
		}
		
		firstIndex = (firstIndex+1)%capacity;
		size--;
	}
	bool isEmpty()
	{
		if(size == 0)
		{
			return true;
		}
		else
			{
				return false;
			}
	}
	T front()
	{
		return this->data[firstIndex];
	}
	int getSize()
	{
		return this->size;
	}
};

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
      return ;
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
	

	int option;
	
	do{
	cout<<"1).Circular queue\n2).Reverse stack using queue\n"<<end;
	cout<<"Choose from the above::";
	cin>>option;
	if(option == 1)
	{
	int data;
	queue<int> q;
	q.push(100);
	q.push(200);
	q.push(300);
	q.push(400);
	q.push(500);
	q.pop();
	q.pop();
	q.push(600);
	q.push(700);
	int size = q.getSize();
	for(int i=0;i<size;i++)
	{
		cout<<"The front element in the queue is ::"<<q.front()<<endl;
		q.pop();
	}
	cout<<endl;
	}
	else if(option == 2)
	{
		int siz;

	Stack<int> s;
	cout<<"Enter the size of the stack::";
	cin>>siz;
	cout<<"Enter the elements::"<<endl;
	for(int i=0;i<siz;i++)
	{
		cin>>data;
		s.push(data);
	}
	for(int i=0;i<siz;i++)
	{
		
		q.push(s.topElement());
		cout<<s.topElement()<<" ";
		s.pop();

	}
	for(int i=0;i<siz;i++)
	{
	
		s.push(q.front());
		q.pop();
	}
	for(int i=0;i<siz;i++)
	{
		cout<<"\nThe element present at the top of the stack is::"<<s.topElement()<<endl;
		s.pop();
	}
	cout<<endl;

	}
	else if(option == 3)
	{
		break;
		exit(0);
	}
	}
	while(1);


}