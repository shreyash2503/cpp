#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class TreeNode{
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode(T data)
	{
		this->data = data;
	}
	~TreeNode()
	{
		delete this->left;
		delete this->right;
	}

};

TreeNode<int>* takeInput()
{
	queue<TreeNode<int>*> q;
	int data;
	cout<<"Enter the data for root";
	cin>>data;
	TreeNode<int> *temp = new TreeNode<int>(data);
	q.push(temp);
	while(!q.empty())
	{
			int data;
			cout<<"Enter data for left::";
			cin>>data;
			TreeNode<int>* flag = new TreeNode<int>(data);
			q.top()->left = flag;
			int data1;
			cout<<"Enter data for the right node::";
			cin>>data1;
			TreeNode<int>* flag1 = new TreeNode<int>(data1);
			q.top()->right = flag2;
			q.push(flag);
			q.push(flag1);
			q.pop();
	
	}

}

void printInOrder(TreeNode<int>* root)
{
	if(root == NULL) return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}