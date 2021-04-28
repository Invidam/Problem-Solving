#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>> adj;
vector<int> parent;
const int INF = 987654321;
int N,K;
vector<int> dijkstra(int src)
{
	vector<int> dist(N,INF);
	priority_queue<p,vector<p>> pq;
	pq.push(p(0,src));
	dist[src] = 0;
	parent[src] = src;
	
	while(!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		
		if(dist[here] < cost)
		{
			cout << "here: " << here << '\n';
			continue;
		}
		for(int i=0;i<adj[here].size();++i)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(p(-nextDist,there));
				parent[there] = here;
			}
		}
		
	}
	
	return dist;
}
vector<int> dijkstra_except_pq(int src)
{
	vector<int> dist(N,INF);
	//priority_queue<p,vector<p>,greater<p>> pq;
	//pq.push(p(0,src));
	vector<bool> visited(N,false);
	dist[src] = 0;
	visited[src] = false;
	parent[src] = src;
	
	while(1)
	{
		int closet = INF, here;
		for(int i=0;i<N;++i)
		{
			if(dist[i] < closet && !visited[i])
			{
				closet = dist[i];
				here = i;
			}
		}
		// 모든 정점이 방문되었을 때
		if(closet == INF) break;

		visited[here] =true;
		for(int i=0;i<adj[here].size();++i)
		{
			int there = adj[here][i].first;

			//dist[there]이 방문하지 않은 정점들보다 가장 작을 때, 진행해봤자 의미가 없을 때
			//이미 자신보다 멀리 떨어진 정점들밖에 없어, 위 반복문을 통해 방문이 되었을 때
			if(visited[there])
			{
				cout << "=\n=\n=\n";
				continue;
			}

			int nextDist = closet + adj[here][i].second;
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				parent[there] = here;
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
	
	cin >> N >> K;
	
	adj = vector<vector<p>>(N,vector<p>());
	parent = vector<int>(N);
	
	char a,b;
	int c;
	for(int i=0;i<K;++i)
	{
		cin >> a >> b >> c;
		adj[a- 'a'].push_back(p(b-'a',c));
		adj[b-'a'].push_back(p(a-'a',c));
	}
	
	vector<int> dist = dijkstra(0);
	for(int i=0;i<N;++i)
		cout << (char)(i + 'a') << " dist : " << dist[i] << '\n';
	
	int here = N-1;
	while(1)
	{
		cout << (char)(here + 'a') << "-> ";
		if(parent[here] == here) break;
		here = parent[here];
	}
	cout << "end\n";
	
	
}
/*
input
7 9
a b 5
a c 1
b d 1
b f 3
b g 3
c d 2
d e 5
d f 3
f g 2
*/