#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BTNode{
public:
	T data;
	BTNode<T> *left;
	BTNode<T> *right;
	BTNode(T data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	~BTNode(){
		delete this->left;
		delete this->right;
	}
};

BTNode<int>* takeInput() //-----> Take Input Level Wise 
{
	int data;
	cout<<"Enter the root data for the tree::";
	cin>>data;
	BTNode<int>* root = new BTNode<int>(data);
	queue<BTNode<int>*> q;
	q.push(root);
	while(!q.empty())
	{
		int data1;
		int data2;

		BTNode<int>* flag = q.front();
		cout<<"Enter the left data for "<<flag->data<<"::";
		cin>>data1;
		if(data1 != -1)
		{
			flag->left = new BTNode<int>(data1);
			q.push(flag->left);
		}
		cout<<"Enter the right data for "<<flag->data<<"::";
		cin>>data2;
		if(data2 != -1)
		{
			flag->right = new BTNode<int>(data2);
			q.push(flag->right);
		}
		q.pop();
	}
	return root;
}

// ! --->Inorder, PostOrder, PreOrder using recursion

void InOrder(BTNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void PostOrder(BTNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" " ;
}
void PreOrder(BTNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);

}

// ? Inorder PostOrder PreOrder without Recursion

void InOrderS(BTNode<int>* root)
{
	stack<BTNode<int>*> s;

    BTNode<int>* flag = root;
	while(flag != NULL || !s.empty())
	{
		while(flag != NULL)
		{
			s.push(flag);
			flag = flag->left;
		}
		flag = s.top();
		cout<<flag->data<<" ";
		s.pop();
		flag = flag->right;
	}
}

void PreOrderS(BTNode<int>* root)
{
	if(!root) return;
	stack<BTNode<int>*> s;
	BTNode<int>* flag = root;
	while(flag != NULL || !s.empty())
	{
		while(flag != NULL)
		{
			cout<<flag->data<<" ";
			if(flag->right)
			{
				s.push(flag->right);
			}
			flag = flag->left;

		}
	if(!s.empty())
	{
		flag = s.top();
		s.pop();
	}

	}
}

void PostOrderS(BTNode<int>* root)
{
	BTNode<int>* flag = root;
	stack<BTNode<int>*> s;
	BTNode<int>* pre = NULL;
	while(flag != NULL || !s.empty())
	{
		if(flag != NULL)
		{
			s.push(flag);
			flag = flag->left;
		}
		else
		{
			flag = s.top();
			if(flag->right == NULL || flag->right == pre )
			{
				cout<<flag->data<<" ";
				pre = flag;
				flag = NULL;
				s.pop();
			}
			else
			{
				flag = flag->right;
			}

		}
	}
		

}



int main()
{
	BTNode<int>* root = takeInput();
	bool condition = true;
	int data;	
	while(condition)
	{
		cout<<"Using Recursion::"<<endl;
		cout<<"1: PreOrder"<<endl;
		cout<<"2: PostOrder"<<endl;
		cout<<"3: InOrder"<<endl;
		cout<<"Without using Recursion"<<endl;
		cout<<"4: PreOrder"<<endl;
		cout<<"5: PostOrder"<<endl;
		cout<<"6: InOrder"<<endl;
		cout<<"Enter your selected option here::";
		cin>>data;
		if(data == 1)
		{
			PreOrder(root);
			cout<<endl;
		}
		else if(data == 2)
		{
			PreOrder(root);
			cout<<endl;
		}
		else if(data == 3)
		{
			InOrder(root);
			cout<<endl;
		}
		else if(data == 4)
		{
			PreOrderS(root);
			cout<<endl;
		}
		else if(data == 5)
		{
			PostOrderS(root);
			cout<<endl;
		}
		else if(data == 6)
		{
			InOrderS(root);
			cout<<endl;
		}
		else{
			exit(0);
		}
	}


}