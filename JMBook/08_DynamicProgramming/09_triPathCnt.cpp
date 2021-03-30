#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tri[101][101] , N, cache[101][101],cache2[101][101];

int path(int y, int x)
{
	if(y == N) return 0;
	int& ret = cache[y][x];
	
	if(ret != -1) return ret;
	ret = max(path(y+1,x),path(y+1,x+1)) + tri[y][x];
	return ret;
}

int triCnt(int y, int x)
{
	if(y == N-1) return 1;
	
	int& ret = cache2[y][x];
	if(ret != -1) return ret;
	ret = 0;
	int&  cand1 = cache[y+1][x], cand2 = cache[y+1][x+1];
	if(cand1 >= cand2) ret += triCnt(y+1,x);
	if(cand2 >= cand1) ret += triCnt(y+1,x+1);
	
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
		memset(cache,-1,sizeof(cache));
		memset(cache2,-1,sizeof(cache2));
		cin >> N;
		for(int i=0;i<N;++i)
			for(int j=0;j<=i;++j)
				cin >> tri[i][j];
		
		path(0,0);
		cout << triCnt(0,0) << '\n';
	}

}