#include <iostream>
#include <cstring>
#include <algorithm>
int triangle[101][101], cache[101][101], N;
using namespace std;

int path(int y, int x)
{
	if(y >= N || x >= N) return 0;
	
	int& ret = cache[y][x];
	if(ret != -1) return ret;
	
	return ret = max(path(y+1 ,x),path(y+1,x+1)) + triangle[y][x];
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
		cin >> N;
		for(int i=0;i<N;++i)
			for(int j=0; j<=i;++j)
				cin >> triangle[i][j];
		
		cout << path(0,0) << '\n';
	}

}