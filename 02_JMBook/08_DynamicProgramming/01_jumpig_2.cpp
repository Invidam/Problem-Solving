#include <iostream>
#include <cstring>
using namespace std;

int arr[101][101];
char cache[101][101];
int N;

bool jumping(int y,int x)
{
	if(y == N-1 && x == N-1) return true;
	else if(y >= N || x >= N) return false;
	
	char& ret = cache[y][x];
	if(ret != -1) return ret;
	
	int range = arr[y][x];
	return ret= jumping(y+range,x) | jumping(y,x+range);
}

string canJump()
{
	if(jumping(0,0))
		return "YES";
	else
		return "NO";
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
			for(int j=0;j<N;++j)
				cin >> arr[i][j];
		
		cout << canJump() << '\n';
	}
}