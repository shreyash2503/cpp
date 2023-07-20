#include <bits/stdc++.h>
using namespace std;

// ! Everything in n's left subtree is less than n's data
// ! Everything in n's right subtree is greater than n's data
// ! Trees following the above condidtions is called a binary Search Tree

template <typename T>
class BTNode{

public:
	T data;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode(T data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	~BTNode()
	{
		delete this->left;
		delete this->right;
	}


};
//Create a BST from a sorted array

BTNode<int>* createBST(vector<int> &v,int s, int e) //----> s and e firstly represent the starting and size of array e = v.size()-1
{
	if(s > e) return NULL;
	int middle = (s+e)/2;
	BTNode<int>* root = new BTNode<int>(v[middle]);
	root->left = createBST(v, s, middle-1);
	root->right = createBST(v, middle+1, e);
	return root;
}
///Pair Class 
class Pair
{
public:
	BTNode<int>* head;
	BTNode<int>* tail;
};

// bool isPresent(BTNode<int>* root, int key)
// {
// 	if(root == NULL) return false;
// 	if(key < root->data){
// 		bool value = isPresent(root->left, key);
// 		if(value)
// 			{
// 				return true;
// 			}
// 	}
// 	if(key > root->data)
// 	{
// 		bool value = isPresent(root->right, key);
// 		if(value)
// 		{
// 			return true;
// 		}
// 	}
// 	if(key == root->data)
// 	{
// 		return true;
// 	}

// 	return false;
// }

class BST
{
	BTNode<int>* root;

	Pair convertToLL(BTNode<int>* root)
	{
		BTNode<int>* flag = flag;
		if(flag->left == NULL && flag->right == NULL)
		{
			Pair p;
			p.head = temp;
			p.tail = temp;
			return p;
		}
		else if(flag->left == NULL && flag->right)
		{
			Pair p;
			p = convertToLL(flag->right);
			flag->right = p.head;
			Pair ans;
			ans.head = flag;
			ans.tail = p.tail;
			return ans;
		}
		else if(flag->right == NULL && flag->left)
		{
			Pair p;
			p = convertToLL(flag->left);
			p.tail->right = flag;
			Pair ans;
			ans.head = p.head;
			ans.tail = flag;
			return ans;

		}
		else
		{
			Pair p;
			Pair p1;
			p = convertToLL(flag->left);
			p.tail->right = flag;
			p1 = convertToLL(flag->right);
			flag->right = p1.head;
			Pair ans;
			ans.head = p.head;
			ans.tail = p1.tail;			
			return ans;

		}

	}



	BTNode<int>* insert(BTNode<int>* root, int data)
	{
		if(root == NULL)
		{
			BTNode<int>* temp = new BTNode<int>(data);
			return temp;
		}
		if(root->data > data)
		{
			root->left = insert(root->left, data);
		}
		if(root->data < data)
		{
			root->right = insert(root->right, data);
		}
		return root;

	}
	void printTree(BTNode<int>* root)
	{
		if(root == NULL) return;

		cout<<root->data<<"::";
		if(root->left)
		{
			cout<<root->left->data<<", ";
		}
		if(root->right)
		{
			cout<<root->right->data<<", ";
		}
		cout<<endl;
		printTree(root->left);
		printTree(root->right);
	}

	BTNode<int>* deleteData(BTNode<int>* root, int data)
	{
		if(root == NULL)
		{
			return NULL;
		}
		if(root->data > data)
		{
			root->left = deleteData(root->left, data);
		}
		else if(root->data < data)
		{
			root->right = deleteData(root->right, data);
		}
		else if(root->data == data)
		{
			if(root->left && root->right)
			{
				BTNode<int>* minRootNode = root->right;
				while(minRootNode->left != NULL)
				{
					minRootNode = minRootNode->left;
				}
				int rightMin = minRootNode->data;
				root->data = rightMin;
				root->right = deleteData(root->right, rightMin);


			}
			else if(root->right == NULL)
			{
				BTNode<int>* temp = root->left;
				root->left = NULL;
				delete root;
				return temp;

			}
			else if(root->left == NULL)
			{
				BTNode<int>* temp = root->right;
				root->right = NULL;
				delete root;
				return temp;

			}
			else{
				delete root;
				return NULL;
			}
		}
		return root;
	}
public:
	BST()
	{
		this->root = NULL;
	}
	~BST()
	{
		delete root;
	}
	BTNode<int>* insert(int data)
	{
		this->root = this->insert(this->root, data);
		return root;

	}
	void print()
	{
		this->printTree(this->root);	
	}
	BTNode<int>* delete1(int data)
	{
		return deleteData(this->root, data);
	}
	BTNode<int>* convertToLL()
	{
		Pair p = this->convertToLL(this->root);
		return p.head;
	}
};





int main()
{
	BST b;

	b.insert(5);
	b.insert(3);
	b.insert(2);
	b.insert(4);
	b.insert(7);
	b.insert(6);
	b.insert(8);
	b.delete1(5);
	b.print();
	cout<<endl;
	BTNode<int>* head = b.convertToLL();
	BTNode<int>* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->right;
	}

}