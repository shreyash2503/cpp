#include <bits/stdc++.h>
using namespace std;

// ! Implementation of Priority Queue 
// ! Ways to implement Priority Queue 
// ! Heaps
// ! Heap is nothing but a complete binary Tree also called as CBT 
// ! We will be using vector or array to implement the Heap Data Structure 
// ! It has heap order property --> Min Heap an Max Heap 
// ! Complete Binary Tree--> All levels are completely filled except the last level 
// ! Heaps can be of two types Min Heap  and Max Heap
// ! In Min Heap root < left_child and root<right_child while vice versa in Max Heap

class PriorityQueue
{
	vector <int> pq;
public:
	PriorityQueue()
	{

	}
	bool isEmpty()
	{
		return pq.size() == 0 ? true : false;
	}

	// Return the size of our priority queue or total number of elements present
	int getSize()
	{
		return pq.size();
	}
	int getMin()
	{
		return pq.size() == 0 ? -1 : pq[0];
	}
	void insert(int data)
	{
		if(pq.size() == 0)
		{
			pq.push_back(data);
		}
		else
		{
			pq.push_back(data);
			int nextIndex = pq.size() - 1;
			int currentIndex = nextIndex;
			if(nextIndex % 2 == 0)
			{
				// ! Performing Up Heapify to make the Heap a min Heap
				while(currentIndex > 0)
				{
					int parentIndex = (currentIndex - 2)/2;
					if(pq[parentIndex] > pq[currentIndex])
					{
						swap(pq[parentIndex], pq[currentIndex]);
						currentIndex = parentIndex;
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				while(currentIndex > 0)
				{
					int parentIndex = (currentIndex - 1)/2;
					if(pq[parentIndex] > pq[currentIndex])
					{
						swap(pq[parentIndex], pq[currentIndex]);
						currentIndex = parentIndex;
					}
					else
					{
						break;
					}
				}

			}

		}
	}
	int removeMin()
	{
		if(this->isEmpty()) return 0;
		int ans = pq[0];
		int currentIndex = pq.size() - 1;
		swap(this->pq[currentIndex], this->pq[0]);
		pq.pop_back();
		int temp = 0;
		int minimumIndex = temp;
		while(true)
		{
			int nextIndex1 = 2*temp + 1;
			int nextIndex2 = 2*temp + 2;
			if(nextIndex1 < pq.size() && pq[nextIndex1] < pq[minimumIndex])
			{
				minimumIndex = nextIndex1;
			}
			if(nextIndex2 < pq.size() && pq[nextIndex2] < pq[minimumIndex])
			{
				minimumIndex = nextIndex2;
			}
			if(minimumIndex == temp) break;
			swap(pq[temp], pq[minimumIndex]);
			temp = minimumIndex;
		}
		return ans;
	}

	void print()
	{
		for(int i=0;i<this->pq.size();i++)
		{
			cout<<pq[i]<<" ";
		}
	}
};



int main()
{
	PriorityQueue p;
	p.insert(2);
	p.insert(3);
	p.insert(4);
	p.insert(1);
	p.print();
	cout<<endl;
	cout<<p.removeMin()<<endl;
	cout<<p.removeMin()<<endl;
	p.print();


}
