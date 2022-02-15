#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;


template<typename T>
class ListNode{
	
public:
	T value;
	ListNode<T>* next;
	
	ListNode<T>() : next(nullptr){}
	ListNode<T>(T v1, ListNode<T>* n1) : value(v1) , next(n1) {}	
};

template<typename T>
class Queue{
public:
	int size;
	ListNode<T> *head, *tail; // head 역할
	
	Queue<T>() : size(0), head(nullptr), tail(nullptr) {}

	~Queue<T>(){
		ListNode<T> *t1 = head, *t2;
		while(t1 != nullptr)
		{
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}
	void push(T value){
		if(size == 0)
			head = tail = new ListNode<T>(value,nullptr);
		else {
			tail->next = new ListNode<T>(value,nullptr);
			tail = tail->next;
		}
		size++;
	}
	
	T front(){
		try{
			if(size ==0) 
				throw out_of_range("UnderflowException");
			return head->value;
		}
		catch(out_of_range& e) {
			cerr << "UnderflowException";
			exit(1);
		}
	}
	T rear(){
		try{
			if(size ==0) 
				throw out_of_range("UnderflowException");
			return tail->value;
		}
		catch(out_of_range& e) {
			cerr << "UnderflowException";
			exit(1);
		}
	}
	
	void pop(){
		try{
			if(size ==0) 
				throw out_of_range("UnderflowException");
			ListNode<int> *temp = head->next;
			delete head;
			head = temp;
			if(head == nullptr)
				tail = nullptr;
			size--;
		}
		catch(out_of_range& e) {
			cerr << "UnderflowException";
			exit(2);
		}
		
	}
};
template <typename T>
ostream& operator<<(ostream& o,const Queue<T>& QQ)
{
	ListNode<T> *temp = QQ.head;
	o <<"fornt[";
	for(int i=0;i<QQ.size;i++)
	{
		o << temp->value;
		temp = temp->next;
		if(i != QQ.size - 1)
			o <<", ";
	}
	o << "]rear\n";
	return o;
}
/*

template <typename T>
ostream& operator<<(ostream& o, Stack<T>& S) {
	ListNode<T> *temp = S.tail;
	o << "top [";
	for(int i=0;i<S.size;i++) {
		o << temp->value;
		temp = temp->next;
		if(i != S.size -1)
			o <<", ";
	}
			o << "]bottom";
	return o;
		
}
*/
template<typename T>
ostream& operator<<(ostream& o,queue<T> q)
{
	o << "front [";
	while(!q.empty())
	{
		o << q.front();
		q.pop();
		if(q.size() != 0)
			o <<", ";
	}
	o << "]rear\n";
	return o;
}
int main() {
	
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.front() << '\n';
	cout << q.rear() << '\n';
	cout << q;
	q.pop();
	q.push(4);
	cout << q.front() << '\n';
	cout << q.rear() << '\n';
	q.pop();
	q.pop();
	q.pop();
	cout << q;
	
	queue<int> qq;
	qq.push(1);
	qq.push(2);
	cout << qq.front();
	cout << qq.back();
	cout << qq;
	qq.push(3);
	qq.pop();
	cout << qq.front();
	cout << qq.back();
	cout << qq;
}