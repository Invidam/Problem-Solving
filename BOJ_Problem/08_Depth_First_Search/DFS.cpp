#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

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
	
	void addEdge(int u,int v){ //u번째 정점과 v먼째 정점을 잇는다.
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void sortList(){ // 모든 정점이 가지고 있는 간선을 오름차순 정렬한다.
		for(int i=0;i<N;i++) 
			sort(adj[i].begin(),adj[i].end());
	}
	
	void dfs_by_recursion(){
		fill(visited.begin(),visited.end(),false);
		dfs_by_recursion(0);
	}
	void dfs_by_stack(){
		fill(visited.begin(),visited.end(),false);
		dfs_by_stack(0);
	}
	
	
	int dfsAll_by_recursion(){
		int components = 0;
		int nodes = 0;
		fill(visited.begin(),visited.end(),false);
		for(int i=0;i<N;i++){
			if(!visited[i]){
				cout << "-- new DFS begin -- \n";
				nodes = dfs_by_recursion(i);
				components++;
				cout << "size : "<< nodes << '\n';
			}
		}
		return components;
	}
	int dfsAll_by_stack(){
		int components = 0;
		int nodes = 0;
		fill(visited.begin(),visited.end(),false);
		for(int i=0;i<N;i++)
		{
			if(!visited[i])
			{
				cout << "-- new DFS begin -- \n";
				nodes = dfs_by_stack(i);
				components++;
				cout << "size : "<< nodes << '\n';
			}
		}
		return components;
		
	}
	
private:
	/*
	void dfs_by_recursion(int curr)
	{
		visited[curr] = true;
		cout << "node : "<< curr << " visited\n";
		for(int next:adj[curr])
		{
			if(!visited[next])	dfs(next);
		}
	}
	void dfs_by_stack(int curr)
	{
		visited[curr] = true;
		stack<int> s;
		s.push(curr);
		while(!s.empty())
		{
			int itr = s.top();
			visited[itr] = true;
			cout << "node " << itr << '\n';
			s.pop();
			for(int i=adj[itr].size() -1;i>=0;i--)
				if(!visited[adj[itr][i]]) s.push(adj[itr][i]);
		}
	}
	*/
	
	int dfs_by_recursion(int curr){
		int nodes = 1;
		visited[curr] = true;
		cout << "node " << curr << " visited " << '\n';
		for(int next: adj[curr])
		{
			if(!visited[next])
			{
				nodes += dfs_by_recursion(next);
			}
		}
		return nodes;
	}
	int dfs_by_stack(int curr){
		
		visited[curr] = true;
		int nodes = 1;
		stack<int> s;
		s.push(curr);
		while(!s.empty())
		{
			int itr = s.top();
			visited[itr] = true;
			cout << "node : "<< itr << " visited\n";
			s.pop();
			for(int i=adj[itr].size() -1;i>=0;i--)
			{
				if(!visited[adj[itr][i]]) 
				{
					s.push(adj[itr][i]);
					nodes++;	
				}
			}
		}	
		return nodes;
	}
};



int main() {
	/*
	
	Graph G(9); // 0~ N-1까지의 정점을 생성.
	//정점은 간선과 방문여부를 저장하고 있다.
	
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 5);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(2, 6);
    G.addEdge(2, 8);
    G.addEdge(6, 7);
    G.addEdge(6, 8);
	
	G.sortList();
	G.dfs_by_recursion();
	G.dfs_by_stack();
	*/
	
	Graph G(10);
	G.addEdge(0, 1);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(4, 6);
    G.addEdge(5, 7);
    G.addEdge(5, 8);
    G.addEdge(7, 8);
	
	G.sortList();
	int components = G.dfsAll_by_stack();
	cout << "components : " << components << '\n';
	components = G.dfsAll_by_recursion();
	cout << "components : " << components << '\n';
	
	
}
