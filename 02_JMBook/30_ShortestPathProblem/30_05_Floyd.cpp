#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> p;
const int INF = (1 << 25);

vector<vector<int>> adj,via;

void floyd()
{
	int V = adj.size();
	
	for(int i=0;i<V;++i)
		adj[i][i] = 0;
	
	for(int k=0;k<V;++k)
	{
		for(int i=0;i<V;++i)
		{
			for(int j=0;j<V;++j)
			{
				if(adj[i][j] > adj[i][k] + adj[k][j])
				{	
					adj[i][j] = adj[i][k] + adj[k][j];
					via[i][j] = k;
				}
			}
		}
	}
}

vector<int> reconstruct(int src, int target)
{
	vector<int> path;
	
	if(via[src][target] == -1)
	{
		path.push_back(src);
		
		if(src != target) 
			path.push_back(target);
	}
	else
	{
		int k = via[src][target];
		path = reconstruct(src,k);
		path.pop_back();
		vector<int> path2 = reconstruct(k,target);
		path.insert(path.end(),path2.begin(),path2.end());
	}
	
	return path;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int V,E,c;
	char a,b;
	cin >> V >> E;
	
	adj = vector<vector<int>>(V,vector<int>(V,INF));
	via = vector<vector<int>>(V,vector<int>(V,-1));
	
	for(int i=0;i<E;++i)
	{
		cin >> a >> b >> c;
		
		a -= 'a';
		b -= 'a';
		
		adj[a][b] = c;
		adj[b][a] = c;
	}
	
	//make adj shortestPath.
	floyd();
	
	
	
	//path is shortestPath(a,b);
	cin >> a >> b;
	a -= 'a';
	b -= 'a';
	
	vector<int> path = reconstruct(a,b);
	
	
	//print path
	for(int i=0;i<path.size();++i)
	{
		int elem = path[i];
		cout << (char)(elem + 'a');
		if(elem != path.back())
			cout << " =("<< adj[elem][path[i+1]] << ")=> ";
	}
	cout << "\nsum: " << adj[path.front()][path.back()]; 
	cout << '\n';
	
	/*
	test case
	7 9

	a b 5
	a c 1
	b d 1

	b g 3
	b f 3
	c d 2

	d e 5
	d f 3
	f g 2
	a b
	*/
}