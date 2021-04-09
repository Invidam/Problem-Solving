#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> slice(const vector<int>& v,int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}
int findRoot(const vector<int>& v ,int root)
{
	for(int i=0;i<v.size();++i)
		if(root == v[i]) return i;
	return -1;
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	if(preorder.empty()) return;
	const int N = preorder.size();
	
	const int root = preorder[0];
	
	const int L = findRoot(inorder,root);
	//const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	printPostOrder(slice(preorder,1,L+1),slice(inorder,0,L));
	printPostOrder(slice(preorder,L+1,N),slice(inorder,L+1,N));
	
	cout << root << " ";
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		int N;
		cin >> N;
		vector<int> preorder(N), inorder(N);
		
		for(int i=0;i<N;++i)
			cin >> preorder[i];
		
		for(int i=0;i<N;++i)
			cin >> inorder[i];
		
		printPostOrder(preorder,inorder);
		
	}
	
}