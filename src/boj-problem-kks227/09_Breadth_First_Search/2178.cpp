#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

//acmicpc.net/problem/2178

/*
문제명: 미로 탐색
TL: 1s
ML: 192MB



Good
1. 
2. 
3. 

Bad
1. dfs와 bfs의 원리를 햇갈려했다.
2. level 부여방식을 새로운 상황에 적용하는 것을 헤맷다.
3. 행 렬 구분 헷갈렸다.

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 50m
TS: 0ms
MS: 2036KB
*/


	
using namespace std;
typedef pair<int, int> p;

int N,M;
//vector<vector<int>> adj;
bool arr[101][101];
bool visited[101][101];
int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int bfs()
{
	int level = 1,qsize;
	
	if(M-1 == 0 && N -1 == 0)
		return 1;
	queue<p> q;
	
	q.push(p(0,0));
	visited[0][0] = true;
	
	while(!q.empty())
	{
		level++;
		qsize = q.size();
		for(int idx=0;idx<qsize;idx++)
		{	
			p curr = q.front();
			visited[curr.first][curr.second] = true;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int roff = curr.first + offset[i][0];
				int coff = curr.second + offset[i][1];

				if(roff >= N || roff < 0 || coff >= M || coff < 0 || visited[roff][coff] || !arr[roff][coff])
					continue;
				q.push(p(roff,coff));
				visited[roff][coff] = true;
				if(roff == N-1 && coff == M-1)
					return(level);
			}
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	
	char c;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin  >> c;
			arr[i][j] =  c - '0';
		}
	}
	
	
	cout << bfs();
}