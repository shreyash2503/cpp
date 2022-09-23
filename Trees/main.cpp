#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data)
	{
		this->data = data;
	}
};

void printTree(TreeNode<int>* root)
{
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
	{
		cout<<root->children[i]->data<<" ,";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		printTree(root->children[i]);
	}
}

void printTreeLevelWise(TreeNode<int>* root)
{
	queue<TreeNode<int>*> q;
	q.push(root);
	while(!q.empty())
	{
		for(int i=0;i<root->children.size();i++)
		{
			q.push(root->children[i]);
		}
		TreeNode<int>* flag = q.front();
		cout<<flag->data<<"::";

		for(int i=0;i<flag->children.size();i++)
		{
			cout<<flag->children[i]->data<<" ,";
		}
		cout<<endl;
		q.pop();
		root = q.front();

	}
}

TreeNode<int>* takeInput() //giving input is complicated because user needs to understand how recursion works to understand how to give input
{
	int data;
	cout<<"Enter data::";
	cin>>data;
	int size;
	TreeNode<int>* root = new TreeNode<int>(data);
	
	cout<<"Enter the number of nodes in the current treenode::";
	cin>>size;
	for(int i=1;i<=size;i++)
	{
		TreeNode<int>* flag = takeInput();
		root->children.push_back(flag);
	}
	return root;
}
//Take input level wise 
TreeNode<int>* takeInput2()
{
	int data;
	queue<TreeNode<int>*> q;
	cout<<"Enter data::";
	cin>>data;
	TreeNode<int>* root = new TreeNode<int>(data);
	q.push(root);
	while(!q.empty())
	{
		TreeNode<int>* flag = q.front();
		q.pop();
		int size;
		cout<<"Enter the number of elements present in "<<flag->data;
		cin>>size;
		for(int i=1;i<=size;i++)
		{
			int childData;
			cout<<"Enter data for "<<i<<" th element of "<<flag->data<<"::";
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			q.push(child);
			flag->children.push_back(child);
		} 
	}
	return root;
}


int main()
{

// TreeNode<int> *root = new TreeNode<int>(1);
// TreeNode<int> *n1 = new TreeNode<int>(2);
// TreeNode<int> *n2 = new TreeNode<int>(3);
// TreeNode<int> *n3 = new TreeNode<int>(4);
// TreeNode<int> *n4 = new TreeNode<int>(5);
// TreeNode<int> *n11 = new TreeNode<int>(100);
// TreeNode<int> *n12 = new TreeNode<int>(200);
// TreeNode<int> *n13 = new TreeNode<int>(300);
// TreeNode<int> *n14 = new TreeNode<int>(400);
// TreeNode<int> *n15 = new TreeNode<int>(500);
// TreeNode<int> *n21 = new TreeNode<int>(1000);
// TreeNode<int> *n22 = new TreeNode<int>(2000);
// root->children.push_back(n1);
// root->children.push_back(n2);
// root->children.push_back(n3);
// root->children.push_back(n4);
// n1->children.push_back(n11);
// n1->children.push_back(n12);
// n1->children.push_back(n13);
// n1->children.push_back(n14);
// n1->children.push_back(n15);
// n2->children.push_back(n21);
// n2->children.push_back(n22);
TreeNode<int>* root = takeInput2();

printTreeLevelWise(root);




}