#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[101][101],cache[101][101],N;

int getMaxPath(int y,int x)
{
	if(y >= N || x >= N) return 0;
	
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	
	return ret = arr[y][x] + max(getMaxPath(y+1,x),getMaxPath(y+1,x+1));
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
		cin >> N;
		memset(cache,-1,sizeof(cache));
		
		for(int i=0;i<N;++i)
			for(int j=0;j<=i;++j)
				cin >> arr[i][j];
		
		cout << getMaxPath(0,0) << '\n';
		
	}
}