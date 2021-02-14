#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> p;
//acmicpc.net/problem/7562

/*
문제명: 나이트의 이동
TL: 1s
ML: 128MB



Good
1. 잘 복습하였다.
2. 
3. 

Bad
1. visited[][] = false는 pop시가 아니라 추가 시에 한다. [무조건]
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 40m
TS: 24ms
MS: 2236KB
*/


/*

memset(arr,value, sizeof(arr));
fill(&arr[0][0],&arr[N-1][N-1],value);

memset이 더 빠르다. + cstring을 써야한다.

*/

int TC,L,r_knight,c_knight,r_end,c_end;
bool visited[301][301];
int offset[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
int bfs()
{
	if(r_knight == r_end && c_knight == c_end)
		return 0;
	fill(&visited[0][0],&visited[300][300], false);
	int level = 1, qsize;
	p curr;
	visited[r_knight][c_knight] = true;
    
	queue<p> q;
	q.push(p(r_knight,c_knight));
    
	while(!q.empty())
	{
		qsize = q.size();
		for(int i=0;i<qsize;i++)
		{
			curr = q.front();
			q.pop();
			for(int j=0;j<8;j++)
			{
				int roff = curr.first + offset[j][0];
				int coff = curr.second + offset[j][1];
				
				if(roff < 0 || roff >= L || coff <0 || coff >= L || visited[roff][coff])
					continue;
				
				if(roff == r_end && coff == c_end)
					return level;
				
				q.push(p(roff,coff));
				visited[roff][coff] = true;
			}
		}
		level++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >>TC;
	while(TC--)
	{
		cin >> L >> r_knight >> c_knight >> r_end >> c_end;
		cout << bfs() << '\n';
	}
}