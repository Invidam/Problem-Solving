#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
//acmicpc.net/problem/7576

/*
문제명: 토마토
TL: 1
ML: 256



Good
1. const char로 구분
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

TU: 20m
TS: 76ms
MS: 11376kb
*/


typedef pair<int, int> p;
int N,M;
char arr[1001][1001];
int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int tomato_max,ripe_tomato_size;
vector<p> ripe_tomato;
const char RIPE = 'a';
const char RAW = 'b';
const char EMPTY = 'c';
int bfs()
{
	queue<p> q;
	if(ripe_tomato_size == tomato_max)
		return 0;
	for(int i=0;i<ripe_tomato.size();i++)
		q.push(ripe_tomato[i]);
	int day_cnt = 1,qsize;
	
	while(!q.empty())
	{
		qsize = q.size();
		for(int i=0;i<qsize;i++)
		{
			p curr = q.front();
			q.pop();
			
			for(int j=0;j<4;j++)
			{
				int roff = curr.first + offset[j][0];
				int coff = curr.second + offset[j][1];
				
				if(roff < 0 || roff >= N || coff <0 || coff >= M || arr[roff][coff] != RAW)
					continue;
				
				arr[roff][coff] = RIPE;
				ripe_tomato_size++;
				q.push(p(roff,coff));
				//cout << "sz : " << ripe_tomato_size << '\n';
				if(ripe_tomato_size == tomato_max)
					return day_cnt;
			}
		}
		day_cnt++;
	}
	
	return -1;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tmp;
	cin >> M >> N;
	tomato_max = M * N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin >> tmp;
			if(tmp == 1)
			{
				arr[i][j] = RIPE;
				ripe_tomato.push_back(p(i,j));
			}
			else if(tmp == 0)
				arr[i][j] = RAW;
			else
			{
				arr[i][j] = EMPTY;
				tomato_max--;
			}
			// a: 익음 b : 익지않음 c :토마토 없음
		}
	}
	ripe_tomato_size = ripe_tomato.size();
	cout << bfs();
}