#include <iostream>
using namespace std;
//acmicpc.net/problem/11727

/*
문제명: 타일링2
TL: 1s
ML: 256MB



Good
1. X
2. 
3. 

Bad
1. num과 n을 혼동하였다. -> 문제에서 입력받은 것은 N으로, 함수에서 사용하는 변수는 n으로 표기할 것을 명시한다.
2. 
3. 

conceipt: 
solution: 11726와 동일하다.
Q1: 
A1: 

NEW :
keypoint: 

TU: 10m
TS: 0ms
MS: 2056KB
*/

int n, dp[10001];
const int rest = 10007;

int solve(int num)
{
	if(dp[num] == -1)
		dp[num] = (solve(num-1) + 2*solve(num-2))%rest;
	
	return dp[num];
}
int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> n;
	for(int i=0;i<=n;dp[i++] = -1);
    dp[2] = 3;
    dp[1] = 1;
	if(n < 3)
    {
	    cout << dp[n];
        return 0;
    }
	cout << solve(n);
}
/*
int n, dp[2];

int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> n;
    dp[0] = 3;
    dp[1] = 1;
	if(n < 3)
    {
	    cout << dp[n%2];
        return 0;
    }
    for(int i=3;i<=n;i++)
        dp[i%2] = (2*dp[i%2] +dp[!(i%2)])%10007;	
	cout << dp[(n%2)];
}

*/