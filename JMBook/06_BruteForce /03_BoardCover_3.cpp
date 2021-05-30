#include <iostream>
#include <vector>
using namespace std;

bool board[21][21];
int offset[4][2][2] = {{{1,0},{1,1}},{{0,1},{1,1}},{{1,-1},{1,0}},{{1,0},{0,1}}};
int H,W;

bool isRanged(int y,int x)
{
	return !(y < 0 || y >= H || x < 0 || x >= W);
}

int cntWhite()
{
	int ret = 0;
	
	for(int i=0;i<H;++i)
		for(int j=0;j<W;++j)
			if(!board[i][j]) ret++;
	return ret;
}

int cntCover(int y,int x)
{
	if(x == W) return cntCover(y+1,0);
	if(y == H) return (cntWhite() == 0);
	
	if(board[y][x])
		return cntCover(y,x+1);
	int ret = 0;
	
	for(int i=0;i<4;++i)
	{
		int yoff1 = y + offset[i][0][0];
		int xoff1 = x + offset[i][0][1];
		
		int yoff2 = y + offset[i][1][0];
		int xoff2 = x + offset[i][1][1];
		
		//범위 벗어날 때
		if(!isRanged(yoff1,xoff1) ||!isRanged(yoff2,xoff2))
			continue;
		//이미 검정일 때
		if(board[yoff1][xoff1] || board[yoff2][xoff2])
			continue;
		
		//범위 안이고 모두 하양일 때
		board[y][x] = board[yoff1][xoff1] = board[yoff2][xoff2] = true;
		ret += cntCover(y,x+1);
		
		board[y][x] = board[yoff1][xoff1] = board[yoff2][xoff2] = false;
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
	
	while(TC--)
	{
		char c;
		cin >> H >> W;
		for(int i=0;i<H;++i)
		{
			for(int j=0;j<W;++j)
			{
				cin >> c;
				board[i][j] = (c == '#');
			}
		}
		cout << cntCover(0,0) << '\n';
	}
}