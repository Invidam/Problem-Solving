#include <iostream>
#include <vector>

using namespace std;
char board[6][6];
bool dp[6][6][9][11];
int TC, N;
int offset[8][2]= {{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1}};
bool hasWord(int y, int x, const string& word)
{
	if(word.size() == 0)
		return true;
	else if(y < 0 || y >= 5 || x < 0 || x >=5 || board[y][x] !=word[0])
		return false;
	for(int direction = 0; direction  < 8; ++direction)
	{
		int yoff = y + offset[direction][0];
		int xoff = x + offset[direction][1];
		if(yoff < 0 || yoff >= 5 || xoff < 0 || xoff >=5)
			continue;
		if(dp[yoff][xoff][direction][word.length()] == true);
		else if(hasWord(yoff, xoff, word.substr(1)))
			return true;
		else dp[yoff][xoff][direction][word.length()] =true;
	}
	return false;
}
int main(int argc, char *argv[])
{
	cin >> TC;
	while(TC--)
	{
		
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				cin >> board[i][j];

		string str;
		cin >> N;
		for(int i=0;i<N;i++)
		{
				cin  >> str;
				cout << str;
				bool flagHave = false;
				fill(&dp[0][0][0][0],&dp[5][5][8][10], 0);
				for(int j=0;j<5;j++)
				{
					for(int k=0;k<5;k++)
					{
						if(hasWord(j,k,str)){
							 flagHave = true;
							 break;
						}
					}
					if(flagHave)
						break;
				}
				if(flagHave)
					cout << " YES\n";
				else 
					cout << " NO\n";
		}
				
		
			
	}
}