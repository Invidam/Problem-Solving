#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 20090711, BEGINNING_SEED = 1983;

struct RNG
{
	int seed,a, b;
	RNG(int a,int b): a(a), b(b), seed(BEGINNING_SEED) {}
	
	int next()
	{
		int ret = seed;
		seed = (seed * (long)a + b)  % MOD;

		return ret;
	}
};

int getMedianSum(int N,int a,int b)
{
	RNG rng(a,b);
	priority_queue<int,vector<int>,less<int>> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;
	int ret = 0;
	
	while(N--)
	{
		if(maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		
		if(!minHeap.empty())
		{
			a = maxHeap.top();
			b = minHeap.top();

			if(a > b)
			{
				maxHeap.pop();
				minHeap.pop();

				maxHeap.push(b);
				minHeap.push(a);
			}
		}
		ret += maxHeap.top();
		ret %= MOD;
	}
	
	return ret;
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N,a,b;
	
	cin >> TC;
	
	while(TC--)
	{
		cin >> N >> a >> b;
		cout << getMedianSum(N,a,b) << '\n';
	}
}

/*

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef int keyType;
struct Node
{
	keyType key;
	
	int priority, size;
	
	Node *left, *right;
	
	Node(const keyType& _key) : key(_key),priority(rand()), size(1) , left(NULL) , right(NULL) {}
	
	void calcSize()
	{
		size = 1;
		if(left) size += left->size;
		if(right) size += right->size;
	}
	
	void setLeft(Node* newNode)
	{
		left = newNode;
		calcSize();
	}
	
	void setRight(Node* newNode)
	{
		right = newNode;
		calcSize();
	}
};


typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root,keyType key)
{
	if(root == NULL) return NodePair(NULL,NULL);
	
	if(root->key < key)
	{
		NodePair rs = split(root->right,key);
		root->setRight(rs.first);
		return NodePair(root,rs.second);
	}
	else
	{
		NodePair ls = split(root->left,key);
		root->setLeft(ls.second);
		return NodePair(ls.first,root);
	}
}

Node* _insert(Node* root, Node* node)
{
	if(root == NULL) return node;
	
	if(root->priority < node->priority)
	{
		NodePair child = split(root,node->key);
		node->setLeft(child.first);
		node->setRight(child.second);
		
		return node;
	}
	else if(root->key > node->key)
		root->setLeft(_insert(root->left,node));
	else
		root->setRight(_insert(root->right,node));
	
	return root;
}

Node* insert(Node* root, keyType newKey)
{
	return root = _insert(root,new Node(newKey));
}

Node* merge(Node* a, Node* b)
{
	if(a== NULL) return b;
	if(b == NULL) return a;
	
	if(a->priority < b->priority)
	{
		b->setLeft(merge(a,b->left));
		return b;
	}
	else
	{
		a->setRight(merge(a->right,b));
		return a;
	}
}

Node* erase(Node* root,keyType key)
{
	if(root == NULL) return root;
	if(root->key == key) 
	{
		root = merge(root->left,root->right);
	}
	else if(root->key > key)
		root->setLeft(erase(root->left,key));
	else 
		root->setRight(erase(root->right,key));
	
	return root;
}

Node* kth(Node* root,int k)
{
	if(k > root->size) return new Node(-1);
	int leftSize = 0;
	if(root->left != NULL) leftSize = root->left->size;
	
	if(k ==leftSize +1) return root;
	else if(k <= leftSize) return kth(root->left,k);
	return kth(root->right,k - leftSize - 1);
}

int countLessThan(Node* root, keyType key)
{
	if(root == NULL) return 0;
	
	if(root->key >= key)
		return countLessThan(root->left,key);
	
	int ls = ((root->left) ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right,key);
}

const int MOD = 20090711, BEGINNING_SEED = 1983;

struct RNG
{
	int seed,a, b;
	RNG(int a,int b): a(a), b(b), seed(BEGINNING_SEED) {}
	
	int next()
	{
		int ret = seed;
		seed = (seed * (long)a + b)  % MOD;

		return ret;
	}
};

int getMedianSum(int N,int a,int b)
{
	RNG rng(a,b);
	Node* root = NULL;
	int sum = 0;
	
	for(int i=0;i<N;++i)
	{
		root = insert(root,rng.next());
		int med = (i)/2 + 1;
		
		sum += kth(root,med)->key;
		sum %= MOD;
	}
	
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N,a,b;
	
	cin >> TC;
	
	while(TC--)
	{
		cin >> N >> a >> b;
		cout << getMedianSum(N,a,b) << '\n';
	}
	
	
}
*/

