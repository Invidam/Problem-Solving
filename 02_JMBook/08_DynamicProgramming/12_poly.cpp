#include <iostream>
#include <cstring>
using namespace std;

int cache[101][101];
const int MOD = 10000000;

int poly(int n,int up)
{
	if(n ==0) return 1;
	int& ret = cache[n][up];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int next = 1;next <=n; ++next)
	{
		ret += poly(n-next,next)* (up == 0 ? 1 : (next + up - 1));
		ret %= MOD;
	}
	return ret;
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
		
		cout << poly(N,0)<< '\n';
	}

}