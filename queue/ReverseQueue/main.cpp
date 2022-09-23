#include <iostream>
#include <queue>
using namespace std;

void reverse(queue<int> &q)
{
	if(q.empty())
	{
		return;
	}
	int element = q.front();
	q.pop();
	reverse(q);
	q.push(element);
}

int main()
{
	int size;
	queue<int> q;
	cout<<"Enter the size of the queue::";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		int data;
		cin>>data;
		q.push(data);
	}
	reverse(q);
	for(int i=0;i<size ;i++)
	{
		cout<<q.front()<<" ";
		q.pop();
	}

}