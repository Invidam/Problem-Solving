#include <iostream>
#include <cstring>
using namespace std;

int visited[101][101];
char board[101][101];
int  N;

bool jumping(int y, int x)
{
	if(y < 0 || y >= N || x <0 || x >= N ) return false;
	if(y == N-1 && x == N-1) return true;
	
	int& ret = visited[y][x];
	if(ret != -1) return ret;
	
	int jumpSize = board[y][x] - '0';
	ret = jumping(y+jumpSize,x) || jumping(y,x+ jumpSize);
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	
	cin >>TC;
	
	while(TC--)
	{
		cin >> N;
		memset(visited,-1,sizeof(visited));
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				cin >> board[i][j];
		cout << (jumping(0,0) ? "YES" : "NO") << '\n';
	}

}