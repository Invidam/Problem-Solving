#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> p;
const int INF = (1 << 25);

vector<vector<p>> adj;
vector<int> inspectTime;

void floyd()
{
	int V = adj.size();
	vector<p> order(V);
	for(int i=0;i<V;++i)
		order[i] = p(inspectTime[i],i);
	sort(order.begin(),order.end());
	
	for(int i=0;i<V;++i)
	{
		adj[i][i] = p(0,0);
	}
	
	for(int k=0;k<V;++k)
	{
		int w = order[k].second;
		for(int i=0;i<V;++i)
		{
			for(int j=0;j<V;++j)
			{
				adj[i][j].first = min(adj[i][j].first, adj[i][w].first + adj[w][j].first);
				adj[i][j].second =min(adj[i][j].second,  adj[i][w].first + adj[w][j].first + inspectTime[w]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int V,E,a,b,c;
	cin >> V >> E;
	adj = vector<vector<p>>(V,vector<p>(V,p(INF,INF)));
	inspectTime = vector<int>(V);
	
	for(int i=0;i<V;++i)
		cin >> inspectTime[i];
	
	for(int i=0;i<E;++i)
	{
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a][b] = p(c,c);
		adj[b][a] = p(c,c);
	}
	//make adj shortestPath.
	floyd();
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		cin >> a >> b;
		a--;
		b--;
		cout << adj[a][b].second << '\n';
	}
}