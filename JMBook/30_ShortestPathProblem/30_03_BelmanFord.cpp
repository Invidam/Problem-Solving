#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> p;
const int INF = (1 << 30);

vector<vector<p>> adj;

vector<int> bellman_ford(int src)
{
	int n = adj.size();
	vector<int> upper(n,INF);
	upper[src] = 0;
	bool relaxed;
	for(int itr=0;itr<n;++itr)
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
		
		for(int i=0;i<upper.size();++i)
			cout << (char)(i + 'a') << ":"<< upper[i] << '\n';
		cout << "======\n";
		if(!relaxed) break;
	}
	
	if(relaxed) upper.clear();
	return upper;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,K,c;
	char a,b;
	
	cin >> N >> K;
	adj= vector<vector<p>>(N,vector<p>());
	
	for(int i=0;i<K;++i)
	{
		cin >> a >> b >> c;
		a -= 'a';
		b -= 'a';
		adj[a].push_back(p(b,c));
	}
	vector<int> upper = bellman_ford(0);
	for(int i=0;i<upper.size();++i)
		cout << (char)(i + 'a') << ":"<< upper[i] << '\n';
	
}