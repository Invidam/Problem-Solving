#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e7;

int cache[101][101];

int poly(int top,int rest)
{
	if(rest == 0) return 1;
	int& ret = cache[top][rest];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i=rest;i>0;--i)
	{
		int multiplyValue = (top == 0 ) ? 1 : top+i-1;
		ret += multiplyValue* poly(i,rest-i);
		ret %= MOD;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;	
	
	memset(cache,-1,sizeof(cache));
	
	while(TC--)
	{
		
		int N;
		cin >> N;
		
		cout << poly(0,N) << '\n';
	}
}