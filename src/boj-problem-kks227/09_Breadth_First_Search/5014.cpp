#include <iostream>
#include <queue>
using namespace std;
//acmicpc.net/problem/5014

/*
문제명: 스타트링크
TL: 1s
ML: 256MB



Good
1. 
2. 
3. 

Bad
1. size설정시 +1하기.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 18m
TS: 12ms
MS: 2992KB
*/

int F,S,G, UD[2];
bool visited[1'000'001];

int bfs()
{
	if(S == G)
		return 0;
	int qsize,cnt = 1;
	queue<int> q;
	q.push(S);
	visited[S] = true;
	while(!q.empty())
	{
		qsize = q.size();
		for(int i=0;i<qsize;i++)
		{
			int curr = q.front();
			q.pop();
			
			for(int j=0;j<2;j++)
			{
				int floor_off = curr + UD[j];
				//cout << floor_off << '\n';
				if(floor_off < 1 || floor_off > F || visited[floor_off])
					continue;
				//cout <<" safe " <<floor_off << '\n';
				if(floor_off == G)
					return cnt;
				visited[floor_off] = true;
				q.push(floor_off);
			}
		}
		cnt++;
	}
	return -1;	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> F >> S >> G >> UD[0] >> UD[1];
	UD[1] = -1 * UD[1];
	
	int ans = bfs();
	if(ans != -1)
		cout << ans;
	else
		cout <<"use the stairs";
}