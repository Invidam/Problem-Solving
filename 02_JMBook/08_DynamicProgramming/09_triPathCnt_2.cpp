#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[101][101],pathSum[101][101],N,arr[101][101];

int triPath(int y,int x)
{
	if(y >= N) return 0;
	
	int& ret = pathSum[y][x];
	if(ret != -1) return ret;
	
	return ret = max(triPath(y+1,x),triPath(y+1,x+1)) + arr[y][x];
}

int pathCnt(int y,int x)
{
	if(y == N-1) return 1;
	if(y >= N) return 0;
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	
	if(triPath(y+1,x) == triPath(y+1,x+1)) ret = pathCnt(y+1,x) + pathCnt(y+1,x+1);
	else if(triPath(y+1,x) > triPath(y+1,x+1)) ret = pathCnt(y+1,x);
	else ret = pathCnt(y+1,x+1);
	
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
		memset(pathSum,-1,sizeof(pathSum));
		cin >> N;
		
		for(int i=0;i<N;++i)
			for(int j=0;j<=i;++j)
				cin >> arr[i][j];
		
		triPath(0,0);
		cout << pathCnt(0,0) << '\n';
	}
}