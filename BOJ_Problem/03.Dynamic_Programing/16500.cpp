#include <iostream>
#include <string>
using namespace std;
//acmicpc.net/problem/16500
16500 문자ㅕ판별 2 512
/*
문제명: 문자열 판별
TL: 2s
ML: 512MB



Good
1. 구현을 잘했다. (string 라이브러리가 아닌 스스로 짜서 효율적으로 해결하였다.)
2. 
3. 

Bad
1. 기준점을 잘못 설정하였다. -> dp[idx]에 해당하는 idx를 기준점으로 하여, idx가 움직일 때에 따라 함수가 변화하게끔 설계해야 한다. (이번 문제에서는 n개의 문자열 a[n]을 기준으로 하여 해결에 어려움이 있었다.)
2. 
3. 

conceipt: 
solution: n번째부터 s의 마지막까지 주어진 a로 가득채울 수 있는지 확인한다.
Q1: 
A1: 

NEW : string 라이브러리에 대해 좀 더 알게 되엇다.
keypoint: 

TU: ?m
TS: 0ms
MS: 2048KB
*/


int dp[101], N;
string s, a[101];

int solve(int n)
{
	if(n > s.length())
		return 0;
	if(n == s.length())
		return 1;
	if(dp[n] != -1)
		return dp[n];
	for(int i=0;i<N;i++)
	{
		if(s[n] == a[i][0] && a[i].length() + n <= s.length())
		{
			int j;
			for(j=0;j<a[i].length();j++)
				if(s[n+j] != a[i][j]) 
					break; // 모두같다면 j = a[i].length() 아니라면 그보다 작은 수.
			
            if(j == a[i].length() && solve(n+j) == 1)
			{
				dp[n] = 1;
				return dp[n];
			}
				
		}
	}
	dp[n] = 0;
	return dp[n];
	
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> N;
	
	for(int i=0;i<N;i++)
		cin >> a[i];
	for(int i=0;i<s.length();i++)
		dp[i] = -1;
	cout << solve(0);
}