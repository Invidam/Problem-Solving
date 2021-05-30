#include <iostream>
#include <vector>
using namespace std;
const double INF = 987654321;
double dist[9][9];
int N;
double shortestPath(vector<bool>& visited, int curr, double currLen)
{
	bool baseFlag = true;
	for(int i=0; i<N;++i)
	{
		if(visited[i] == false)
		{
			baseFlag = false;
			break;
		}
	}
	
	if(baseFlag)
		return currLen;
	
	double ret = INF,cand;
	for(int next =0; next <N;next++)
	{
		if(visited[next] == true)
			continue;
		visited[next] = true;
		if(curr == -1)
			cand = shortestPath(visited,next,currLen);
		else 
			cand = shortestPath(visited, next, currLen + dist[curr][next]);
			
		visited[next] = false;
		
		ret = ret < cand ? ret : cand;
		
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		char c;
		cin >> N;
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				cin >> dist[i][j];
				cin.get(c);
			}
		}
		vector<bool> visited(8,false);
		cout << fixed;
		cout.precision(10);
		cout << shortestPath(visited,-1,0) << '\n';
	}

}