#include <iostream>
#include <cstring>
using namespace std;

int N,L,cache[1001][1001],arr[1001];
double avgMin;

int updateSum(int from, int to)
{
	int len = to - from + 1;
	int& ret = cache[from][to];
	if(ret != -1) return ret;
	
	if(len != L)
		ret = updateSum(from,to-1) + arr[to];
	else
		ret = updateSum(from-1,to-1) - arr[from -1] + arr[to];
	
	
	double avg = (double)ret / len;
	avgMin = avgMin < avg ? avgMin : avg;
		
	return ret;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(8);
	int TC;
	cin >> TC;
	while(TC--)
	{
		int sum = 0;
		cin >> N >> L;
		
		memset(cache,-1,sizeof(cache));
		
		for(int i=0;i<N;++i)
		{
			cin >> arr[i];
			if(i < L) sum += arr[i];
		}
		
		cache[0][L-1] = sum;
		avgMin = (double)sum / L;
		for(int i=0;i+L<=N;++i)
			updateSum(i,N-1);
		
		cout << avgMin << '\n';
		
	}
}