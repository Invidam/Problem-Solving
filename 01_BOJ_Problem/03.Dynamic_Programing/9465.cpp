#include <iostream>
//acmicpc.net/problem/9465

/*
문제명: 스티커
TL: 1s
ML: 256MB



Good
1. dp, 메모이제이션에 대해 직접 경험하였다.
2. 스스로 풀었을 때, 메모리를 줄이게 짰다.
3. 

Bad
1. 메모이제이션을 사용할 때, 재귀 처리의 조건(입력 인자)와 같은 배열을 선언해야 한다. [이 부분에 대해 용량을 줄이기 위해 다르게 작성하였는데 그것 때문에 시간초과가 되는 듯하다.].
2. dp에는 재귀 함수의 결괏값이 들어간다. 즉 if(arr[][] == -1) return arr[][]가 되어야 한다. 
3. 

conceipt: 여러 경우의 수에 따른 값이 어떻게 변하는 지 배열에 저장시킨다.
solution: 0,1,2 (선택X, 위선택, 아래선택) 시에 어떠한 숫자 합을 가지는 지를 dp를 이용하여 넣어 놓는다.
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h 30m
TS: 116ms
MS: 8532KB
*/

int TC,N;
int score[2][100001];
int dp[3][100001];
using namespace std;
int solve(int last, int idx) {
	if(idx == N)
		return 0;
	else if(dp[last][idx] != -1)
		return dp[last][idx];
	else
	{
		int ret = solve(0,idx+1);
		if(last != 1)
			ret = std::max(ret,solve(1,idx+1) + score[0][idx]);
		if(last != 2)
			ret = std::max(ret,solve(2,idx+1) + score[1][idx]);
		dp[last][idx] = ret;
		
		return ret;
	}
}
int main()
{	
    ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<3;j++)
				dp[j][i] = -1;
			cin >> score[0][i];
		}
		for(int i=0;i<N;i++)
			cin >> score[1][i];
		cout << solve(0,0) << '\n';
    }
}