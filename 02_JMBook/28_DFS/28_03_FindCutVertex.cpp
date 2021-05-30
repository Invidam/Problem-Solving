#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> discovered;
vector<bool> isCutVertex;
vector<vector<int>> adj;
int cnt = 0;
void initializing(int N)
{
	discovered = vector<int>(N,-1);
	isCutVertex =  vector<bool>(N,0);
	adj = vector<vector<int>>(N,vector<int>(0));
}
int findCutVertex(int here, bool isRoot)
{
	discovered[here] = cnt++;
	int ret = discovered[here],children = 0;
	
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		
		if(discovered[there] == -1)
		{
			children++;
			int subtree = findCutVertex(there,false);
			if(!isRoot && subtree >=discovered[here])
				isCutVertex[here] = true;
			ret = min(ret,subtree);	
		}
		else
			ret = min(ret,discovered[there]);
	}
	if(isRoot)
		isCutVertex[here] = (children >= 2);
		
	
	return ret;
	
	
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
		adj[v].push_back(u);
	}
	
	findCutVertex(0,true);
	
	for(int i=0;i<isCutVertex.size();++i)
		if(isCutVertex[i]) cout << i << '\n';

}