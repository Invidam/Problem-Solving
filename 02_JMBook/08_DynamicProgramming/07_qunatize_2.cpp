#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//tc 50 n 100 s 10 num 1000
const int INF = 987654321;
int N,S,cache[101][11],arr[101];

int getMinError(int from,int to)
{
	int n = to - from,sum = 0,errorSum = 0,avg;
	
	for(int i=from;i<to;++i)
		sum += arr[i];
	
	avg = (int)((double)sum/n + 0.5);
	
	for(int i=from;i<to;++i)
		errorSum += (avg - arr[i])*(avg - arr[i]);
	
	return errorSum;
}

int quantize(int from,int s)
{
	if(s ==0) return (from == N) ? 0 : INF;
	if(from == N) return 0;
	
	int& ret = cache[from][s];
	if(ret != -1) return ret;
	ret = INF;
	
	for(int next=from+1;next<=N; ++next)
		ret = min(ret,getMinError(from,next)+quantize(next,s-1));
	
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
		memset(cache,-1,sizeof(cache));
		cin >> N >> S;
		for(int i=0;i<N;++i)
			cin >> arr[i];
		
		sort(arr,arr+N);
		
		cout << quantize(0,S) <<'\n';
	}
}