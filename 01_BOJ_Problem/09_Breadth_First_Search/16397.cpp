#include <iostream>
#include <queue>
using namespace std;
//acmicpc.net/problem/16397

/*
문제명: 탈출
TL: 1s
ML: 256MB



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

TU: 1h
TS: 0ms
MS: 2248KB
*/

int N,T,G;
const int MAX_RANGE = 99'999;
int visited[100'000];

int bfs()
{
	if(N == G)
		return 0;
	queue<int> q;
	q.push(N);
	visited[N] = true;
	int qsize,cnt_button = 1;
	
	while(!q.empty())
	{
		qsize = q.size();
		
		for(int i=0;i<qsize;i++)
		{
			int curr = q.front();
			q.pop();
			
			if(curr + 1 <= MAX_RANGE && !visited[curr+1])
			{
				if(curr+1 == G)
				{
					//cout << curr;
					return cnt_button;
				}
				q.push(curr+1);
				visited[curr+1] = true;
			}
			if(curr < 50000)
			{
				int tmp = 2*curr;
				int for_deduct = MAX_RANGE + 1;
				//cout << curr << " => "; 
				while(for_deduct)
				{
					if(tmp / for_deduct)
					{
						tmp -= for_deduct;
						break;
					}
					else
						for_deduct /= 10;
				}
				if(tmp == G)
				{
					//cout << curr;
					return cnt_button;
				}
				if(!visited[tmp])
				{
					q.push(tmp);
					visited[tmp] = true;
				}
					
				//cout <<tmp << '\n';
			}
		}
		cnt_button++;
		if(cnt_button > T)
			return -1;
	}
	return -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> T >> G;
	int ans = bfs();
	
	if(ans != -1)
		cout << ans;
	else
		cout << "ANG";
}