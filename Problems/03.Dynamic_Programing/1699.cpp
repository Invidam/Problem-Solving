#include <iostream>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/1699

/*
문제명: 제곱수의 합
TL: 2s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. n^2이 되면 시간초과가 될까봐 다른 방식으로 풀다가 해결하지 못하였다.
2. 시간복잡도는 O(n^2)이 아니라, O((n^(1/2))^2) 이므로, 동전 2와 같은 방법으로 해결하여도 지장이 없었다. (i*i <= 10000을 이용하여 i가 318부분인걸 추측했어야 했다. )
3. 문제를 풀며, 시간복잡도가 바뀔만한 게 있으면 바뀐 시간복잡도에 대해서 해결을 고민하기.
4. 너무 오랜 시간 풀면 다른 방법을 고안하기.

conceipt: 
solution: 
Q1: 
A1: 

NEW : x^2 + y^2 != 3z^2  
keypoint: 

TU: 1d
TS: 44ms
MS: 2408KB
*/



int dp[100001],N,sqr[318],idx;

int solve(int n)
{
	if(dp[n] != -1)
		return dp[n];
	dp[n] = 100000;
	for(int i=idx-1;i>=0;i--)
	{
		if(n - sqr[i] > 0 && dp[n] > solve(n-sqr[i]) + 1)
			dp[n] = dp[n-sqr[i]] + 1;
	}
	return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> N;
	for(int i=0;i<=N;i++)
		dp[i] = -1;
	for(int i=0;i<=N && i*i <= 100000; i++)
	{
		sqr[idx++] = i*i;
		dp[i*i] = 1;
		if(N == i*i)
		{
			cout << 1;
			return 0;
		}
	}
	cout << solve(N);
}