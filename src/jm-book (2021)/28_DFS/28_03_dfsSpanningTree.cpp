#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> discovered, finished;
vector<vector<int>> adj;
int cnt = 0;
void initializing(int N)
{
	discovered = vector<int>(N,-1);
	finished =  vector<int>(N,0);
	adj = vector<vector<int>>(N,vector<int>(0));
}

void dfs(int here)
{
	discovered[here] = cnt++;
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		
		cout << "vortext(" << here << "->" << there << ") : ";
		
		if(discovered[there] == -1)
		{
			cout << "tree edge" << '\n';
			dfs(there);
		}
		else if(discovered[here] < discovered[there])
		{
			cout << "forward edge" << '\n';
		}
		else if(finished[there] == 0)
		{
			cout << "back edge" << '\n';
		}
		else
		{
			cout << "cross edge" << '\n';
		}
	}
	finished[here] = 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	
	cin >> N;
	
	
	initializing(N);
	
	while(1)
	{
		int u,v;
		cin >> u >> v;
		if(u == -1) break;
		if(u >= N || v >= N) break;
		
		adj[u].push_back(v);
	}
	
	dfs(0);
	
	/*
	Input Example
	7
	0 1
	0 4
	0 5
	0 6
	1 2
	2 0
	4 2
	5 3
	5 6
	6 3
	-1 -1

*/
	
}