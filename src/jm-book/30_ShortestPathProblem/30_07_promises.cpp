#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (1 << 25);

vector<vector<int>> adj;
int promises[3][1001];
int V,M,N;
void floyd()
{	
	for(int i=0;i<V;++i)
		adj[i][i] = 0;
	
	for(int k=0;k<V;++k)
		for(int i=0;i<V;++i)
			for(int j=0;j<V;++j) 
				if(adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
}

int cntMeaningless()
{
	int ret = 0;
	for(int k=0;k<N;++k)
	{
		int start = promises[0][k];
		int end = promises[1][k];
		int weight = promises[2][k];
		
		if(adj[start][end] <= weight)
		{
			ret++;
			continue;
		}
		for(int i=0;i<V;++i)
		{
			for(int j=0;j<V;++j)
			{
				if(adj[i][j] > adj[i][start] + adj[end][j] + weight)
					adj[i][j] = adj[i][start] + adj[end][j] + weight;
				if(adj[i][j] > adj[i][end] + adj[start][j] + weight)
					adj[i][j] = adj[i][end] + adj[start][j] + weight;
			}
		}
	}
	
	return ret;	
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
		int a,b,c;
		cin >> V >> M >> N;
		adj = vector<vector<int>>(V,vector<int>(V,INF));

		for(int i=0;i<M;++i)
		{
			cin >> a >> b >> c;
			if(adj[a][b] < c) continue;
			adj[a][b] = c;
			adj[b][a] = c;
		}
		
		floyd();
		
		for(int i=0;i<N;++i)
			cin >> promises[0][i] >> promises[1][i] >> promises[2][i];
		
		cout << cntMeaningless() << '\n';
	}
}