#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> p;
const int INF = (1 << 30), TARGET = 1;
vector<vector<p>> adj;

bool IsReachable(int src,int target)
{
	int n = adj.size();
	
	vector<bool> visited(n,false);
	queue<int> q;
	q.push(src);
	visited[src] = true;
	
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		
		for(int i=0;i<adj[here].size();++i)
		{
			int there = adj[here][i].first;
			if(visited[there]) continue;
			
			if(there == target) return true;
			visited[there] = true;
			q.push(there);
		}
	}
	
	return visited[target];
	
}
vector<int> getMinPath(int src)
{
	int n = adj.size();
	vector<int> upper(n,INF);
	upper[src] = 0;
	bool relaxed;
	for(int itr=0;itr<n-1;++itr)
	{
		relaxed = false;
		for(int here=0;here<n;++here)
		{
			if(upper[here] == INF) continue;
			
			for(int i=0;i<adj[here].size();++i)
			{
				int there= adj[here][i].first;
				int dist = adj[here][i].second;
				
				if(upper[there] > upper[here] + dist)
				{
					upper[there] = upper[here] + dist;
					relaxed = true;
				}
			}
		}
		
		if(!relaxed) return upper;
	}
	
	for(int here=0;here<n;++here)
	{
		if(upper[here] == INF) continue;

		for(int i=0;i<adj[here].size();++i)
		{
			int there= adj[here][i].first;
			int dist = adj[here][i].second;

			if(upper[there] > upper[here] + dist)
			{
				if(IsReachable(src,here) && IsReachable(here,TARGET))
				{
					upper.clear();
					return upper;
				}
			}
		}
	}
	
	return upper;
}

vector<int> getMaxPath(int src)
{
	int n = adj.size();
	vector<int> lower(n,-INF);
	lower[src] = 0;
	bool relaxed;
	for(int itr=0;itr<n-1;++itr)
	{
		relaxed = false;
		for(int here=0;here<n;++here)
		{
			if(lower[here] == -INF) continue;
			
			for(int i=0;i<adj[here].size();++i)
			{
				int there= adj[here][i].first;
				int dist = adj[here][i].second;
				
				if(lower[there] < lower[here] + dist)
				{
					lower[there] = lower[here] + dist;
					relaxed = true;
				}
			}
		}

		if(!relaxed) return lower;
	}
	
.	for(int here=0;here<n;++here)
	{
		if(lower[here] == -INF) continue;

		for(int i=0;i<adj[here].size();++i)
		{
			int there= adj[here][i].first;
			int dist = adj[here][i].second;

			if(lower[there] < lower[here] + dist)
			{
				if(IsReachable(src,here) && IsReachable(here,TARGET))
				{
					lower.clear();
					return lower;
				}
			}
		}
	}
	
	return lower;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{

		int N,K,a,b,c;

		cin >> N >> K;
		adj= vector<vector<p>>(N,vector<p>());

		for(int i=0;i<K;++i)
		{
			cin >> a >> b >> c;
			adj[a].push_back(p(b,c));
		}
		vector<int> upper = getMinPath(0);

		if(!upper.empty() && upper[1] == INF)
		{
			cout << "UNREACHABLE\n";
			continue;	
		}

		vector<int> lower = getMaxPath(0);

		if(upper.empty())
			cout << "INFINITY ";
		else
			cout << upper[1] << ' ';

		if(lower.empty())
			cout << "INFINITY\n";
		else
			cout << lower[1] << '\n';
	}
		
	
	
}