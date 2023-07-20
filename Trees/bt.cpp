// #include <iostream>
// #include <queue>
#include <bits/stdc++.h>
using namespace std;

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

// Python is the best programming language in the whole world







void printBT(BTNode<int>* root)
{
	if(root == NULL)
	{
		return;

	}
	cout<<root->data<<":";
	if(root->left !=NULL)
	{
		cout<<root->left->data<<" ";
	}	
	if(root->right != NULL)
	{
		cout<<root->right->data<<" ";
	}
	cout<<endl;
	printBT(root->left);
	printBT(root->right);
}
//Take input root wiss ---> First input for all left nodes will be taken and then the input for the right nodes will be taken

BTNode<int>* takeInput()
{
	int data;
	cout<<"Enter the data::";
	cin>>data;
	if(data == -1)
	{
		return NULL;
	}
	BTNode<int>* root = new BTNode<int>(data);
	root->left = takeInput();
	root->right = takeInput();

	return root;
}

//Take input level wise --> input for the left as well as the right node will be taken at the same time 

BTNode<int>* takeInput2()
{
	queue<BTNode<int>*> q;
	int data;
	cout<<"Enter the value of the root data::";
	cin>>data;
	BTNode<int> *root = new BTNode<int>(data);
	q.push(root);

	while(!q.empty()){
		int data1;
		int data2;
		BTNode<int>* flag = q.front();
		cout<<"Enter left data for "<<flag->data<<"::";
		cin>>data1;
		if(data1 != -1)
		{
			flag->left = new BTNode<int>(data1);
			q.push(flag->left);
		}

		cout<<"Enter right data for "<<flag->data<<"::";
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
//Print the  Binary Tree Level Wise

void printBT2(BTNode<int>* root)
{
	queue<BTNode<int>*> q;
	q.push(root);
	while(!q.empty())
	{
		if(root != NULL)
		{
		BTNode<int>* temp = q.front();
		cout<<temp->data<<" ";
		if(temp->left)
		{
		q.push(temp->left);

		}
		if(temp->right)
		{
		q.push(temp->right);	
		}
		q.pop();
		}
	}
}

///Print Binary Tree in level Wise properly like 
/* 
   1
  2 3 
4 5  6 7


*/

void printBT3(BTNode<int>* root)
{
	queue<BTNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		BTNode<int>* temp = q.front();
		if(temp == NULL)
		{
			q.pop();
			if(!q.empty())
			{
			q.push(NULL);
			cout<<endl;
			}
		}
		else{
		cout<<temp->data<<" ";
		if(temp->left)
		{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
		q.pop();
		}

	}
}

//Count the nodes in a binary Tress

// int countNodes2(BTNode<int>* root)
// {
// 	if(root == NULL)
// 	{
// 		return 0;
// 	}
// 	int count = 0;

// 	if(root->left)
// 	{
// 		count = 1+countNodes2(root->left);
// 	}
// 	if(root->right)
// 	{
// 		count = count+1+countNodes2(root->right);
// 	}

// 	return count;
// }

int countNodes2(BTNode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1 + countNodes2(root->left) + countNodes2(root->right);
}

//Inorder traversal in binary Tress

void Inorder(BTNode<int>* root)
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
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

void PostOrder(BTNode<int> *root)
{
	if(root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

//Finding the height of a binart Tree

int HeightOfBinaryTree(BTNode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	int left = 1+HeightOfBinaryTree(root->left);
	int right = 1+HeightOfBinaryTree(root->right);
	int mx = max(left, right);

	return mx;
}


//Check if a tree is symmetric
// If you are allowed to pass only root as the formal parameter then create a helper function which will check for the if conditions;

bool isSymmetric(BTNode<int>* left , BTNode<int>* right)
{
	if(right == NULL && left == NULL)
	{
		return true;
	}
	if(right == NULL && left != NULL)
	{
		return false;
	}
	if(right != NULL && left == NULL)
	{
		return false;
	}
	if(right->data != left->data)
	{
		return false;
	}

	return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);


}

//Find a paritcular Node in the tree

bool findNode(BTNode<int>* root,int key)
{
	if(root == NULL)
	{
		return false;
	}
	if(root->data == key)
	{
		return true;
	}
	return findNode(root->left,key) || findNode(root->right,key);

}

//find the minimum value in the binary Tree

int minValue(BTNode<int>* root, int ans)
{
	if(root == NULL)
	{
		return ans;
	}
	return min(minValue(root->left, (ans > root->data ? root->data :ans)),minValue(root->right,(ans > root->data ? root->data :ans)));
}

//Find the maximum value in a binary Tree;
int maxValue(BTNode<int>* root, int ans)
{
	if(root == NULL)
	{
		return ans;
	}
	return max(maxValue(root->left , (ans > root->data ? ans : root->data)), maxValue(root->right, (ans > root->data ? ans : root->data)));
}

//Find the number of leaf Trees in a Binary Tree
int countNoOfLeafNodes(BTNode<int>* root)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return countNoOfLeafNodes(root->left) + countNoOfLeafNodes(root->right);
}

//Create a tree when a preorder and inorder traversals of a tree are given

BTNode<int>* createTree(int inorder[],int PreOrder[], int inS, int inE, int prS, int prE)
{	
	if(inS > inE) return NULL;
	int rootIndex = 0;
	int root = PreOrder[prS];
	BTNode<int>* temp = new BTNode<int>(root);
	for(int i=inS;i<=inE;i++)
	{
		if(inorder[i] == root)
		{
			rootIndex = i;
			break;
		}
	}
	cout<<rootIndex<<endl;
	temp->left = createTree(inorder,PreOrder,inS,rootIndex-1,prS+1,rootIndex-inS+prS);
	temp->right = createTree(inorder,PreOrder,rootIndex+1,inE,rootIndex-inS+prS+1,prE);
	return temp;
}

//Create a tree when a postorder and inorder traversals of a tree are given

BTNode<int>* createTree2(int inorder[], int PostOrder[] ,int inS, int inE, int poS, int poE)
{
	if(inS > inE) return NULL;
	int rootIndex = -1;
	int rootData = PostOrder[poE];
	BTNode<int>* temp = new BTNode<int>(rootData);
	for(int i=inS;i<=inE;i++)
	{
		if(PostOrder[i] == rootData)
		{
			rootIndex = i;
			break;
		}
	}
	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPoS = poS;
	int lPoE = lInE - lInS + lPoS;
	int rInS = rootIndex + 1;
	int rInE = inE;
	int rPoS = lPoS + 1;
	int rPoE = poE - 1;
	temp->left = createTree(inorder, PostOrder, lInS, lInE, lPoS, lPoE);
	temp->right = createTree(inorder, PostOrder, rInS, rInE, rPoS, rPoE);
	return temp;
}

//Diameter of a Binary Tree---> Diameter of a Binary Tree is the maximum distance between any two nodes
// int diameter(BTNode<int>* root)
// {
// 	if(root == NULL) return 0;
// 	int left = diameter(root->left);
// 	int right = diameter(root->right);
// 	int mx = left + right;

// 	return 1+max(left, right, mx);
// }





bool getPath(BTNode<int>* root, int key, vector<int> &v)
{
	if(root == NULL)
	{
		return false;
	}
	if(root->data == key)
	{
		v.push_back(root->data);
		return true;
	}
	bool LisPresent = getPath(root->left, key, v);
	bool RisPresent = getPath(root->right, key, v);
	if(LisPresent)
	{
		v.push_back(root->data);
		return true;

	}
	if(RisPresent){
		v.push_back(root->data);
		return true;
	}
	return false;
}






int main()
{
	// BTNode<int>* root = new BTNode<int>(4);
	// BTNode<int>* n1 = new BTNode<int>(5);
	// BTNode<int>* n2 = new BTNode<int>(6);
	// BTNode<int>* n3 = new BTNode<int>(7);
	// BTNode<int>* n4 = new BTNode<int>(8);
	// BTNode<int>* n5 = new BTNode<int>(9);
	// BTNode<int>* n6 = new BTNode<int>(10);
	// BTNode<int>* n7 = new BTNode<int>(11);
	// BTNode<int>* n8 = new BTNode<int>(12);
	// root->left = n1;
	// root->right = n2;
	// n1->left = n3;
	// n1->right = n4;
	// n2->left = n5;
	// n2->right = n6;
	// n3->left = n7;
	// n4->left = n8;
	int inorder[10],PreOrder[10], PostOrder[10];
	// BTNode<int>* root = takeInput2();
	// printBT3(root);
	// cout<<endl;
	// cout<<"The number of nodes in the binary tree is "<<countNodes2(root)+1<<endl;
	// cout<<"The inorder Traversal of the tree is ::";
	// Inorder(root);
	// cout<<endl;
	// cout<<"The pre order Traversal of the tree is ::";
	// PreOrder(root);
	// cout<<endl;
	// cout<<"The post Order Traversal of the Tree is ::";
	// PostOrder(root);
	// cout<<endl;
	// cout<<"The maximum depth or height of the Binary Tree is::";
	// cout<<HeightOfBinaryTree(root);
	// cout<<endl;
	// if(isSymmetric(root->left, root->right))
	// {
	// 	cout<<"The tree is Symmetric"<<endl;
	// }
	// else
	// {
	// 	cout<<"The tree is not Symmetric"<<endl;
	// }

	// if(findNode(root, 100))
	// {
	// 	cout<<"The data is present in the Tree"<<endl;
	// }
	// else{
	// 	cout<<"The data is not present in the Tree"<<endl;
	// }
	// cout<<"The minimum value present in the Tree is ::"<<endl;
	// cout<<minValue(root,INT_MAX)<<endl;
	// cout<<"The maximum value present in the Tree is ::"<<endl;
	// cout<<maxValue(root, INT_MIN)<<endl;

	// cout<<"The number of Leaf Nodes in the Tree::"<<countNoOfLeafNodes(root)<<endl;
	vector<int> v;
	for(int i=0;i<7;i++)
	{
		cout<<"Enter element "<<i<<" for Inorder ::";
		cin>>inorder[i];
	}
	for(int i=0;i<7;i++)
	{
		cout<<"Enter element "<<i<<" for PreOrder ::";
		cin>>PreOrder[i];
	}
	// for(int i=0;i<7;i++)
	// {
	// 		cout<<"Enter element "<<i<<" for PostOrder ::";
	// 		cin>>PostOrder[i];
	// }
	BTNode<int>* sh = createTree(inorder,PreOrder,0,6,0,6);
	printBT3(sh);
	// BTNode<int>* flag = createTree2(inorder, PostOrder, 0,6,0,6);
	// printBT3(flag);
	cout<<endl;
	getPath(sh,5,v);
	reverse(v.begin(), v.end());
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}

}