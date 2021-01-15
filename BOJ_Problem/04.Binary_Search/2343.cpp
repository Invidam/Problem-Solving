#include <iostream>
using namespace std;
//acmicpc.net/problem/2343

/*
문제명: 기타 레슨
TL: 2s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. lo선정, while문 조건, 범위에따른 lo또는 hi선정에 실수가 잦았다.

방법 1.
조건	lo + 1 < hi
참	hi = mid
거짓	lo = mid
cout << hi
: hi 가 ans, lo가 ans-1에 위치.
: 범위는 (initial lo, initial hi]

방법 2.
조건	lo <= hi
참	hi = mid - 1
거짓	lo = mid + 1
cout << lo
: hi가 ans-1 lo = ans에 위치.
: 범위는 [initial low, inital MAX] ㅇㅎ
장점 : 범위가 가시성 높으며, 좀더 공격적으로 범위를 줄여나간다.

방법 2가 나은 듯 하다.

2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h40m
TS: 12ms
MS: 2048KB
*/


int N,M,arr[100'001],sum,ans = 100'000;
long long mid;
int lo,hi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
		hi += arr[i];
	}
	if(M == 1)
	{
		cout << hi;
		return 0;
	}
	while(lo +1 <  hi)
	{
		mid = (lo + hi) / 2;
		int cnt = 0,i;
		sum = 0;
		for(i=0;i<N;i++)
		{
			if(sum  > mid- arr[i])
			{
				sum = 0;
				i--;
				if(++cnt >= M)
					break;
				
				continue;
			}
			else
				sum += arr[i];
		}
		if(i == N)
			hi = mid;
		else
			lo = mid;
	}
	cout << hi;
}

