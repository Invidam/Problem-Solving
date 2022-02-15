#include <iostream>
using namespace std;
//acmicpc.net/problem/11057

/*
문제명: 오르막 수
TL: 1s
ML: 256MB



Good
1. 잘 응용하였다.
2. 
3. 

Bad
1. 
2. 
3. 

conceipt: 쉬운 계단수와 바슷한 문제라는 생각이 들었다.
solution: dp[10]을 선언하여 마지막 자리수가 i일 때, 조건에 맞는 수들의 수를 배열 안에 넣었다.
Q1: 
A1: 

NEW :
keypoint: 

TU: 10m
TS: ms
MS: KB
*/

int dp[10] = {1,1,1,1,1,1,1,1,1,1};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);		
	int N,sum = 0;
	cin >> N;
	
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=j+1;k<10;k++)
			{
				dp[j] += dp[k]%10007;
				dp[j] %= 10007;
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		sum += dp[i]%10007;
		sum %= 10007;
	}
	cout << sum;
}

