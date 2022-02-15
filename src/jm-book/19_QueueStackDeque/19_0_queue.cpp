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
class queue
{
	public:
	
	listNode<T> *head,*tail;
	int size;
	
	queue<T>() : size(0), head(nullptr), tail(nullptr) {}
	
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
	void push(T newElement)
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
	
	void pop()
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
void print_queue(queue<T>& q)
{
	int qsize = q.size;
	listNode<T> *temp = q.head;
	cout <<"front[";
	
	for(int i=0;i<qsize;++i)
	{
		cout << temp->element;
		temp = temp->prev;
		if(i !=qsize -1)
			cout << ", ";
	}
	cout <<"]rear\n";
}
template <typename T>
ostream& operator<<(ostream& o,queue<T>& q)
{
	int qsize = q.size;
	o <<'[';
	
	for(int i=0;i<qsize;++i)
	{
		o << q.front();
		if(i !=qsize -1)
			o << ", ";
		q.pop();
	}
	o <<"]\n";
	
	return o;
}

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	queue<int> q;
	
	//insert testcase
	q.push(1);
	q.push(2);
	q.push(3);
	
	//print testcase
	print_queue(q);
	
	
	//delete testcase
	q.pop();
	print_queue(q);
	
	
	//front testcase
	cout << q.front() << '\n';
	
	//empty testcase;
	cout << q.empty() << '\n';
	
	while(!q.empty())
	{
		cout << q.front() << '\n';
		q.pop();
	}
	
}