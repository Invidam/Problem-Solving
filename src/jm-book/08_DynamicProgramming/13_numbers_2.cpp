#include <iostream>
#include <cstring>
using namespace std;

bool adj[101][101];
int adjSize[101],N,T,D,P;
double cache[101][101];

double getFindPercent(int day,int here)
{
	if(day == 0) return (here==P);
	
	double& ret = cache[day][here];
	if(ret != -1) return ret;
	
	ret = 0;
	
	for(int before=0;before<N;++before)
	{
		if(!adj[here][before]) continue;
		ret += getFindPercent(day-1,before) / adjSize[before];
	}
	return ret;
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
		memset(adj,false,sizeof(adj));
		fill(&cache[0][0],&cache[100][100],-1);
		memset(adjSize,0,sizeof(adjSize));
		
		cin >> N >> D >> P;
		
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				cin >> adj[i][j];
				if(adj[i][j]) adjSize[i]++;
			}
		}
		
		int T,Q;
		cin >> T;
		
		while(T--)
		{
			cin >> Q;
			cout << getFindPercent(D,Q) << ' ';
		}
		
		cout << '\n';
	}
}