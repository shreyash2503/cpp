#include <iostream>
using namespace std;

template<typename T>
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

template<typename T>
class queue
{
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	queue()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void push(T data)
	{
		Node<T> *flag = new Node<T>(data);
		if(head == NULL)
		{
			head = flag;
			tail = flag;
			size++;
		}
		else
		{
			tail->next = flag;
			tail = flag;
			size++;
		}
	}
	void pop()
	{
		Node<T> *temp;
		temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	T front()
	{
		return head->data;
	}
	int getSize()
	{
		return this->size;
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

};

int main()
{
	queue<int> q;
	q.push(100);
	q.push(200);
	q.push(300);
	q.push(400);
	q.push(500);
	q.push(600);
	q.push(700);
	q.push(800);
	q.pop();
	cout<<"The element present at the front of the queue is ::"<<q.front()<<endl;

}