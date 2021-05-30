#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

//acmicpc.net/problem/1309

/*
문제명: 교환
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
1. set.count에 대해 배웠다. (set안에 있는 요소의 갯수 출력)
2. max함수가 string도 가능하다는 것을 배웠다. (숫자로된 문자열의 경우.)
keypoint: 

TU: 1h 45m
TS: 8ms
MS: 2156KB
*/



const int MAX_NUM = 1'000'000;
string N = "";
int K,M;
int max_ans = 0;

void bfs()
{
	int cnt = 0,qsize;
	string ret = "0";
	queue<string> q;
	q.push(N);
	
	if((M == 2 && N[1] == '0') || M == 1) 
	{
		cout << -1;
		return;	
	}
	
	//10이 들어온 경우, K번을 바꿀 수 없으므로 -1 출력한다.
	// 1~9가 들어온 경우 1버도 바꿀 수 없으므로 -1 출력한다.
	
	while(cnt < K)
	{
		qsize = q.size();
		set<string> s;
		for(int i=0;i<qsize;i++)
		{
			string curr = q.front();
			
			for(int j=0;j<M;j++)
			{
				for(int k=j+1;k<M;k++)
				{
					if(j == 0 &&  curr[k] == '0')
						continue;
					
					string next = curr;
					swap(next[j],next[k]);
					
					if(s.count(next))
						continue;
					
					q.push(next);
					s.insert(next);
				}
			}	
			q.pop();
		}
		cnt++;
	}
	while(!q.empty())
	{
		ret = max(ret,q.front());
		q.pop();
	}
	cout<< ret;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char c;
	while(1)
	{
		cin.get(c);
		if(c < '0' || c >'9')
			break;
		N+= c;
	}
	cin >> K;
	M = N.length();
	//N = 입력받은 수의 문자열 K = 문자열의 자릿수 max_ans = 입력받은 수(최댓값의 기준이 될 수)
	
	bfs();
}