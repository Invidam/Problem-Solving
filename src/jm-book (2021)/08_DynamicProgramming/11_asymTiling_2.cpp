#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e9+7;
int cache1[101],cache2[101];
int tiling(int n)
{
	if(n <= 1) return 1;
	
	int& ret = cache1[n];
	if(ret != -1) return ret;
	
	return ret = (tiling(n-1) + tiling(n-2))%MOD;
}

int asymTiling(int n)
{
	if(n<=2) return (n>0) ? n : (n==0);
	int& ret = cache2[n];
	if(ret != -1) return ret;
	
	return ret = (asymTiling(n-4) + asymTiling(n-2)) % MOD;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;	
	
	memset(cache1,-1,sizeof(cache1));
	memset(cache2,-1,sizeof(cache2));
	
	while(TC--)
	{
		
		int N;
		cin >> N;
		int ans = (tiling(N) - asymTiling(N) + MOD)%MOD;
		cout << ans << '\n';
	}
}