#include <iostream>
using namespace std;
//A Queue is FIFO First In First Out 
//The difference between a stack and queue is the entry and exit points
// In a queue the entry and the exit points are different while in a stack the entry and exit points are the same
template<typename T>
class queue{
	T* data;
	int size;  // To keep a track of the size of the queue
	int firstIndex;
	int nextIndex;
	int capacity;
public:
	queue()
	{
		this->capacity = 5;
		data = new T[5];
		firstIndex = -1;
		nextIndex = 0;
		size = 0;
	}
	queue(int capacity)
	{
		this->capacity = capacity;
		data = new T[capacity];
		firstIndex = -1;
		nextIndex = 0;
		size =0;
	}
	void push(T data)
	{
		if(size == capacity)
		{
			cout<<"The queue is full and you can no longer insert elements in the queue::"<<endl;
			return;
		}
		this->data[nextIndex] = data;
		nextIndex = (nextIndex+1)%capacity;
		if(firstIndex == -1 && size == 0)
		{
			firstIndex = 0;
		}
		size++;
	}
	void pop()
	{
		if(isEmpty())
		{
			cout<<"Queue Empty"<<endl;
			return ;
		}
		firstIndex = (firstIndex+1)%capacity;
		size--;
		if(size == 0)
		{
			firstIndex = -1;
			nextIndex = 0;
		}
		
	}
	bool isEmpty()
	{
		if(size == 0 && firstIndex == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int getSize()
	{
		return this->size;
	}
	T front()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty"<<endl;
		}
		return this->data[firstIndex];
	}
};

int main()
{
	queue<int>q(5);
	q.push(100);
	q.push(200);
	q.push(300);
	q.push(400);
	q.push(500);
	q.pop();
	q.pop();
	q.pop();
	q.push(600);
	q.push(700);
	q.push(800);
	cout<<"The first index in the queue is ::"<<q.front();




}