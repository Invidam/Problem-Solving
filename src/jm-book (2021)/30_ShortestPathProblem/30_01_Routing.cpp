#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <limits.h>
using namespace std;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;
vector<vector<pid>> adj;
const double INF = pow(10,308);
int N,K;
vector<double> dijkstra(int src)
{
	vector<double> dist(N,INF);
	priority_queue<pdi,vector<pdi>> pq;
	pq.push(pdi(0,src));
	dist[src] = 0;
	
	while(!pq.empty())
	{
		int here = pq.top().second;
		double cost = -pq.top().first;
		pq.pop();
		
		if(dist[here] < cost) continue;
		for(int i=0;i<adj[here].size();++i)
		{
			int there = adj[here][i].first;
			double nextDist = cost + adj[here][i].second;
			
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(pdi(-nextDist,there));
			}
		}
	}
	
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		cin >> N >> K;

		adj = vector<vector<pid>>(N,vector<pid>());

		int a,b;
		double c;
		for(int i=0;i<K;++i)
		{
			cin >> a >> b >> c;
			c = log10(c);
			adj[a].push_back(pid(b,c));
			adj[b].push_back(pid(a,c));
		}

		vector<double> dist = dijkstra(0);
		cout << pow(10,dist[N-1]) << '\n';
	}
	
}