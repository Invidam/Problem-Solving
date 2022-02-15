#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[101],cache2[101];

int asymTiling(int n)
{
	if(n <=1 ) return 1;
	if(n == 2) return 2;
	if(n==3 ) return 1;
	int& ret = cache2[n];
	if(ret != -1) return ret;
	
	return ret = (asymTiling(n-2) + asymTiling(n-4))%MOD;
}

int tiling(int n)
{
	if(n <=2 ) return n;
	int& ret = cache[n];
	if(ret != -1) return ret;
	return ret =(tiling(n-1) + tiling(n-2))%MOD;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC,N;
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		memset(cache,-1,sizeof(cache));
		memset(cache2,-1,sizeof(cache2));
		
		cout << (tiling(N) - asymTiling(N) + MOD)%MOD << '\n';
	}

}