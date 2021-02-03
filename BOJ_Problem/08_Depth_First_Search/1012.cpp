#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
//acmicpc.net/problem/1012

/*
문제명: 유기농 배추
TL: 1s
ML: 512MB



Good
1. Graph를 이용하여 풀었다.
2. 
3. 

Bad
1. 기존 만들었던 코드의 변형이라, 다시 만들면 좋을 것 같다.
2. pos을 이용할땐 [2][5]가 아니라 [5][2]이다. 5개의 배열이 있는데 그 배열의 내용이 2 개의 배열이기 때문이다.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h30m?
TS: 52ms
MS: 2284KB
*/
typedef pair<int, int> p;
int pos[5][2] = {{0,1},{0,-1},{1,0},{-1,0},{0,0}};
class Graph{
public:
	int N;
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<char> cycled;
	
	//생성자
	Graph(): N(0) {}
	Graph(int n) : N(n) {
		adj.resize(N);
		visited.resize(N);
	}
	
	void addEdge(int u,int v){ //u번째 정점과 v먼째 정점을 잇는다.
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void sortList(){ // 모든 정점이 가지고 있는 간선을 오름차순 정렬한다.
		for(int i=0;i<N;i++) 
			sort(adj[i].begin(),adj[i].end());
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
			if(!visited[next])	dfs_by_recursion(next);
	}
};



int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		p arr[2501];
		int M,N,K,x,y;
		bool is_adjacent = false;
		
		cin >> M >> N >> K;
		Graph G(K);
		for(int i=0;i<K;i++)
		{
			cin >> x >> y;
			arr[i] = p(x,y);
		}
		for(int i=0;i<K;i++)
		{
			for(int j=0;j<K;j++)
			{
				for(int k=0;k<5 && i != j;k++)
				{
					int adj_point = -1;
					if(arr[i].first+pos[k][0] == arr[j].first && arr[i].second+pos[k][1] == arr[j].second)
					{
						adj_point = j;
						if(adj_point != -1)
							G.addEdge(i,adj_point);
					}
				}
			}
		}
		G.sortList();
		cout << G.dfsAll_by_recursion() << '\n';
	}
	
	
}
