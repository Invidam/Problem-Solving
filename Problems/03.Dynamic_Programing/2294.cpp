#include <iostream>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/2294

/*
문제명: 동전 2
TL: 1s
ML: 128MB



Good
1. MAX를 이용하여 간편하게 짰다
2. dp[num] 값을 tmp처럼 사용하여 메모리 아꼈다.
3. k보다 큰 값을 버려 시간 단축했다.

Bad
1. [+]sort시, arr+n-1까지만 된다.
2. 반례 잘 못 찾았다. 3 15 14 14 14 일 때가 반례였다.
3. 출력을 하는 방식이 조금 지엽적이라 느껴졌다.

conceipt: 무난한 dp문제였다.
solution: 동전의 가격을 기준으로 dp 사용했다.
Q1: 
A1: 

NEW : X
keypoint: 

TU: 1h
TS: 0ms
MS: 1140KB
*/

int n,k,tmp,cnt;
int coin[101];//1038 ~
int dp[10001];
const int MAX = 10001;

int solve(int num) // p :숫자  / r : 횟수
{
	int m = MAX;
	if(dp[num] != -1 || dp[num] >= MAX) // 이미 계산 되거나 나올 수 없는 경우일 때
		return dp[num];
	for(int i=n-1;i>=0;i--)
		if(num - coin[i] > 0 && m > solve(num - coin[i]))
			if(dp[num - coin[i]] != -1)
				m = dp[num - coin[i]];
	
	dp[num] = m+1;
	return dp[num];
}
int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> n >> k;
	for(int i=0;i<=10000;i++)
		dp[i] = -1;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin >> tmp;
		if(tmp > k || dp[tmp] == 1)
		{
			coin[i] = k+1;
			cnt++;
		}
		else
		{
			coin[i] = tmp;
			dp[coin[i]] = 1;
		}
	}
	n -= cnt;
	if(n == 0)
	{
		cout << "-1";
		return 0;	
	}
	sort(coin,coin+n+cnt);
	if(solve(k) < MAX)
		cout << dp[k];
	else
		cout << "-1"
}