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
class stack
{
	public:
	
	listNode<T> *tail;
	int size;
	
	stack<T>() : size(0), tail(nullptr) {}
	
	int empty()
	{
		return (size == 0);
	}
	int top()
	{
		if(size == 0)
			return -1;
		return tail->element;
	}
	void push(T newElement)
	{
		if(size == 0)
			tail = new listNode<T>(newElement,nullptr,nullptr);
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
		listNode<T> *newTail = tail->next;
		delete tail;
		tail = newTail;
		
		if(tail != nullptr)
			tail->prev = nullptr;
		size--;
	}
	
	

};

template <typename T>
void print_stack(stack<T>& s)
{
	int ssize = s.size;
	listNode<T> *temp = s.tail;
	cout <<"top[";
	
	for(int i=0;i<ssize;++i)
	{
		cout << temp->element;
		temp = temp->next;
		if(i !=ssize -1)
			cout << ", ";
	}
	cout <<"]bottom\n";
}


using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	stack<int> s;
	
	//insert testcase
	s.push(1);
	s.push(2);
	s.push(3);
	
	//print testcase
	print_stack(s);
	
	
	//delete testcase
	s.pop();
	print_stack(s);
	
	
	//front testcase
	cout << s.top() << '\n';
	
	//empty testcase;
	cout << s.empty() << '\n';
	
	while(!s.empty())
	{
		cout << s.top() << '\n';
		s.pop();
	}
	
}