#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(int element,stack<int> &s)
{
	if(s.empty())
	{
		s.push(element);
		return;
	}
	else
	{
		int data = s.top();
		s.pop();
		insertAtBottom(element,s);
		s.push(data);
	}


}
void reverse(stack<int> &s)
{
	if(s.empty())
	{
		return;
	}
	else
	{
		int element = s.top();
		s.pop();
		reverse(s);
		insertAtBottom(element,s);
	}

}
int main()
{
	stack<int> s;
	int size;
	cout<<"Enter the size of the stack::";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		int data;
		cin>>data;
		s.push(data);
	}

	reverse(s);
	for(int i=0;i<size;i++)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}