#include <iostream>
//acmicpc.net/problem/1003

/*
문제명: 피보나치 함수
TL: 0.25s
ML: 128MB



Good
1. 오류 없이 잘 해결하였다.
2. 
3. 

Bad
1. 문제를 잘 못 이해하였다. 잘 읽었어야 했다.
2. 
3. 

conceipt: 무난한 dp문제이다.
solution: 바텀업 방식으로 해결하였다.
Q1: 
A1: 

NEW :
keypoint:  f(0) ,f(1)을 몇번 실행했는 지 저장하는 것이다.

TU: 30m?
TS: 0ms
MS: 2016KB
*/

int T;
int cnt[2][41];

int main()
{
	scanf("%d",&T);
	int inp[T];
	for(int i=0;i<T;i++)
		scanf("%d",inp+i);
		
	cnt[0][0] = 1;
	cnt[1][1] = 1;
	
	for(int i=2;i<=40;i++)
	{
		cnt[0][i] += cnt[0][i-2];
		cnt[1][i] += cnt[1][i-2];
		cnt[0][i] += cnt[0][i-1];
		cnt[1][i] += cnt[1][i-1];
	}
	for(int i=0;i<T;i++)
			printf("%d %d\n",cnt[0][inp[i]],cnt[1][inp[i]]);
	
}