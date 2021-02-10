#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Graph{
public:
	int N;
	vector<vector<int>> adj;
	
	Graph(): N(0) {}
	Graph(int n): N(n)
	{
		adj.resize(N);
	}
	
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	void sortList()
	{
		for(int i=0;i<N;i++)
			sort(adj[i].begin(),adj[i].end());
	}
	
	void bfs()
	{
		vector<bool> visited(N,false);
		queue<int> q;
		q.push(0);
		visited[0] = true;
		int level = 0;
		while(!q.empty())
		{
			int qsize = q.size();
			cout << "== level : " << level << "==\n";
			for(int i=0;i<qsize;i++)
			{
				int curr = q.front();
				q.pop();
				cout << "node " << curr << " visited\n";
				for(int next : adj[curr])
				{
					if(!visited[next])
					{
						q.push(next);
						visited[next] = true;
					}
				}
			}
			level++;
		}
		
	}
};

int main()
{
	Graph G(9);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,3);
	G.addEdge(1,5);
	G.addEdge(3,4);
	G.addEdge(5,4);
	G.addEdge(2,6);
	G.addEdge(2,8);
	G.addEdge(6,7);
	G.sortList();
	G.bfs();
}