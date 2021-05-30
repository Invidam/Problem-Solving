#include <iostream>
#include <cstdlib>
#include <deque>
using namespace std;


template<typename T>
class ListNode{
	
public:
	T value;
	ListNode<T>* next;
	ListNode<T>* prev;
	
	ListNode<T>() : next(nullptr) , prev(nullptr){}
	ListNode<T>(T v1, ListNode<T>* n1,ListNode<T>* n2) : value(v1) , next(n1),prev(n2) {}	
};

template<typename T>
class Deque{
public:
	int size;
	ListNode<T> *head, *tail; // head 역할
	
	Deque<T>() : size(0), head(nullptr), tail(nullptr) {}

	~Deque<T>(){
		ListNode<T> *t1 = head, *t2;
		while(t1 != nullptr)
		{
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}
	void push_back(T value){
		if(size == 0)
			head = tail = new ListNode<T>(value,nullptr,nullptr);
		else {
			tail->next = new ListNode<T>(value,nullptr,tail);
			tail = tail->next;
		}
		size++;
	}
	void push_front(T value){
		if(size == 0)
			head = tail = new ListNode<T>(value,nullptr);
		else {
			ListNode<T> *t1 = head;
			head = new ListNode<T>(value,t1,nullptr);
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
	
	void pop_front(){
		try{
			if(size ==0) 
				throw out_of_range("UnderflowException");
			ListNode<int> *temp = head->next;
			delete head;
			head = temp;
			head->prev = nullptr;
			if(head == nullptr)
				tail = nullptr;
			size--;
		}
		catch(out_of_range& e) {
			cerr << "UnderflowException";
			exit(2);
		}
		
	}
	void pop_back(){
		try{
			if(size ==0) 
				throw out_of_range("UnderflowException");
			ListNode<int> *temp = tail->prev;
			delete tail;
			tail = temp;
			tail->next = nullptr;
			if(tail == nullptr)
				head = nullptr;
			size--;
		}
		catch(out_of_range& e) {
			cerr << "UnderflowException";
			exit(2);
		}
		
	}
};

template<typename T>
ostream& operator<<(ostream& o,deque<T> dq)
{
	o << "front [";
	for(auto& elem : dq)
	{
		o << elem;
		if(elem != dq.back())
			o << ", ";
	}
	
	
	o << "]rear\n";
	return o;
}
/*
template <typename T>
ostream& operator<<(ostream& o,const Deque<T>& DQ)
{
	ListNode<T> *temp = DQ.head;
	o <<"fornt[";
	for(int i=0;i<DQ.size;i++)
	{
		o << temp->value;
		temp = temp->next;
		if(i != DQ.size - 1)
			o <<", ";
	}
	o << "]rear\n";
	return o;
}

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

*/
int main() {
	deque<int> dq;
	dq.push_back(1);
	cout << dq;
	dq.push_back(2);
	cout << dq;
	dq.push_back(3);
	cout << dq;
	dq.push_front(5);
	cout << dq;
	//dequ
}