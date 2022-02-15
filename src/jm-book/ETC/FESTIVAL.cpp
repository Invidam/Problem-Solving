#include <iostream>
using namespace std;
//algospot.com/judge/problem/read/FESTIVAL

/*
문제명: 록 페스티벌
TL: 20s
ML: 64MB



Good
1. precision 처리.
2. 
3. 

Bad
1. 처음접하는 저지다보니 낯설었음.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 40m
TS: 40ms
MS: 779KB
*/

//1. 컴파일 에러 / 100'1로 선언 ( gcc라 안되나봄)
//2. 오답 /for문 범우 에러 (32줄,  <=로 해주어야 1,1같은 경우 처리.)
//3. 오답 /dp 초기화 안함. 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N,L,teams, arr[1001], dp[1001];
	double min_avg,tmp;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N >> L;
		
		fill(dp,dp+1001,0);
		teams = L;
		min_avg = 1000001;
	  
		for(int i=0;i<N;i++)
		{
			cin >> arr[i];
		}
		
		
		while(1)
		{
			for(int i=0;i<=N-teams;i++)
			{
				if(teams == L)
					for(int j=0;j<teams;j++)
						dp[i] += arr[i+j];
				else
					dp[i] += arr[i+teams -1];
			  
				tmp = (double)dp[i]/teams;
			  
				if(min_avg > tmp)
					min_avg = tmp;
			}
		  
			teams++;
			if(teams > N)
				break;
		}
		cout << fixed;
		cout.precision(8);
		
		cout << min_avg << '\n';
	}
}