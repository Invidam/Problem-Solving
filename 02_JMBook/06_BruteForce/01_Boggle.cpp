#include <iostream>
#include <queue>
#include <utility>
using namespace std;
//algospot.com/judge/problem/read/BOGGLE

/*
문제명: BOGGLE
TL: 10s
ML: 64MB

TU: 3h
TS: 4ms
LEN: 1.4KB


Good
1. 오랜만에, 어떠한 유형에 구애받지 않고 문제를 풀어봤던 것 같다.

Bad
1. 

IAN
1. 문제를 정확히 이해하지 못하였다. (이미 갔던 곳에서도 이동이 가능하다고 잘못 이해 하였다.) -> 이로 인해 문제가 꼬였다.
2. curr을 인자로 줄 때, 바꾸지 않아 오류가 생겼었다.
3. BFS 사용이 안되었는데, 모든 가지들이 다른 경우를 뜻하기 때문이었다.

NEW
1. 


Q1: 
A1: 


Solution: 
1. dp에 현재 위치[roff][coff], 방향[k], idx[idx]을 넣어서 확인한다. (시간 초과 방지)
2. 인접한 곳들중에 다음 문자에 들어갈만한 게 있으면 넣는다. 

Approach: 
1. bfs의 좌표문제들과 비슷하였다.

Clue:
1. NxN + offset을 이용한 이동문제.

Reconstruction : 
*/

typedef pair<int, int> p;
bool dp[6][6][9][11];
char board[6][6];
int offset[8][2] = {{1,0},{-1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,-1}};
bool findWord(string& word,int idx,p curr)
{
	if(word.length() <=  idx)
		return true;
	
  	if(idx == 0)
	{
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				if(board[i][j] == word[0])
					if(findWord(word,idx +1 , p(i,j)))
						return true;
		return false;
	}
	for(int k=0;k<8;k++)
	{
		int roff = curr.first + offset[k][0];
		int coff = curr.second + offset[k][1];
		
		if(roff <0 || roff >=  5 || coff < 0 || coff >= 5)
			continue;
		
		if(board[roff][coff] == word[idx])
		{
			if(dp[curr.first][curr.second][k][idx] == false);
			else if(findWord(word,idx +1, p(roff,coff)))
				return true;
			else
				dp[curr.first][curr.second][k][idx] = false;
		}
	}
	
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N;
	
	cin >> TC;
	
	while(TC--)
	{
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				cin >> board[i][j];
		
		cin >> N;
		
		string word;
		for(int i=0;i<N;i++)
		{
			cin >> word;
			cout << word;
			fill(&dp[0][0][0][0],&dp[5][5][8][10],true);
			
			if(findWord(word,0,p(0,0)))
				cout << " YES\n";
			else
				cout << " NO\n";
		}
	}
}

/*
종만북의 주어진 함수를 보고 푼 코드
#include <iostream>
using namespace std;

char board[6][6];
int dp[6][6][9][11];
const int offset[8][2] = {{1,0},{-1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,-1}};

// 해당 위치에서부터 해당 단어가 완성이 되면 true 아니면 fase 리턴
bool hasWord(int y, int x,const string& word) 
{
	
	if(y < 0 || y >=5 || x < 0 || x>=5)
		return false;
	else if(board[y][x] != word[0])
		return false;
	else if(word.size() == 1)
		return true;
	
	for(int i=0;i<8;i++)
	{
		int yoff = y + offset[i][1];
		int xoff = x + offset[i][0];
		
		if(yoff < 0 || yoff >=5 || xoff < 0 || xoff >=5)
			continue;
		
		if(dp[yoff][xoff][i][word.length()] == 1)
			return true;
		else if(dp[yoff][xoff][i][word.length()] == 0)
			return false;
		else if(hasWord(yoff,xoff,word.substr(1)))
		{
			dp[yoff][xoff][i][word.length()] = 1;
			return true;
		}
		else
			dp[yoff][xoff][i][word.length()] = 0;
	}
	return false;
	
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N;
	
	cin >> TC;
	
	while(TC--)
	{
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				cin >> board[i][j];
		
		cin >> N;
		
		string word;
		for(int i=0;i<N;i++)
		{
			cin >> word;
			cout << word;
			
			bool findFlag = false;
			fill(&dp[0][0][0][0],&dp[5][5][8][10],-1);
			for(int j=0;j<5;j++)
			{
				for(int k=0;k<5;k++)
				{
					if(hasWord(j,k,word)) 
					{
						findFlag = true;
						j = 5;
						k = 5;
					}
				}
			}
			
			if(findFlag)
				cout << " YES\n";
			else
				cout << " NO\n";
		}
	}
}

*/