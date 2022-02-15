#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class heap
{
	public:
	
	vector<int> heap;
	
	
	void push(int newValue)
	{	
		heap.push_back(newValue);
		int i = heap.size() -1;
		while(i != 0 && heap[(i-1)/2] < heap[i])
		{
			const int& next = (i-1)/2;
			swap(heap[next],heap[i]);
			i = next;
		}
	}

	void pop()
	{
		heap[0] = heap.back();
		heap.pop_back();
		int i=0;
		while(1)
		{
			const int& left= 2*(i+1) -1 , right = 2*(i+1);
			if(heap.size()-1 < left)
				break;
			
			int next;
			
			if(heap.size() -1 == left)
				next = left;
			else 
				next = heap[left] > heap[right] ? left : right;
			
			if(heap[i] > heap[next])
				break;
			
			swap(heap[i],heap[next]);
			i = next;
		}
	}
	int top()
	{
		return heap[0];
	}

	void print()
	{
		for(int i=0;i<heap.size();++i)
			cout << heap[i] << " ";
		cout <<'\n';
	}


};


void push_heap(vector<int>& heap,int newValue)
{
	heap.push_back(newValue);
	int i = heap.size() -1;
	while(i != 0 && heap[(i-1)/2] < heap[i])
	{
		const int& next = (i-1)/2;
		swap(heap[next],heap[i]);
		i = next;
	}
}

void pop_heap(vector<int>& heap)
{
	heap[0] = heap.back();
	heap.pop_back();
	int i=0;
	while(1)
	{
		const int& next1 = 2*(i+1) -1 , next2 = 2*(i+1);
		int next;
		if(heap.size()-1 < next1)
			break;
		
		if(heap.size()-1 == next1 || heap[next1] >= heap[next2])
		{
			next = next1;
		}
		else
		{
			next = next2;
		}
		
		swap(heap[i],heap[next]);
		i = next;
		

		
	}
}

int top_heap(vector<int>& heap)
{
	return heap[0];
}

void print_heap(vector<int>& heap)
{
	for(int i=0;i<heap.size();++i)
		cout << heap[i] << " ";
	cout <<'\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	heap h;
	
	for(int i=0;i<=10;++i)
	{
		h.push(i);
		h.print();
	}
	
	cout << "top: " << h.top() << '\n';
	for(int i=0;i<=3;++i)
	{
		h.pop();
		h.print();
	}
	
}