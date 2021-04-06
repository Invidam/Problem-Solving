#include <iostream>

using namespace std;

template <typename T>
class listNode
{
	public:
	
	listNode<T> *prev,*next;
	T element;
	
	listNode() {}
	listNode(T element) : element(element) {}
	listNode(T element, listNode<T> *prev, listNode<T> *next) : element(element) , prev(prev), next(next) {}
};


template <typename T>
class deque
{
	public:
	
	listNode<T> *head,*tail;
	int size;
	
	deque<T>() : size(0), head(nullptr), tail(nullptr) {}
	
	int empty()
	{
		return (size == 0);
	}
	int front()
	{
		if(size == 0)
			return -1;
		return head->element;
	}
	int rear()
	{
		if(!tail)
			return -1;
		return tail->element;
	}
	void push_back(T newElement)
	{
		if(!head)
			head = tail = new listNode<T>(newElement,nullptr,nullptr);
		else
		{
			tail->prev = new listNode<T>(newElement,nullptr,tail);
			tail = tail->prev;
		}
		size++;
	}
	void push_front(T newElement)
	{
		if(!head)
			head = tail = new listNode<T>(newElement,nullptr,nullptr);
		else
		{
			head->next = new listNode<T>(newElement,head,nullptr);
			head = head->next;
		}
		size++;
	}
	
	void pop_back()
	{
		if(size == 0) return;
		listNode<T> *newTail = tail->next;
		delete tail;
		tail = newTail;
		if(tail == nullptr)
			head = nullptr;
		else 
			tail->prev = nullptr;
		size--;
	}
	void pop_front()
	{
		if(size == 0) return;
		listNode<T> *newHead = head->prev;
		delete head;
		head = newHead;
		if(head == nullptr)
			tail = nullptr;
		else 
			head->next = nullptr;
		size--;
	}
	
	

};

template <typename T>
void print_deque(deque<T>& dq)
{
	int size = dq.size;
	listNode<T> *temp = dq.head;
	cout <<"front[";
	
	for(int i=0;i<size;++i)
	{
		cout << temp->element;
		temp = temp->prev;
		if(i !=size -1)
			cout << ", ";
	}
	cout <<"]rear\n";
}

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	deque<int> dq;
	
	//insert testcase
	dq.push_front(2);
	dq.push_back(3);
	dq.push_front(1);
	
	//print testcase
	print_deque(dq);
	
	
	//delete testcase
	dq.pop_back();
	dq.pop_front();
	print_deque(dq);
	
	
	//front testcase
	cout << dq.front() << '\n';
	
	//empty testcase;
	cout << dq.empty() << '\n';
	
	while(!dq.empty())
	{
		cout << dq.front() << '\n';
		dq.pop_front();
	}
	
}