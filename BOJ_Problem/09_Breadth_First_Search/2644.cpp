#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//acmicpc.net/problem/2644

/*
문제명: 촌수계산
TL: 1s
ML: 128MB



Good
1. O(n^2)으로 해결하였다. (n이 100밖에 안되기 때문이다.)
2. bfs를 배웠다. (하위 트리의 수 만큼만 push를 하여 level을 cnt한다는 개념을 이해하였다.) 
3. 

Bad
1. 촌수는 부모뿐만이 아니라 자식도 된다는 것을 생각해내지 못하였다.
(문제의 상황[부모자식]을 이해하기보다 문제의 특징[촌수 증가 법칙]을 이해하기.)
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h10m
TS: 0ms
MS: 2016KB
*/


/*
int n, a, b , m , x , y;
int parent[101];

vector<int> a_parent;
vector<int> b_parent;
int solve()
{
	for(int i=0;i<a_parent.size();i++)
	{
		for(int j=0;j<b_parent.size();j++)
		{
			if(a_parent[i] == b_parent[j])
				return i + j;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a >> b;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		parent[y] = x;
	}
	a_parent.push_back(a);
	while(parent[a_parent.back()] != 0)
		a_parent.push_back(parent[a_parent.back()]);
	int a_lv = a_parent.size();
	
	
	b_parent.push_back(b);
	while(parent[b_parent.back()] != 0)
		b_parent.push_back(parent[b_parent.back()]);
	int b_lv = b_parent.size();
	
	
	if(a_parent.back() == b_parent.back()) // 같은 계통
	{
		if(a_lv > b_lv)
		{
			for(int i=0;i<a_lv;i++)
			{
				if(a_parent[i] == b)
				{
					cout << i;
					return 0;	
				}
			}
			cout << solve();
		}
		else if( a_lv < b_lv)
		{
			for(int i=0;i<b_lv;i++)
			{
				if(b_parent[i] == a)
				{
					cout << i;
					return 0;	
				}
			}
			cout <<solve();
		}
		else
			cout << solve();
	}
	else
		cout << "-1";
	
}
*/

//bfs를 이용한 풀이
int n, a, b , m , x , y;
bool visited[101];
vector<vector<int>> adj;

int bfs(int s,int e)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	int dis = 1;
	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<size;i++)
		{
			int curr = q.front();
			q.pop();
			for(int next : adj[curr])
			{
				if(visited[next])
					continue;
				if(next == e)
					return dis;
				q.push(next);
				visited[next] = true;
			}
		}
		dis++;
	}
	
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a >> b;
	adj.resize(n);
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	cout << bfs(a-1,b-1);
	
}