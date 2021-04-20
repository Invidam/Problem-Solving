#include <iostream>
#include <vector>
//algospot.com/judge/problem/read/gallery

/*
문제명: 갤러리
TL:1s
ML: 64MB

TU: 1d
TS: 8ms
LEN: 1.4KB


Good
1. 스스로의 방식으로 품

Bad
1. 

IAN
1. 기존 답이 거의 잘나왔는데, 루트에 대한 처리가 부족했음.

NEW
1. 


Q1: 
A1: 


Solution:

Approach: 

Clue:

Reconstruction : 
*/


using namespace std;
const int UNWATCHED = 0, WATCHED = 2, INSTALLED = 1, HERE_IS_LEAF = 98765431;
int cameraCnt;
vector<bool> visited;
vector<int> adj[1001];

int G;

void initializing()
{
	visited  = vector<bool>(G,false);
	
	for(int i=0;i<G;++i)
		adj[i].clear();
	
	cameraCnt = 0;
}

void makeVertex(int a,int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int getCameraCnt(int here)
{
	visited[here] = true;
	
	if(adj[here].empty())
	{
		cameraCnt++;
		return INSTALLED;
	}
	
	int childStat = HERE_IS_LEAF;
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		
		if(!visited[there])
		{
			
			childStat = min(childStat,getCameraCnt(there));
		}
	}
	
	if(childStat == UNWATCHED)
	{
		cameraCnt++;
		return INSTALLED;
	}
	else if(childStat == INSTALLED)
	{
		return WATCHED;
	}
	else// if(childStat == WATCHED || childStat == HERE_IS_LEAF)
	{
		return UNWATCHED;
	}
	
}

void getAllCameraCnt()
{
	for(int i=0;i<G;++i)
	{
		if(!visited[i] && getCameraCnt(i) == UNWATCHED) 
		{
			cameraCnt++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,H;
	
	cin >> TC;
	
	while(TC--)
	{
		cin >> G >> H;
		initializing();
		
		int a,b;
		for(int i=0;i<H;++i)
		{
			cin >> a >> b;
			makeVertex(a,b);
		}
	  
		getAllCameraCnt();
		cout << cameraCnt << '\n';
		
		
	}
}

/*

#include <iostream>
#include <vector>

using namespace std;

int cameraCnt;
vector<bool> visited,isRuled;
vector<int> adj[1001];

int G;

void initializing()
{
	visited = isRuled = vector<bool>(G,false);
	
	for(int i=0;i<G;++i)
		adj[i].clear();
	
	cameraCnt = 0;
}

void makeVertex(int a,int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void getCameraCnt(int here)
{
	visited[here] = true;
	
	if(adj[here].empty())
	{
		isRuled[here] = true;
		cameraCnt++;
		return;
	}
	
	bool isChildAllRuled = true;
	
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		
		if(!visited[there])
		{
			getCameraCnt(there);
			if(!isRuled[there]) isChildAllRuled = false;
		}
	}
	
	if(!isChildAllRuled)
	{
		cameraCnt++;
		for(int i=0;i<adj[here].size();++i)
			isRuled[adj[here][i]] = true;
		isRuled[here] = true;
	}
	
}

void getAllCameraCnt()
{
	for(int i=0;i<G;++i)
	{
		if(!visited[i]) 
		{
			getCameraCnt(i);
			cameraCnt += !isRuled[i];
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,H;
	
	cin >> TC;
	
	while(TC--)
	{
		cin >> G >> H;
		initializing();
		
		int a,b;
		for(int i=0;i<H;++i)
		{
			cin >> a >> b;
			makeVertex(a,b);
		}
	  
		getAllCameraCnt();
		cout << cameraCnt << '\n';
	}
}*/


