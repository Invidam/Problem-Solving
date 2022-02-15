#include <iostream>
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

void print_node(Node* node)
{
	cout << node->key << "(" << node->priority << ")\n";
}
void print_tree(Node* root, int depth)
{
	if(root == NULL) return;
	cout << "==" << depth << "==\n";
	print_node(root);
	print_tree(root->left, depth + 1);
	print_tree(root->right,depth +1);
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
void print_tree(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	print_tree(root->left);
	print_node(root);
	print_tree(root->right);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Node* root = NULL;
	
	//insert TestCase
	for(int i=1;i<=3;++i)
		root = insert(root,i);
	
	print_tree(root);
	
// 	//cLT TestCase
// 	cout << "clt" << countLessThan(root,6) << '\n';
	
// 	//erase TestCase
// 	root = erase(root,4);
// 	root = erase(root,5);
// 	print_tree(root,0);
	
	
// 	//kth TestCase
// 	print_node(kth(root,4));
}