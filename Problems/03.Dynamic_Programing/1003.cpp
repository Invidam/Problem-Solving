#include <iostream>
//acmicpc.net/problem/1003

/*
문제명: 피보나치 함수
TL: 0.25s
ML: 128MB



Good
1. 오류 없이 잘 해결함
2. 
3. 

Bad
1. 문제를 잘 못 이해했다 읽기만 하면 되엇는데
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint:  0 ,1을 몇번 실행했는 지 저장

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