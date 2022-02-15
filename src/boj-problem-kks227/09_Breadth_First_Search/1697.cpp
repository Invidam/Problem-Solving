#include <iostream>
#include <queue>
using namespace std;
//acmicpc.net/problem/1697

/*
문제명: 숨바꼭질
TL: 2s
ML: 128MB



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

TU: 15m
TS: 0ms
MS: 2248KB
*/


int N,K;
bool visited[100'001];
const int DIS_MAX = 100'000;

int bfs()
{
	if(N >= K)
		return N-K;
	queue<int> q;
	q.push(N);
	int qsize, time = 1;
	visited[N] = true;
	
	while(!q.empty())
	{
		qsize = q.size();
		
		for(int i=0;i<qsize;i++)
		{
			int curr = q.front();
			q.pop();
			if(!visited[curr-1] && (curr -1) >= 0) 
			{
				if(curr-1 == K)
					return time;
				q.push(curr-1);
				visited[curr-1] = true;
			}
			if((curr+1 <= DIS_MAX) && !visited[curr+1])
			{
				if(curr+1 == K)
					return time;
				q.push(curr+1);
				visited[curr+1] = true;
			}
			if((2*curr) <= DIS_MAX && 2*curr >= 0 && !visited[2*curr])
			{
				if(2*curr == K)
					return time;
				q.push(2*curr);
				visited[2*curr] = true;
			}
		}
		time++;
	}
	return -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	
	cout << bfs();
}