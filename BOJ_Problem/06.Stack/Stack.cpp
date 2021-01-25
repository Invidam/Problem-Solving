#include <iostream>
#include <cstdlib>
#include <stack>
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
class Stack{
public:
	int size;
	ListNode<T>* tail; // head 역할
	
	Stack<T>() : size(0), tail(nullptr) {}

	~Stack<T>(){
		ListNode<T> *t1 = tail, *t2;
		while(t1 != nullptr){
			t2 =t1->next;
			delete t1;
			t1 = t2;
		}
	}
	void push(T value){
		tail = new ListNode<T>(value,tail);
		size++;
	}
	
	T top(){
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
			ListNode<int> *temp = tail->next;
			delete tail;
			tail = temp;
			size--;
		}
		catch(out_of_range& e) {
			cerr << "UnderflowException";
			exit(2);
		}
		
	}
};

template<typename T>
class LinkedList{
	
public:
	int size;
	ListNode<T>* head;
	
	LinkedList<T>() : size(0), head(nullptr) {}
	
	~LinkedList<T>(){
		ListNode<T> *t1 = head, *t2;
		while(t1 != nullptr) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}
	void insert(int k, T value) {
		try	{
			if(k > size || k < 0)
				throw out_of_range("InvalidIndexException");
			
			if(k == 0) {
				head = new ListNode<T>(value,head);
			}
			else {
				ListNode<T> *dest = head;
				for(int i=0;i<k-1;i++) {
					dest = dest->next;
				}
				dest->next = new ListNode<T>(value,dest->next);
			}
			size++;
		}
		catch(out_of_range &e)	{
			cerr << "InvalidIndexException";
			exit(1);
		}
	}
	void erase(int k) {
		try	{
			if(k > size || k < 0)
				throw out_of_range("InvalidIndexException");
			
			if(k == 0) {
				ListNode<T> *temp = head->next;
				delete head;
				head = temp;
			}
			else {
				ListNode<T> *dest = head,*temp;
				for(int i=0;i<k-1;i++) {
					dest = dest->next;
				}
				//de -> de ne(want to del) -> de ne ne
				temp = dest->next->next;
				delete dest->next;
				dest->next = temp;
			}
			size--;
		}
		catch(out_of_range &e)	{
			cerr << "InvalidIndexException";
			exit(2);
		}
	}
	
	int search(T value) {
		ListNode<T> *temp = head;
		for(int i=0;i<size;i++) {
			if(temp->value == value)
				return i;
			temp = temp->next;	
		}
		return -1;
	}
};

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
template <typename T>
ostream& operator<<(ostream& o, stack<T>& s) {
	o << "top [";
	while(!s.empty()) {
		o << s.top();
		if(s.size() != 1)
			o <<", ";
		s.pop();
	}
	o << "]bottom\n";
	return o;
		
}
template <typename T>
void showstack(stack<T> &s) {
	cout <<"top[";
	while(!s.empty()){
		cout << s.top();
		if(s.size() != 1) cout<<", ";
		s.pop();
	}
	cout <<"]bottom\n";
}
int main() {
	
	stack<int> s;
	s.
	showstack(s);
	cout << s;
	showstack(s);
	//cout << s.top() <<"??\n";
	showstack(s);
	
	
}