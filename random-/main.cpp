#include <iostream>
#inlcude <queue>
#include <vector>
using namespace std;

template<typename T>
class TreeNode
{
public:
	T data
	vector<TreeNode<T>*> children;
	TreeNode(T data)
	{
		this->data = data;
	}
}
void printTree(TreeNode<int>* root)
{
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data;
	}
	for(int i=0;i<root->children.size();i++)
	{
		printtree(root->children[i]);
	}

}

void printTree2(TreeNode<int>* root)
{
	queue<TreeNode<int>*> q;
	q.push(root);
	while(!q.empty())
	{
		for(int i=0;i<root->children.size();i++)
		{
			q.push(root->children[i]);
		}
		cout<<root->data<<":";
		for(int i = 0;i<root->children.size();i++)
		{
			cout<<root->children[i]->data<<" ,";
		}
		cout<<endl;
		q.pop();
		root = q.front();

	}
}

TreeNode<int>* takeInput()
{
	int data;
	cout<<"Enter data::";
	cin>>data;
	TreeNode<int>* root = new TreeNode<int>(data);
	int size;
	for(int i=0;i<size;i++)
	{
		TreeNode<int>* temp = takeInput();
		root->children.push(temp);
	}
	return root;

}
TreeNode<int>* takeInput2()
{
	int data;
	cout<<"Enter data::";
	cin>>data;
	TreeNode<int>* root = new TreeNode<int>(root);
	queue<TreeNode<int>*> q;
	q.push(root);
	while(!q.empty())
	{
		int size;
		cout<<"Enter the number of elements you want to enter in "<<root->data;
		cin>>size;
		for(int i=0;i<size;i++)
		{
			int data;
			cout<<"Enter the data you want to enter in "<<i<<" th node of "<<root->data;
			cin>>data;
			TreeNode<int>* temp = TreeNode<int>(data);
			root->children.push(temp);
			q.pop();
			root = q.front();
		}
	}
}
 
