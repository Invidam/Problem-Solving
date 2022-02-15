#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

const int TOWER_SIZE = 4,INF = 987654321;
int N;
int sgn(int n) {if(!n) return 0; return n > 0 ? 1 : -1;}
int incr(int n) {if(n < 0) return n-1; return n+1;}

int getValue(int mask, int idx)
{
	return (mask >> (idx * 2)) & (3); 
}

int setValue(int mask, int idx, int value)
{
	return mask & ~(3 << (idx * 2)) | (value << (idx * 2));
}

void putValue(int& mask, int idx, int value)
{
	mask =  mask & ~(3 << (idx * 2)) | (value << (idx * 2));
}

int c[1 << (24)];
int bfs(int start, int finish)
{
	if(start == finish) return 0;
	
	memset(c,0,sizeof(c));
	queue<int> q;
	c[start] = 1;
	c[finish] = -1;
	q.push(start);
	q.push(finish);
	
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		int cost = c[here];
		vector<int> top(4,INF);
		for(int i=N-1;i>=0;--i)
			top[getValue(here,i)] = i;
		
		for(int i=0;i<TOWER_SIZE;++i)
		{
			if(top[i] == INF) continue;
			
			for(int j=0;j<TOWER_SIZE;++j)
			{
				if(i == j) continue;
				if(top[i]  > top[j]) continue;
				//top[i]에 있었던 원판의 위치가 있는 인덱스
				int IndexToMove = top[i];
				int ElemToMove = j;
				
				int next;
				next = here;
				next = setValue(next,IndexToMove,ElemToMove);
				
				if(c[next] != 0)
				{
					if(sgn(c[next]) != sgn(cost))
						return abs(c[next]) + abs(cost) -1;
					continue;
				}

				c[next] = incr(cost);
				q.push(next);
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
	int TC, K;
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		int n;
		int startValue = 0, finishValue= 0;
		
		for(int i=0;i<TOWER_SIZE;++i)
		{
			cin >> K;
			for(int j=0;j<K;++j)
			{
				cin >> n;
				n--;
				//n번째 크기인 원판은 i번째 기둥에 있어야 한다.
				// arr[n] = i 이어야 한다.
				putValue(startValue,n,i);
			}
		}
		
		for(int i=0;i<N;++i)
		{
			//모든 원판을 맨 오른쪽에 넣는다.	
			putValue(finishValue,i,TOWER_SIZE-1);
		}
		cout << bfs(startValue,finishValue) << '\n';
	}
}