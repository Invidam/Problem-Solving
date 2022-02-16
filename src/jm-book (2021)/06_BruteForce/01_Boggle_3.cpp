#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
//acmicpc.net/problem/BOGGLE

/*
문제명: 보글게임
TL: 10s
ML: 64MB

TU: 30m
TS: 0ms
LEN: 1.5kb


Good
1. 예전에 비한 tu시간단축
2. dp인자의 변화로 인한 ts시간 단축 (4ms -> 0ms)

Bad
1. X

IAN
1. 헷갈린 부분: 함수 종료를 어느부분에서 해야하는 지.

(정답: 주어진 문자열의 길이(length())과 idx가 같아질 때)

NEW
1. X


Q1: X
A1: X


Solution: 
1. 재귀함수를 이용해, board에서 offset의 해당 단어의 다음글자가 있는지를 확인해 isTrue함수에 저장시킨다.
2. dp를 이용해 시간을 단축한다
(기존: 25*(문자열크기)*8^(문자열 길이) -> 25*(문자열크기)*문자열길이)

Approach: 
1. offset을 이용한 bfs문제들.

Clue:
1. 5x5라고 주어진 board + 인접글자를 확인

Reconstruction : 
*/

*/
vector<string> wordList;
int cache[6][6][11][11];
int offset[8][2] = {{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1}};
char board[5][5];
int hasWord(int y,int x,int listIdx, int idx)
{
	int& ret = cache[y][x][listIdx][idx];
	if(ret != -1) return ret;
	
	if(wordList[listIdx].length() <= idx+1) return ret = 1;
	
	for(int i=0;i<8;++i)
	{
		int yoff = y + offset[i][0];
		int xoff = x + offset[i][1];
		
		if(yoff < 0 || yoff >= 5 || xoff <0 || xoff >=5)
			continue;
		if(wordList[listIdx][idx+1] != board[yoff][xoff])
			continue;
		
		if(hasWord(yoff,xoff,listIdx,idx+1))
			return ret = 1;
	}
	return ret = 0;
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
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)
				cin >> board[i][j];
		
		int N;
		cin >> N;
		wordList = vector<string>(N);
		vector<bool> isTrue(N,false);
		for(int i=0;i<N;++i)
			cin >> wordList[i];
		
		//hasWord(y,x에서/ n번째 word의 idx부터를 찾을 수 있는지 리턴)
		for(int i=0;i<N;++i)
		{
			
			for(int j=0;j<5;++j)
			{
				for(int k=0;k<5;++k)
				{
					if(wordList[i][0] == board[j][k])
					{
						if(hasWord(j,k,i,0))
						{
							isTrue[i] = true;
							break;
						}
					}
				}
				if(isTrue[i]) break;
			}
		}
		
		for(int i=0;i<N;++i)
		{
			string ans = isTrue[i] ? "YES\n" : "NO\n";
			cout << wordList[i] << " " << ans;
		}
	}
}