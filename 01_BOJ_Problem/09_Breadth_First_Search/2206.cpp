#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
//acmicpc.net/problem/2206

/*
문제명: 벽 부수고 이동하기
TL: 2s
ML: 192MB



Good
1. 
2. 
3. 

Bad
1. 
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 3h
TS: 56ms
MS: 5084KB
*/
	
typedef pair<int, int> p;
typedef pair<bool, pair<int, int>> bii;
int N,M;
bool arr[1001][1001];
bool visited[2][1001][1001];
int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs()
{
	if(N-1 == 0 && M-1 == 0)
		return 1;
	queue<bii> q;
	q.push(bii(false,p(0,0)));
	visited[0][0][0] = true;
	int dis = 2,qsize;
	while(!q.empty())
	{
		qsize = q.size();
		
		for(int i=0;i<qsize;i++)
		{
			bii curr = q.front();
			q.pop();
			
			for(int j=0;j<4;j++)
			{
				int roff = curr.second.first + offset[j][0];
				int coff = curr.second.second + offset[j][1];
				if(roff <0 || roff >= N || coff < 0 || coff >= M || visited[curr.first][roff][coff] || visited[0][roff][coff])
					continue;
				if(arr[roff][coff] == true)
				{
					if(curr.first == true)
						continue;
					else
					{
						q.push(bii(true,p(roff,coff)));	
						visited[0][roff][coff] = true;
					}
				}
				else
					q.push(bii(curr.first,p(roff,coff)));
				
				visited[q.back().first][roff][coff] = true;
				if(roff == N-1 && coff == M-1)
					return dis;
			}				
		}
		dis++;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char c;
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	cout << bfs();
}