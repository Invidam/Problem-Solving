#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

//acmicpc.net/problem/6593

/*
문제명: 상범빌딩
TL: 1s
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

NEW : tuple에 대해 배웠다.
keypoint: 

TU: 45m
TS: 0ms
MS: 2176KB
*/



typedef tuple<int, int, int> t;
char arr[31][31][31];
int offset[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int L,R,C;
t S;

/*
typle에 관해서

생성할 때,
make_tuple(~~);
t s = {a,b,c};

참고할 때
get<0>(t);
	
int ls,rs,cs;
tie(ls,rs,cs) = S;

auto[ls,rs,cs] = S;
처럼 사용가능하다.

if(tie(ls,rs,cs) == E)
	cout << "~";
도 가능하다.

귀찮으면
pair<int, pair<int,int>>을 쓰자.
	
*/
int bfs()
{
	int sec = 1,qsize;
	queue<t> q;
	q.push(S);
	/*
	int ls,rs,cs;
	tie(ls,rs,cs) = S;
	*/
	auto[ls,rs,cs] = S;
	arr[ls][rs][cs] = '#';
	
	while(!q.empty())
	{
		qsize = q.size();
		for(int i=0;i<qsize;i++)
		{
			t curr = q.front();
			q.pop();
			for(int j=0;j<6;j++)
			{
				int loff = get<0>(curr) + offset[j][0];
				int roff = get<1>(curr) + offset[j][1];
				int coff = get<2>(curr) + offset[j][2];
				
				if(loff < 0 || loff >= L || roff < 0 || roff >= R || coff < 0 || coff >= C || arr[loff][roff][coff] == '#' )
					continue;
				if(arr[loff][roff][coff] == 'E')
					return sec;
				else if(arr[loff][roff][coff] == '.')
				{
					//flag_escape = true;
					q.push({loff,roff,coff});
					arr[loff][roff][coff] = '#';
				}
				
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
	while(1)
	{
		cin >> L >> R >> C;
		if(L==0&&R==0&&C==0)
			break;
		for(int i=0;i<L;i++)
		{
			for(int j=0;j<R;j++)
			{
				for(int k=0;k<C;k++)
				{
					cin>>arr[i][j][k];
					if(arr[i][j][k] == 'S')
						S = {i,j,k};
				}
			}
		}
		int ans = bfs();
		if(ans)
			cout <<"Escaped in "<< ans << " minute(s).\n";
		else
			cout <<"Trapped!\n";
		
	}
}