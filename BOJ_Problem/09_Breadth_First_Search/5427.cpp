#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> p;
//acmicpc.net/problem/5427

/*
문제명: 불
TL: 1s
ML: 256MB



Good
1. 
2. 
3. 

Bad
1. 범위 생각을 못했다. rroff ccoff의 경우.
2. 내가 생각해낸 답이 올바른지 확인을 해야한다.(언제 할 지는 정확히는 모르겠다.)
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h 30m
TS: 1ms
MS: 256KB
*/


int w,h;
char arr[1002][1002];
int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(p human,vector<p> dis)
{
	int sec = 1,qsize;
	queue<p> q;
	q.push(human);
	for(int i=0;i<dis.size();i++)
		q.push(dis[i]);
	
	while(!q.empty())
	{
		qsize = q.size();
		for(int i=0;i<qsize;i++)
		{
			p curr = q.front();
			q.pop();
			char stat = arr[curr.first][curr.second];
			for(int j=0;j<4;j++)
			{
				int roff = curr.first + offset[j][0];
				int coff = curr.second + offset[j][1];
				bool flag_near_fire = false;
				
				if(roff <0 || roff >= h || coff < 0 || coff >= w)
				{
					if(stat == '@')
						return sec;
					else 
						continue;
				}
                
				if(arr[roff][coff] != '.')
					continue;
                
				for(int k=0;k<4 && stat == '@';k++)
				{
					int rroff = roff + offset[k][0];
					int ccoff = coff + offset[k][1];
					if(rroff <0 || rroff >= h || ccoff < 0 || ccoff >= w)
						continue;
					if(arr[rroff][ccoff] == '*')
					{
						flag_near_fire = true;
						break;
					}
				}
				if(flag_near_fire)
					continue;
				
				arr[roff][coff] = stat;
				q.push(p(roff,coff));
			}
		}
		sec++;
	}
	return 0;
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
		vector<p> dis_fire;
		p dis_human;
		cin >> w >> h;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cin >> arr[i][j];
				if(arr[i][j] == '*')
					dis_fire.push_back(p(i,j));
				if(arr[i][j] == '@')
					dis_human = p(i,j);
			}
		}
		int ans = bfs(dis_human,dis_fire);
		if(ans)
			cout << ans << '\n';
		else
			cout << "IMPOSSIBLE\n";
	}
}