#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//algospot.com/judge/problem/read/FORTRESS

/*
문제명: 요새
TL: 1s
ML: 64MB

TU: 2h30m
TS: 4ms
LEN: 2.5KB


Good
1. 

Bad
1. x,y,r이 아니라 idx를 element로 줬으면 좀 더 메모리가 단축되었을듯.

IAN
1. inside함수의 오류
2. 자식이 1개일 때, 잘못된 값 도출
3. height -1 이아닌 height로의 선언

NEW
1. cmp함수 사용법 (구체적인 실행시의 코드)


Q1: 
A1: 


Solution: 요새들을 트리로 나타낸 뒤 가장 긴 경로를 찾는다.

Approach: 요새들을 벗어난다는 개념이 트리구조와 유사하여 보였음.

Clue: 거리 찾기 또하 ㄴ트리구조에 자주쓰임

Reconstruction : 
*/



typedef pair<int, int> p;
p coord[101], radius[101];
int N,M1,M2;

bool cmp(const p& a,const p& b)
{
	if(a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

struct fortress
{
	int x,y,r;
	fortress(int x,int y,int r) : x(x),y(y),r(r) {}
};

struct treeNode
{
	fortress* element;
	treeNode* parent;
	vector<treeNode *>children;
	int height = -1;
	
};

bool isInside(fortress* big,fortress* small)
{
	int deltaX = big->x - small->x, deltaY = big->y - small->y;
	
	int distance = deltaX*deltaX + deltaY * deltaY;
	int rad = big->r;
	return (distance < (rad*rad)); 
	
}
//https://stackoverflow.com/questions/25098807/return-pointer-to-node-in-insert-method-of-binary-search-tree
treeNode* makeTree(treeNode* curr,int i)
{	
	const int& idx = radius[i].second;
	fortress* element = new fortress(coord[idx].first,coord[idx].second,radius[i].first);

	treeNode* toAdd = new treeNode;
	toAdd->element = element;
	
	if(i==0)
	{
		curr = toAdd;
		curr->parent = nullptr;
		return curr;
	}
	
	bool isSibiling = true;
	
	for(int j=0;j<curr->children.size();++j)
	{
		if(isInside(curr->children[j]->element,element))
		{;
			curr->children[j] = makeTree(curr->children[j],i);
			isSibiling = false;	
			break;
		}
	}
	
	if(isSibiling)
	{
		curr->children.push_back(toAdd);
		toAdd->parent = curr;
	}
	
	return curr;

}
void updateMax(int n)
{
	int tmp;
	if(M1 < n)
	{
		tmp = M1;
		M1 = n;
		n = tmp;
	}
	if(M2 < n)
		M2 = n;
}
int getHeight(treeNode* root)
{
	int &ret = root->height;
	if(ret != -1) return ret;
	
	if(root->children.empty())
		return ret = 1;
	
	for(int i=0;i<root->children.size();++i)
		ret = max(ret,getHeight(root->children[i]) + 1);
	
	return ret;
}
int getMaxWall(treeNode* root)
{
	int ret = 0;
	int height = getHeight(root);
	ret = max(ret,height-1);
	
	M1 = M2 = 0;
	for(int i=0;i<root->children.size();++i)
		updateMax(getHeight(root->children[i]));
  
	ret = max(ret,M1+M2);
	for(int i=0;i<root->children.size();++i)
		ret = max(ret,getMaxWall(root->children[i]));
  
	return ret;
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
		int x,y,r;
		cin >> N;
		for(int i=0;i<N;++i)
		{
			cin >> x >> y >> r;
			coord[i] = p(x,y);
			radius[i] = p(r,i);
		}
		treeNode* root;
		sort(radius,radius + N,cmp);
		
		for(int i=0;i<N;++i)
			root = makeTree(root,i);
		
		cout << getMaxWall(root) << '\n';
	}
}

/*
4

2
11
21 15 20
15 15 10
13 12 5 
12 12 3 
12 12 2
12 12 1
19 19 3
19 19 2
19 19 1
30 24 5
32 10 7

12
20 20 1000
21 15 20
15 15 10
13 12 5 
12 12 3 
12 12 2
12 12 1
19 19 3
19 19 2
19 19 1
30 24 5
32 10 7



3
5 5 15
5 5 10
5 5 5

8 
21 15 20 
15 15 10 
13 12 5 
12 12 3 
19 19 2 
30 24 5 
32 10 7 
32 9 4 

ts
*/