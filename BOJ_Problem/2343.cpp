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
(low +1 < hi )일 때	-> cout << lo는 [initial lo, initial hi)을 의미함.
					 -> cout << hi는 (initial lo,initial hi]을 의미함. 
이번 문제같은 경우는 원하는 조건일 때, hi = mid로 갱신되므로 hi에 원하는 값이 들어가므로
cout << hi를 사용해야 한다. 또한, (lo,hi]이므로 가능한 범위였던 1~sum 중에 lo는 0, hi는 sum이 들어가야 한다.
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

