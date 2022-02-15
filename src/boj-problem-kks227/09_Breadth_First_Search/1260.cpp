#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;


//acmicpc.net/problem/1260

/*
문제명: dfs 와 bfs
TL: 2s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. 만들어놨던 기본형태에 오류가 있었다.(이미 추가한 값을 또 추가시킬 때) [1. 방문여부 확인  2. 방문 기록 및 정점 출력 3. 간선 추가 ]
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW : 새로운 라이브러리 배웠다. (모든 라이브러리를 저장시켜놓은 것) [TU 감소 및 MS 증가]
keypoint: 

TU: 40m
TS: 0ms
MS: 2296KB
*/



int N,M,V;
vector<vector<int>> adj;
bool visited[1001];

/*
void dfs(int idx)
{
	visited[idx] = true;
	cout << idx +1 <<" ";
	for(auto& next : adj[idx])
	
		if(!visited[next]) dfs(next);
}
*/
void dfs()
{
	fill(visited,visited+1001,false);
	stack<int> s;
	s.push(V);
	while(!s.empty())
	{
		int curr = s.top();
		s.pop();
		if(visited[curr])
			continue;
		visited[curr] = true;
		cout << curr + 1 <<" ";
		for(int i=adj[curr].size()-1;i>=0;i--)
		{
			if(!visited[adj[curr][i]])
			{
				s.push(adj[curr][i]);
			}
		}
	}
	cout << '\n';
}
void bfs()
{
	fill(visited,visited+1001,false);
	queue<int> q;
	q.push(V);
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		if(visited[curr])
			continue;
		visited[curr] = true;
		cout << curr + 1 <<" ";
		for(auto& next : adj[curr])
		{
			if(!visited[next])
			{
				q.push(next);
			}
		}
	}
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> V;
	
	V--;
	adj.resize(N+1);
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	for(int i=0;i<N;i++)
		sort(adj[i].begin(),adj[i].end());
	
	dfs();
	cout << '\n';
	bfs();
}