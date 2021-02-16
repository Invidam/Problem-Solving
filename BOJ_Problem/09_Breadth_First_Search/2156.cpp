#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
//acmicpc.net/problem/2156

/*
문제명: 탈출
TL: 1s
ML: 128MB



Good
1. 같은 문제였지만, 잘 풀었다.(시간 단축)
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

TU: 28m
TS: 0ms
MS: 2156KB
*/


typedef pair<int, int> p;
int R,C;
char arr[51][51];
int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
p Hedgehog;
vector<p> Water;


int bfs()
{
	int time = 1,qsize;
	queue<p> q;
	q.push(Hedgehog);
	for(auto& dis : Water)
		q.push(dis);
	
	while(!q.empty())
	{
		qsize = q.size();
		
		for(int i=0;i<qsize;i++)
		{
			p curr = q.front();
			char stat_curr = arr[curr.first][curr.second];
			q.pop();
			
			for(int j=0;j<4;j++)
			{
				int roff= curr.first + offset[j][0];
				int coff= curr.second + offset[j][1];
				char stat_next = arr[roff][coff];
				bool flag_water = false;
				if(stat_next == 'D' && stat_curr == 'S')
					return time;
				if(roff < 0 || roff >= R || coff < 0 || coff > C || stat_next != '.')
					continue;
				if(stat_curr == 'S')
				{
					for(int k=0;k<4;k++)
					{
						int rroff = roff + offset[k][0];
						int ccoff = coff + offset[k][1];
						if(rroff < 0 || rroff >= R || ccoff < 0 || ccoff > C)
							continue;
						if(arr[rroff][ccoff] == '*')
						{
							flag_water = true;
							break;
						}
					}
				}
				if(flag_water)
					continue;
				
				arr[roff][coff] = stat_curr;
				q.push(p(roff,coff));
				/*
				for(int t1=0;t1<R;t1++)
				{
					for(int t2=0;t2<C;t2++)
					{
						cout << arr[t1][t2];
					}
					cout <<'\n';
				}
				cout <<"============\n";
				*/
			}
		}
		time++;
	}
	
	return 0;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 'S')
				Hedgehog = p(i,j);
			else if(arr[i][j] == '*')
				Water.push_back(p(i,j));
		}
	}
	
	int ans = bfs();
	
	if(ans)
		cout << ans;
	else
		cout <<"KAKTUS";
}