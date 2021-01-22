#include <iostream>
#include <list>
using namespace std;
//acmicpc.net/problem/1158

/*
문제명: 요세푸스 문제
TL: 2s
ML: 256MB



Good
1. 
2. 
3. 

Bad
1. erase 함수등의 시간복잡도를 잘 몰라 조금 헷갈리게 코드를 작성하였다. -> erase : O(K)이다.
2. erase함수 사용시 itr = erase(itr) or erase(itr++) 로 작성해야 한다.
3. 코드 작성 시 문제가 생기더라도 내적으로든 외적으로든 해결하려고 노력해야 한다.
4. 너무 몰입하지 말자.

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: m
TS: 116ms
MS: 2300KB
*/




int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	list<int> l;
    
	for(int i=0;i<N;i++)
		l.push_back(i+1);
	
	list<int>::iterator itr = l.begin();
	
	cout <<"<";
	while(l.size() != 1) {
		for(int i=0;i<K-1;i++) {
			if(itr == l.end())
				itr = l.begin();
			itr++;
			if(itr == l.end())
				itr = l.begin();
		}
		cout << *itr << ", ";
		itr = l.erase(itr);
	}
	
	cout << *itr << ">";
	
	return 0;
}

/*
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
	ListNode<T>* erase(int k) {
		try	{
			if(k > size || k < 0)
				throw out_of_range("InvalidIndexException");
			
			if(k == 0) {
				ListNode<T> *temp = head->next;
				delete head;
				head = temp;
				size--;
				return head;
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
				size--;
				return temp;
			}
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

int N,K,arr[5001],idx,arr_idx,cnt = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	LinkedList<int> l;
	int cnt = 0,idx = 0;
	cin >> N >> K;
	
	for(int i=0;i<N;i++)
		l.insert(i,i+1);
	
	ListNode<int>* itr = l.head;
	cout <<"<";
	if(K == 1) {
		for(int i=0;i<N-1;i++)
			cout << i+1 <<", ";
		cout << N << ">";
		return 0;
	}
	
	while(l.size != 1) {
		cnt++;
		if(cnt != 0 &&cnt % (K) == 0) {
			cout << itr->value << ", ";
			itr = l.erase(idx);
			cnt++;
			if(itr == nullptr) {
				cnt--;
				itr = l.head;
				idx = 0;
				continue;
			}
		}
		if(itr->next == nullptr) {
			itr = l.head;
			idx = 0;
		}
		else {
			itr = itr->next;
			idx++;
		}
	}
	cout <<itr->value <<">";
	
}

2300 128
*/