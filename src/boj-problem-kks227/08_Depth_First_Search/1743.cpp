#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/1743

/*
문제명: 음식물 피하기
TL: 2s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. dfs에 대해 어떻게 구현하는지 (내가 하고있는게 맞는지) 확인해보기
https://www.acmicpc.net/source/25522443
kks님 소스 ( + 해설 참고)
다른 사람들 소스 보면서 비교하기.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 25m
TS: 0ms
MS: 2432KB
*/
	
int movement[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int pos[101][101];
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
	
	int dfsAll_by_recursion(){
		int nodes = 0;
		int max_nodes = 0;
		fill(visited.begin(),visited.end(),false);
		for(int i=0;i<N;i++){
			if(!visited[i]){
				nodes = dfs_by_recursion(i);
				max_nodes = max(max_nodes,nodes);
			}
		}
		return max_nodes;
	}
	
private:
	
	int dfs_by_recursion(int curr){
		int nodes = 1;
		visited[curr] = true;
		for(int next: adj[curr])
			if(!visited[next])
				nodes += dfs_by_recursion(next);
		
		return nodes;
	}
};



int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(pos[0],pos[101],-1);
	int N,M,K,r,c;
	cin >> N >> M >> K;
	Graph G(K);
	
	for(int i=0;i<K;i++)
	{
		cin >> r >> c;
		r--;
		c--;
		pos[r][c] = i;
		for(int j=0;j<4;j++)
		{
			if(r+movement[j][0] < 0 || r+movement[j][0] > N || c+movement[j][1] < 0 ||  c+movement[j][1] > M )
			{
				//cout  << "out "<< r+1 << " , " << c+1 << '\n';
				continue;
				
			}
			
			if(pos[r+movement[j][0]][c+movement[j][1]] != -1)
			{
				//cout <<"adj " << r+1 << " , " << c+1 << '\n';
				G.addEdge(i,pos[r+movement[j][0]][c+movement[j][1]]);
			}
		}
	}
	
	cout << G.dfsAll_by_recursion();
	
	
}
