#include <iostream>
using namespace std;
//acmicpc.net/problem/11055

/*
문제명: 가장 큰 증가 부분 수열
TL: 1s
ML: 256MB



Good
1. 상위권에 잇던 코드와 같은 방식으로 해결하였다. (잘 풀었다.)
2. 시간을 얼마 들이지 않고도 잘 풀었다.
3. 

Bad
1. dp[2][1001]로 선언하여 가시성을 떨어트렸다.
2. 
3. 

conceipt: 
solution: idx를 돌며, 자기보다 큰 수들 중 가장 큰 부분 수열을 저장해놓고 자기자신 + 그 수열을 dp[1][idx]에 저장한다. 그 후 가장큰 값을 출력한다.
Q1: 
A1: 

NEW :
keypoint: 

TU: 37m
TS: 0ms
MS: 2024KB
*/

int N,dp[2][1'001],max_num;

int solve(int idx)
{
	if(dp[1][idx] != 0)
		return dp[1][idx];
	
	dp[1][idx] = dp[0][idx];
	int temp = 0;
	for(int i=idx+1;i<N;i++)
	{
		if(solve(i) > temp && dp[0][i] > dp[0][idx])
			temp = dp[1][i];
	}
	dp[1][idx] += temp;
	max_num = max_num > dp[1][idx] ? max_num : dp[1][idx];
	return dp[1][idx];
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> dp[0][i];
	}
	
	dp[1][N-1] = dp[0][N-1];
	
	//max_num = max_num > dp[1][0] ? max_num : dp[1][0];
	solve(0);
	
	cout << max_num;
}