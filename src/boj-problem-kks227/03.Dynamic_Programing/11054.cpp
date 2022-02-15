#include <iostream>
using namespace std;
//acmicpc.net/problem/11054

/*
문제명: 카드 구매하기
TL: 1s
ML: 256MB



Good
1. 비슷한 유형을 계속 풀다보니 실력이 상승한 것 같다.
2. for문에서, i/2+1을 쓰며 시간을 단축시켰다.
3. 계획했던 문제해결 절차를 따라 문제를 해결하였다.

Bad
1. 탑다운 방식과 바텀업 방식 중 바텀업 방식을 사용하는 것이 배열 선언에서 메모리를 아낄 수 있었는데 무작정 탑다운을 고집한 것 같다.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 20m
TS: 0ms
MS: 2020KB
*/

int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> dp[i+1];
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<i/2+1;j++)
			if(dp[i] < dp[j] + dp[i-j])
				dp[i] = dp[j] + dp[i-j];
	}
	cout << dp[N];
}


/*
#include <iostream>
using namespace std;

int dp[1001],p[1001];

int solve(int n)
{
	if(dp[n] != -1)
		return dp[n];
	dp[n] = p[n];
	for(int i=1;i<n/2+1;++i)
		if(n-i > 0 &&  dp[n]< solve(n-i) + solve(i))
			dp[n] = dp[n-i] + dp[i];
	return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> p[i+1];
		dp[i+1] = -1;
	}
	dp[1] = p[1];
	cout << solve(N);
}
*/