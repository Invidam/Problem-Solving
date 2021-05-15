#include <iostream>
#include <vector>
using namespace std;
double B[501],T[501][501],M[501][501],cache[501][101];
int m,n,q,inputWordsIdx[101],path[501][101];
string words[501],inputWords[101];

double getMaxPercent(int lastIdx,int len)
{
	if(len == 0) return 1;
	
	double& ret = cache[lastIdx+1][len];
	if(ret != -1) return ret;
	
	int existNum = inputWordsIdx[n-len], maxIdx = -1;
	
	for(int next=0;next<m;++next)
	{
		double cand_percent = (lastIdx == -1) ?  B[next]*M[next][existNum] : T[lastIdx][next]*M[next][existNum];
		double cand = getMaxPercent(next,len-1)*cand_percent;
		if(ret < cand)
		{
			ret = cand;
			maxIdx = next;
		}
	}
	
	path[lastIdx+1][len] = maxIdx;
	
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
		cin >> m >> q;
	
	for(int i=0;i<m;++i)
		cin >> words[i];
	
	for(int i=0;i<m;++i)
		cin >> B[i];
	
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			cin >> T[i][j];
	
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			cin >> M[i][j];
	
	for(int i=0;i<q;++i)
	{
		cin >> n;
		for(int i=0;i<n;++i)
			cin >> inputWords[i];
		
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(inputWords[i] == words[j]) inputWordsIdx[i] = j;
		
		fill_n(&cache[0][0],501*101,-1.0);
		fill_n(&path[0][0],501*101,-1);
		
		getMaxPercent(-1,n);
		
		int itr = path[0][n];
		while(itr != -1)
		{
			cout << words[itr] <<' ';
			n--;
			if(n < 0) break;
			itr = path[itr+1][n];
		}
		cout << '\n';
	}
}