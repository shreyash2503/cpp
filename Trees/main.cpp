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

	~TreeNode()
	{
		for(int i=0;i<this->children.size();i++)
		{
			delete this->children[i];
		}
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

//count the number of nodes in the tree

int countNodes(TreeNode<int>* root)
{
    int count = 1;
    if(root == NULL) // edge case , no need of base case as our leaf node will act as the base condition
    {
    	return 0;
    }
	
	for(int i=0;i<root->children.size();i++)
	{
		count +=countNodes(root->children[i]);
	}
	return count;
}

int heightOfTree(TreeNode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	int mx = 0;
	for(int i=0;i<root->children.size();i++)
	{
		int childHeight = heightOfTree(root->children[i]);
		mx = max(mx,childHeight);
	}
	return 1+mx;

}

//Depth of a node:- How far a node is from the root node
// For the root node the depth is zero while for children of the root node the value of depht is 1;
//Print all nodes at depth d or print all the nodes at level k;

void printNode(TreeNode<int>* root,int k)
{
	if(k == 0)
	{
		cout<<root->data<<" ";
		return;
	}
	if(root == NULL)
	{
		cout<<"The tree is empty::";
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		printNode(root->children[i], k-1);

	}
}

// count the number of leaf nodes in the given tree;

int NoOfLeafNodes(TreeNode<int>* root)
{
	int count = 0;
	if( root && root->children.size() == 0)
	{
		return 1;
	}
	if(root == NULL)
	{
		return 0;
	}
	for(int i=0;i<root->children.size();i++)
	{
		count+=NoOfLeafNodes(root->children[i]);
	}
	return count;
}
//Count the number of leaf nodes using pass by reference;

void NoOfLeafNodes2(TreeNode<int>* root,int &ans)
{
	if(root && root->children.size())
	{
		ans++;
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		NoOfLeafNodes2(root->children[i],ans);
	}
}
//PreOrder Traversal in Trees---->First print the root and then print its children

void preOrderTraversal(TreeNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++)
	{
		preOrderTraversal(root->children[i]);
	}
}

//PostOrderTraversal in Trees--->first print the children and then the parent of the children


void postOrderTraversal(TreeNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		postOrderTraversal(root->children[i]);
	}
	cout<<root->data<<" ";
}

//Deleting a tree (As we do dynamic memory allocation it is our job to free the memory we created in heap)
//First delete children then delete root or else this will result in memory leak
void deleteTree(TreeNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	for(int i=0;i<root->children.size();i++)
	{
		deleteTree(root->children[i]);
	}
	delete root;
}
//Binary Trees;




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

//printTreeLevelWise(root);
cout<<"The number of nodes in the tree are " <<countNodes(root)<<endl;
//Input code for printing the nodes at level k;
//cout<<"The node present at depth 1 is ";
//printNode(root,2);
/////////////
//Input code for counting the number of leaf nodes;
//cout<<"The number of leaf nodes in the tree are "<<NoOfLeafNodes(root)<<endl;
////////////////////////////

//PreOrderTraversal Input code 
postOrderTraversal(root);

//code for deleteing a tree;
delete root;

return 0;
}