#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> p;
const int INF = (1 << 30), X = 200,MAX_SIZE = 400,START_NUM = -199,END_NUM = 199, O = 199;

vector<vector<p>> adj;

int numberToIndex(int n)
{
	return n + 199;
}

vector<int> dijkstra(int src)
{
	int n = adj.size();
	
	vector<int> dist(n,INF);
	priority_queue<p,vector<p>> pq;
	
	// X -> 399로 변경
	src = numberToIndex(src);
	
	pq.push(p(0,src));
	dist[src] = 0;
	
	while(!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		
		pq.pop();
		
		if(dist[here] < cost) continue;
		
		for(int i=0;i<adj[here].size();++i)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(p(-nextDist,there));
			}
		}
	}
	
	return dist;
}

int solve(vector<int>& a, vector<int>& b)
{
	int m = a.size();
	vector<int> courses(m);
	
	for(int i=0;i<m;++i)
	{
		courses[i] = a[i] - b[i];
		adj[numberToIndex(X)].push_back(p(numberToIndex(courses[i]),a[i]));
	}

	for(int num=START_NUM;num<END_NUM+1;++num)
	{
		for(int i=0;i<m;++i)
		{
			int nextNum = num + courses[i];
			int weight = a[i];
			
			if(nextNum < START_NUM || nextNum > END_NUM) continue;

			adj[numberToIndex(num)].push_back(p(numberToIndex(nextNum),weight));
		}
	}
	
	vector<int> dist = dijkstra(X);
	
	return dist[O];
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
		int m;
		cin >> m;
		
		adj = vector<vector<p>>(MAX_SIZE,vector<p>());
		vector<int> a(m),b(m);
		
		for(int i=0;i<m;++i)
			cin >> a[i] >> b[i];
		
		int ans = solve(a,b);
		
		if(ans != INF)
			cout << ans << '\n';
		else
			cout << "IMPOSSIBLE\n";
	}
}