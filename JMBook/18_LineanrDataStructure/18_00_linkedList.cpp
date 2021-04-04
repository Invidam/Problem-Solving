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
class linkedList
{
	public:
	
	int size;
	listNode<T> *head;
	linkedList<T>() : size(0), head() {}
	
	~linkedList<T>(){
		listNode<T> *t1 = head, *t2;
		while(t1 != nullptr) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}	
	
	void insertNode(int idx,T element)
	{
		if(idx < 0 || idx > size)
		{
			cout << "error in insert\n";
			return;
		}
		if(idx == 0)
		{
			if(head)
			{
				listNode<T> *headNext = head;

				head = new listNode<T>(element,nullptr,headNext);
				head->next->prev = head;
			}
			else
			{
				head = new listNode<T>(element,nullptr,nullptr);
			}
		}
		else
		{
			listNode<T> *dest = head;
			
			for(int i=0;i<idx-1;++i)
			{
				dest = dest->next;
			}
			dest->next = new listNode<T>(element,dest->next,nullptr);
		}
		size++;
	}
	
	void deleteNode(int idx)
	{
		if(idx < 0 || idx > size)
		{
			cout << "error in delete\n";
			return;
		}
		if(idx == 0)
		{
			listNode<T> *newHead = head->next;
			if(head)
				delete head;
			head = newHead;
		}
		else
		{
			listNode<T> *dest = head, *toNext;
			for(int i=0;i<idx-1;++i)
			{
				dest = dest->next;
			}
			
			toNext = dest->next->next;
			delete dest->next;
			
			dest->next = toNext;
			toNext->prev= dest;
		}
		size--;
	}
	
	void printLinkedList()
	{
		cout << *this;
	}
	
	T search(int element)
	{
		listNode<T> *toFind = head;
		for(int i=0;i<size;++i)
		{
			if(toFind->element == element)
				return i;
			toFind = toFind->next;
		}
		return -1;
	}
	
	
};

template <typename T>
ostream& operator<<(ostream& o,linkedList<T>& l)
{
	o <<'[';
	
	listNode<T> *itr = l.head;
	
	for(int i=0;i<l.size;++i)
	{
		o << itr->element;
		if(i != l.size -1) o << ", ";
		
		itr = itr->next;
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
	
	linkedList<int> ll;
	g
	//insert testcase
	ll.insertNode(0,1);
	ll.insertNode(1,2);
	ll.insertNode(2,3);
	
	//print testcase
	ll.printLinkedList();
	cout << ll;
	
	ll.insertNode(0,5);
	ll.printLinkedList();
	
	//delete testcase
	ll.deleteNode(1);
	ll.printLinkedList();
	ll.deleteNode(0);
	
	//search testcase
	cout << "search idx: " << ll.search(3) << '\n';
	cout << "search idx: " << ll.search(1) << '\n';
	
	cout << ll;
}