#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<bool> visited;
vector<vector<int>> adj;

void dfs(int here)
{
	cout << "DFS Visited : " << here << '\n';
	visited[here] = true;
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		if(!visited[there])
			dfs(there);
	}
}
void dfs_noPrintVer(int here)
{
	visited[here] = true;
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		if(!visited[there])
			dfs_noPrintVer(there);
	}
}
void dfs_forTopology(int here,vector<int>& forPrint)
{
	visited[here] = true;
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		if(!visited[there])
			dfs_forTopology(there,forPrint);
	}
	forPrint.push_back(here);
}
void dfsAll()
{
	visited = vector<bool>(adj.size(),false);
	for(int i=0;i<visited.size();++i)
		if(!visited[i]) dfs(i);
}

int countComponent()
{
	int ret = 0;
	visited = vector<bool>(adj.size(),false);
	for(int i=0;i<visited.size();++i)
	{
		if(!visited[i]) 
		{
			ret++;
			dfs_noPrintVer(i);	
		}
	}
	
	return ret;
}
bool isLinked(int a,int b)
{
	visited = vector<bool>(adj.size(),false);
	dfs_noPrintVer(a);
	return visited[b];
}

void topologicalSort()
{
	visited = vector<bool>(adj.size(),false);
	vector<int> forPrint;
	for(int i=0;i<visited.size();++i)
		if(!visited[i]) dfs_forTopology(i,forPrint);
	
	for(auto itr = forPrint.rbegin(); itr != forPrint.rend();++itr)
		cout << *itr+1 << " ";
	cout << '\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	
	cin >> N;
	visited.resize(N);
	visited.assign(N,false);
	adj.resize(N);
	
	int K;
	cin >> K;
	for(int i=0;i<K;++i)
	{
		int v1,v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		adj[v1].push_back(v2);
	}
	for(int i=0;i<N;++i)
		sort(adj[i].begin(),adj[i].end());
	
	cout << isLinked(0,5) << '\n';
	cout << isLinked(4,5) << '\n';
	
	cout << countComponent() << '\n';
	
	topologicalSort();
	
}