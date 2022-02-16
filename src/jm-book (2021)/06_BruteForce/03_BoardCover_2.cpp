#include <iostream>
using namespace std;

int TC,H,W;
bool board[21][21];
int offset[4][3][2] = {{{0,0},{1,0},{0,1}},{{0,0},{0,1},{1,1}},{{0,0},{1,0},{1,1}},{{0,0},{1,0},{1,-1}}};
bool setBoard(int offsetType, int y, int x, bool coverType)
{
	int L_x[3];
	int L_y[3];
	
	for(int i=0;i<3;++i)
	{
		L_y[i] = y + offset[offsetType][i][0];
		L_x[i] = x + offset[offsetType][i][1];
		if(L_y[i]<0 || L_y[i]>= H || L_x[i] <0 || L_x[i] >= W)
			return false;
		if(board[L_y[i]][L_x[i]] == coverType)
			return false;	
	}
	
	for(int i=0;i<3;++i)
		board[L_y[i]][L_x[i]] = coverType;
	
	
	return true;
}

int coverBoard()
{
	int y_white = -1, x_white = -1;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			if(board[i][j] == true)
			{
				y_white = i;
				x_white = j;
				break;
			}
		}
		if(y_white != -1)
			break;
	}
	if(y_white == -1)
		return 1;
	
	int ret =0;
	
	for(int i=0;i<4;i++)
	{
		if(setBoard(i,y_white,x_white,false))
		{
			ret += coverBoard();
			
			setBoard(i,y_white,x_white,true);
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	while(TC--)
	{
		char c;
		cin >> H >>W;
		for(int i=0;i<H;++i)
		{
			for(int j=0;j<W;++j)
			{
				cin >> c;
				if(c == '#')
					board[i][j] = false;
				else if(c == '.')
					board[i][j] = true;
			}
		}
		cout << coverBoard() <<'\n';
	}
}