#include <iostream>
using namespace std;

template<typename T>
class Node{
	T data;
	Node<T>* next;
public:
	Node(T data)
	{
		this->data = data;
		this->next = NULL;
	}
}

template<typename T>
class Stack
{
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	Stack()
	{
		head = NULL;
		tail = NULL:
	}
	void push(T data)
	{
		Node<T> *n = new Node<T>(data); 
		if(head == NULL)
		{
			head = n;
			tail = NULL;
			size++;

		}
		else
		{
			n->next = head;
			head = n;
			size++;
		}
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
}