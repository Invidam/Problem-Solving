#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,TC,arr[501],cache[501];

int lis(int start)
{
	int& ret = cache[start+1];
	if(ret != -1) return ret;
	ret = 0;
	for(int next = start +1;next<N;++next)
	{
		if(start == -1 || arr[start] < arr[next])
			ret = max(ret,lis(next) + 1);
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin  >> TC;
	while(TC--)
	{
		memset(cache,-1,sizeof(cache));
		cin >> N;
		for(int i=0;i<N;++i)
			cin >> arr[i];
		
		cout << lis(-1) << '\n';
	}
}
/*
int N,TC,arr[501],cache[501][501];

int LIS(int bef, int from)
{
	if(from >= N) return 0;
	int& ret = cache[bef+1][from];
	if(ret != -1) return ret;
	
	if(bef == -1 || arr[bef] < arr[from])
		ret = max(ret,LIS(from,from+1)+1);
	ret = max(ret,LIS(bef,from+1));
	
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin  >> TC;
	while(TC--)
	{
		memset(cache,-1,sizeof(cache));
		cin >> N;
		for(int i=0;i<N;++i)
			cin >> arr[i];
		
		cout << LIS(-1,0) << '\n';
	}
}
*/
