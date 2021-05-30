#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> adj;
vector<int> dist,parent;

void initializing(int N)
{
	dist = parent = vector<int>(N,-1);
	adj = vector<vector<int>>(N,vector<int>());
}

vector<int> bfs(int start)
{
	vector<int> order;
	vector<int> q;
	
	dist[start] = 0;
	parent[start] = start;
	q.push_back(start);
	
	while(!q.empty())
	{
		int here = q.front();
		q.erase(q.begin());//q.pop_front();
		
		order.push_back(here);		

		for(int i=0;i<adj[here].size();++i)
		{
			int there = adj[here][i];
			if(dist[there] != -1 ) continue;
			
			q.push_back(there);
			dist[there] = dist[here] +1;	
		}
	}

	return order;
}

vector<int> shortestParth(int u, int v)
{
	vector<int> path(1,v);
	while(parent[v] != v)
	{
		v = parent[v];
		path.push_back(v);
	}
	
	reverse(path.begin(),path.end());
	
	return path;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int N, K;
	cin >> N >> K;
	
	initializing(N);
	
	for(int i=0;i<K;++i)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		parent[b] = a;
	}

	vector<int> ret;
	bfs(0);
	ret = shortestParth(0,5);
	cout << "len: "<<dist[ret.back()] << '\n';
	cout << "path: [";
	for(auto& elem: ret)
	{
		cout << elem;
		if(elem != ret.back())
			cout << "-> ";
		else
			cout << "]\n";
	}
	// TC : 7 6 0 1 0 2 0 3 1 4 4 5 2 6
	
}