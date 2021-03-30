#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321, MAX = 101;
int N,S,pSum[MAX],pSqSum[MAX],arr[MAX],cache[MAX][MAX];

void precalc()
{
	sort(arr,arr+N);
	pSum[0]= arr[0];
	pSqSum[0] = arr[0] * arr[0];
	
	for(int i=1;i<N;++i)
	{
		pSum[i] = arr[i] + pSum[i-1];
		pSqSum[i] = arr[i] * arr[i] + pSqSum[i-1];
	}
}

int getError(int from, int to)
{
	int n = to - from +1;
	int sum = pSum[to] - (from == 0 ? 0 : pSum[from-1]);
	int Sqsum = pSqSum[to] - (from == 0 ? 0: pSqSum[from-1]);
	int m = int((double)sum/n + 0.5);
	int ret = Sqsum + m*m*n - 2 * sum * m;
	return ret;
}

int quantize(int from, int parts)
{
	
//	if(from == N) return 0;
	if(from >= N) return INF;
	
	if(N < parts) return quantize(0,N);
	
	int& ret = cache[from][parts];
	if(ret != -1) return ret;
	if(parts == 1) return ret = getError(from,N-1);
	ret = INF;
	
	for(int next = 1; from + next <= N;++next)
	{
		ret = min(ret,getError(from,from+next - 1)+quantize(from + next, parts - 1));
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
		cin >> N >> S;
		for(int i=0;i<N;++i) cin >> arr[i];
		
		precalc();
		memset(cache,-1,sizeof(cache));
	//	cout << getError(0,2) << '\n' << getError(3,6) << '\n';
		cout << quantize(0,S) << '\n';
	}

}