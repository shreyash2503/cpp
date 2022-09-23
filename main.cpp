#include <iostream>
using namespace std;
template <typename T>
class queue{
	T* data;
	int firstIndex;
	int nextIndex;
	int size;
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
		size = 0;
	}

	void push(T data)
	{
		if(size == capacity)
		{
			cout<<"The queue is already full you can no longer insert elements in the queue"<<endl;
			return;
		}
		this->data[nextIndex] = data;
		nextIndex = (nextIndex+1)%capacity;
		
		if(size == 0 && firstIndex == -1)
		{
			firstIndex = 0;
		}
		size++;
	}
	void pop()
	{
		if(size == 0)
		{
			cout<<"The queue is empty nothing is left to pop in the queue"<<endl;
		}
		firstIndex = (firstIndex+1)%capacity;
		size--;
		if(size == 0)
			{
				firstIndex = -1;
				nextIndex = 0;
			}
	}
	T front()
	{
		return data[firstIndex];

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
		return size;
	}
};

int main()
{
	queue<int> q;
	q.push(5);
	q.push(6);
	q.push(900);
	q.push(1000);
	q.push(300);
	q.push(400);
	q.push(600);
	q.pop();
	q.pop();
	q.pop();
	q.push(5);
	cout<<"The front element in the queue is::"<<q.front();
}