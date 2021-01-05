#include <iostream>
using namespace std;
//acmicpc.net/problem/11726

/*
문제명: 2xn 타일링
TL: 1s
ML: 128MB



Good
1. 배운 것을 잘 복습하였다. (2개의 배열을 이용한 코드 & dp코드)
2. 피보나치에 대한 자료조사를 추가로 하였다. (Q1,A1참고)
3. 

Bad
1. 인덱스 선언에 조금 실수가 있었다. (1,2,3등을 넣어보며 실행 전에 손으로 컴파일해보기.)
2. 
3. 

conceipt: n일 때, 세로 타일 1개를 사용한 후 남은 자리(n-1)을 구한 값 + 가로 타일 2개를 사용하여 남은 자리(n-2)를 더한 값이 정답. --> 피보나치 문제이다.
solution: 중복이 있기에 dp를 사용한다.

Q1: 피보나치 수의 범위를 추정할 수 있을까?
A1: 그래프형이 지수함수 꼴이며 1000와 10000번째를 보았는데, 이 둘이 2^n보다 작으니 f(n) < 2^n이라 할 수 있겠다.
	왜냐하면 2^n = sigma(1~2^n-1) + 1 이기 때문에 2^n을 g(n)이라 한다면
	f(1) < g(1) , f(2) < g(2) 이며, f(n) = f(n-1) + f(n-2) & g(n) = S(g(1),g(n-1)) +1 이므로, f(n) < g(n)이다.
	참고로 f(45)까지가 int범위이다.

NEW :	피보나치 수의 범위
keypoint: 

TU: 5m
TS: 0ms
MS: 2016KB
*/

int n,dp[100001];
const int rest = 10007;

int solve(int num)
{
	if(dp[num] != -1)
		return dp[num];
	
	dp[num] = (solve(num-1) + solve(num-2))%rest;
	return dp[num];
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> n;
	if(n < 3)
    {
	    cout << n;
        return 0;
    }
	for(int i=0;i<=n;i++)
		dp[i] = -1;
	
    dp[0] = 1;
    dp[1] = 1;
	cout << solve(n);	
}
/*
int n, dp[2];

int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> n;
	if(n < 3)
    {
	    cout << n;
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i=1;i<n;i++)
        dp[!(i%2)] = (dp[1] +dp[0])%10007;	
	cout << dp[(n%2)];
}
*/