#include <bits/stdc++.h>
using namespace std;
// ! One of the algorithm to find out minimum spanning tree
class PriorityQueue{
public:
	vector<int> pq;
	void insert(int data)
	{
		if(this->pq.size() == 0)
		{
			pq.push_back(data);
		}
		else
		{
			pq.push_back(data);
			int currentIndex = pq.size() - 1;
			while(currentIndex > 0)
			{
				int temp = (currentIndex - 2)/2;
				if(pq[temp] > pq[currentIndex])
				{
					swap(pq[temp], pq[currentIndex]);
				}
				else
				{
					break;
				}
				currentIndex = temp;
			}
		}

	}
	int removeMin()
	{
		int ans = pq[0];
		swap(pq[0], pq[pq.size() - 1]);
		pq.pop_back();
		int temp = 0;
		int minIndex = temp;
		while(true)
		{
			int nextIndex1 = 2*temp + 1;
			int nextIndex2 = 2* temp + 2;
			if(nextIndex1 < pq.size() && pq[nextIndex1] < pq[minIndex] )
			{
				minIndex = nextIndex1;
			}
			if(nextIndex2 < pq.size() && pq[nextIndex2] < pq[minIndex])
			{
				minIndex = nextIndex2;
			}
			if(minIndex == temp) break;
			swap(pq[temp], pq[minIndex]);
			temp = minIndex;
		}
		return ans;
	}
	bool isEmpty()
	{
		return pq.size() == 0 ? true : false;
	}
};



class Graph{
public:
	vector<vector<int>> G;
	vector<vector<int>> MST;
	int* parent;
	int vertices;
	Graph(int T)
	{
		this->parent = new int[T];
		for(int i=0;i<T;i++)
		{
			this->parent[i] = i;
		}

	}
	void add_edges_and_vertices(int w, int u, int v)
	{
		G.push_back({w, u, v});
	}
	int find_set(int i)
	{
		if(parent[i] == i)
		{
			return i;
		}
		else
		{
			return find_set(parent[i]);
		}
	}
	void union_set(int u, int v)
	{
		parent[u] = parent[v]; 
	}
	void kruskal()
	{
		int i,  x, y;
		sort(G.begin(), G.end());

		for(int i=0;i<G.size();i++)
		{
			x = find_set(G[i][1]);
			y = find_set(G[i][2]);
			if(x != y)
			{
				this->union_set(G[i][1],G[i][2]);
				this->MST.push_back(G[i]);
			}
		}

	}
	void primsAlgo(vector<vector<int>> v, int sv)
	{
		vector <int> parent(v.size(), -1); ----> in c create a array of size of number of vertices intialized with -1
		vector <int> wt(v.size(), INT_MAX);  ---> in c create a array of size of number of vertices intialized with INT_MAX --> present in limits.h
		vector <bool> visited(v.size(), false);
		wt[0] = 0;
		PriorityQueue p;
		for(int i=0;i<v.size();i++)
		{
			p.insert(i);
		}
		while(!p.isEmpty())
		{
			int u = p.removeMin();
			visited[u] = true;
			for(int i=0;i<v.size();i++)
			{
				if(v[u][i] != -1)
				{
					if(visited[i] == false)
					{
						if(v[u][i] < wt[i])
						{
							wt[i] = v[u][i];
							parent[i] = u;
						}
					}
				}
			}
		}
		for(int i=0;i<parent.size();i++)
		{
			cout<<parent[i]<<" ";
		}

	}


	void dijkstraAlgo(vector<vector<int>> v, int sv)
	{
		vector<int> wt(v.size()-1, INT_MAX);
		vector<bool> visited(v.size()-1, false);
		wt[sv] = 0;
		for(int i=0;i<v.size()-1;i++)
		{
			int u;
			int min = INT_MAX;
			for(int j=0;j<v.size(); j++)
			{
				if(wt[j] < min && visited[j] == false)
				{
					min = wt[j];
					u = j;
				}
			}
			visited[u] = true;
			for(int k=0;k<v.size();k++)
			{
				if(v[u][k] != -1)
				{
					if(visited[k] == false)
					{
						if(wt[u] + v[u][k] < wt[k])
						{
							wt[k] = wt[u] + v[u][k];
						}
					}
				}

			}

		}
		for(int i=0;i<v.size();i++)
		{
			cout<<wt[i]<<" ";
		}
	}
	void prims()
	{
		vector<vector<int>> v(5, vector<int>(5,-1));
		for(int i=0;i<5;i++)
		{
			int sv, ev;
			int data;
			cin>>sv>>ev;
			cout<<"Enter data::";
			cin>>data;

			v[sv][ev] = data;
			v[ev][sv] = data;
		}
		primsAlgo(v, 0);
	}

 	
 	 void dijkstra()
 	 {
 	 	vector<vector<int>> v(5, vector<int>(5,-1));
		for(int i=0;i<5;i++)
		{
			int sv, ev;
			int data;
			cin>>sv>>ev;
			cout<<"Enter data::";
			cin>>data;

			v[sv][ev] = data;
			v[ev][sv] = data;
		}
 	 	dijkstraAlgo(v, 0);
 	 }

};

int main()
{
	Graph g(4);
	// g.add_edges_and_vertices(1,1,2);
	// g.add_edges_and_vertices(2,2,3);
	// g.add_edges_and_vertices(3,4,3);
	// g.add_edges_and_vertices(4,1,4);
	// g.add_edges_and_vertices(5,2,4);
	// g.kruskal();
	// for(int i=0;i<g.MST.size();i++)
	// {
	// 	cout<<g.MST[i][0]<<" ";
	// 	cout<<g.MST[i][1]<<" ";
	// 	cout<<g.MST[i][2]<<" ";
	// 	cout<<endl;
	// }
	// g.prims();
	g.dijkstra();

}