#include <iostream>
using namespace std;

template<typename T>
class queue
{
	T* data;
	int firstIndex;
	int nextIndex;
	int size;
	int capacity;
public:
	queue()
	{
		data = new T[5];
		firstIndex = -1;
		nextIndex = 0;
		size = 0;
		capacity = 5;
	}

	void push(T data)
	{
		if(size == capacity)
		{
			T* newArray = new T[capacity*2];
			int j=0;
			for(int i=firstIndex;i<capacity;i++)
			{
				newArray[j] = this->data[i];
				j++;
			}
			for(int i=0;i<firstIndex;i++)
			{
				newArray[j] = this->data[i];
					j++;
			}
			firstIndex = 0;
			nextIndex = capacity;
			this->capacity = this->capacity*2;
			delete [] this->data;
			this->data = newArray;
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
			cout<<"The queue is already empty, you can no longer insert elements in the queue"<<endl;
			firstIndex = -1;
			nextIndex = 0;
			return;
		}
		firstIndex = (firstIndex+1)%capacity;
		size--;

	}
	T front()
	{
		return data[firstIndex];
	}
};

int main()
{
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
	q.push(800);
	q.push(900);
	
	cout<<"The front of the queue is ::"<<q.front();
}