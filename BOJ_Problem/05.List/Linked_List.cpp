#include <iostream>
#include <cstdlib>
using namespace std;

class InvalidIndexException {
	
};
template<typename T>
class ListNode{
	
public:
	T value;
	ListNode<T>* next;
	
	ListNode<T>() : next(nullptr){}
	ListNode<T>(T v1, ListNode<T>* n1) : value(v1) , next(n1) {}	
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
ostream& operator<<(ostream& o, LinkedList<T>& l) {
	ListNode<T> *temp =l.head;
	o << '[';
	for(int i=0;i<l.size;i++) {
		o << temp->value;
		temp = temp->next;
		if(i != l.size -1) {
			o << ", ";
		}
	}
	o << ']';
	return o;
		
}

int main() {
	
	LinkedList<int> LL;
	LL.insert(0,1);
	LL.insert(1,5);
	LL.insert(1,7);
	cout << LL;
	
}