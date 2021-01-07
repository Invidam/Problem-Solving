#include <iostream>
using namespace std;
//acmicpc.net/problem/1904

/*1
문제명: 01타일
TL: 0.75s
ML: 256MB



Good
1. 문제를 푼 후 다른 사람 코드를 보며 내 코드를 크게 보완하였다(메모리, 시간적인 측면)
2. 
3. 

Bad
1. 문제가 피보나치 수열이라는 것을 고려는 했었는데, 손으로 풀어보는 과정에서 실수가 나와 아니라고 생각했다.
2. 따라서 나만의 방식으로 풀었는데, 이 때 시간 복잡도가 초과된다는 것을 눈치채지 못하였다. (이걸 눈치채고 다른 방법을 고안했어야 했다.)
3. 따라서 시간이 많이 소요되었다.

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h
TS: 8ms
MS: 2016KB
*/

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
    for(int i=0;i<n-1;i++)
    {
		dp[i%2] %= 15746;
        dp[!(i%2)] = (dp[1] +dp[0])%15746;
    }
	cout << dp[!(n%2)];
}