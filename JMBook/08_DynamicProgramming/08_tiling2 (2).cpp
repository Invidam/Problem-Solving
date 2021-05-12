#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int cache[10001];
int tiling(int n)
{
	if(n <= 1) return 1;
	int& ret = cache[n];
	return ret = (ret != -1)? ret : (tiling(n-1) + tiling(n-2))%MOD;
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
		int N;
		cin >> N;
		
		cout << tiling(N) << '\n';
	}
}