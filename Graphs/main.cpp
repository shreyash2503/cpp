#include <bits/stdc++.h>
using namespace std;

// ! Implementation of Graph using Adjacency Matrix 
// ! We first ask the user number of vertices and number of edges in the graph and then run a for loop for each instance fo the loop we we will ask the connection between 
// ! the eges and make them correspondingly true in the matrix 
// ! Implementation of DFS-->Depth First Search

void DFS(vector<vector<int>> v, int sv, vector<bool>& visited)
{
	stack<int> s;
	int size = v.size();
	s.push(sv);
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		for(int i=0;i<size;i++)
		{
			if(v[top][i]==true && !visited[i])
			{
				s.push(i);
			}
		}
		if(!visited[top])
		{
			cout<<top<<" ";
			visited[top] = true;
		}
	}
	for(int i=0;i<visited.size();i++) // ----> For Disconnected graphs
	{
		if(!visited[i])
		{
			DFS(v, i, visited);
		}
	}
}
// ! Implementation of BFS---> Breadth First Search
void BFS(vector<vector<int>> v, int sv, vector<bool>& visited)
{
	queue<int> q;
	int size = v.size();
	q.push(sv);
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		
		for(int i=0;i<size;i++)
		{
			if(v[front][i]==1 && !visited[i])
			{
				q.push(i);
			}
		}
		if(!visited[front])
		{
			cout<<front<<" ";
			visited[front] = true;
		}

	}
	for(int i=0;i<v.size();i++)
	{
		if(!visited[i])
		{
			BFS(v, i, visited);
		}
	}
}


int main()
{
	int vertices, edges;
	cout<<"Enter the number of vertices in the Graph::";
	cin>>vertices;
	cout<<"Enter the number of edges in the Graph::";
	cin>>edges;
	vector<bool> visited1(vertices, false);
	vector<bool> visited2(vertices, false);
	vector<vector<int>> v(vertices, vector<int>(vertices,0));
	for(int i=0;i<edges;i++)
	{
		int fe,se;
		cin>>fe>>se;
		v[fe][se] = 1;
		v[se][fe] = 1;
	}
	bool contd = true;
	do{
		cout<<endl;
		int option;
		cout<<"Choose from the below option::"<<endl;
		cout<<"1. BFS"<<endl;
		cout<<"2. DFS"<<endl;
		cin>>option;
		if(option == 1)
		{
			BFS(v, 0, visited1);
			cout<<endl;
		}
		else if(option == 2)
		{
			DFS(v, 0, visited2);
			cout<<endl;
		}
		else
		{
			contd = false;
			exit(0);
		}	
		}
	while(contd);


}
