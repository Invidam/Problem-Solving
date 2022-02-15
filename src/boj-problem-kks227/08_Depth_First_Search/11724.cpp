#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/11724

/*
문제명: 연결요소의 개수
TL: 3s
ML: 512MB



Good
1. 기본 문제이다.
2. 
3. 

Bad
1. 
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 5m
TS: 92ms
MS: 6392KB
*/
	

class Graph{
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;
	
	//생성자
	Graph(): N(0) {}
	Graph(int n) : N(n) {
		adj.resize(N);
		visited.resize(N);
	}
	
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void sortList(){ 
		for(int i=0;i<N;i++) 
			sort(adj[i].begin(),adj[i].end());
	}
	
	void dfs_by_recursion(){
		fill(visited.begin(),visited.end(),false);
		dfs_by_recursion(0);
	}
	
	int dfsAll_by_recursion(){
		int components = 0;
		fill(visited.begin(),visited.end(),false);
		for(int i=0;i<N;i++){
			if(!visited[i]){
				dfs_by_recursion(i);
				components++;
			}
		}
		return components;
	}
	
private:
	
	void dfs_by_recursion(int curr){
		visited[curr] = true;
		for(int next: adj[curr])
			if(!visited[next])
				dfs_by_recursion(next);
		return;
	}
};



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M,u,v;
	cin >> N >> M;
	Graph G(N);
	for(int i=0;i<M;i++)
	{
		cin >> u >> v;
		G.addEdge(u-1,v-1);
	}
	
	cout << G.dfsAll_by_recursion();
	
	
}
