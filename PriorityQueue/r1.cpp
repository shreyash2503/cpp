# include <bits/stdc++.h>
using namespace std;

class PriorityQueue{
public:
	vector <int> heap

	int parent(int index){
		return index - 1 / 2;
	}

	int leftChild(int index){
		return (2 * index + 1)
	}
	int rightChild(int index){
		return (2 * index + 2);
	}

	void heapifyUp(int index){
		int current = index;
		while(current > 0 && heap[parent(current)] > heap[current]){
			swap(heap[parent(current)], heap[current]);
			current = parent(current);
		}
	}

	void insert(int value){
		heap.push_back(value);
		heapifyUp(v.size() - 1);
	}

	void heapifyDown(int index){
		int left = leftChild(index);
		int right = rightChild(index);
		int smallest = index;

		if(left < heap.size() && heap[left] < heap[smallest]){
			smallest = left;
		}
		if(right < heap.size() && heap[right] < heap[smallest]){
			smallest = right;
		}

		if(smallest != index){
			swap(heap[smallest], heap[index]);
			heapifyDown(smallest);

		}
	}

	int getMin(){
		int minElement = heap[0];
		int value = heap.pop_back();
		heap[0] = value;
		heapifyDown(0);

		return minElement

	}
}