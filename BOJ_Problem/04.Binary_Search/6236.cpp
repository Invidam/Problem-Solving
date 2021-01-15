#include <iostream>
using namespace std;
//acmicpc.net/problem/6236

/*
문제명: 예산
TL: 1s
ML: 128MB



Good
1. 잘 복습하였고, 문제해결 전략을 고안해보았다.
2. 
3. 

Bad
1. M == 1을 M =1이라고 하여 한번 틀렸다.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 20m
TS: 2408ms
MS: 16KB
*/


int N,M,arr[100'001],sum,lo,hi;
long long mid;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
		if(hi < arr[i])
			hi = arr[i];
	}
	hi *=N;
	if(M == 1)
	{
		for(int i=0;i<N;i++)
			sum += arr[i];
		cout << sum;
		return 0;
	}
	while(lo <=  hi)
	{
		mid = (lo + hi) / 2;
		int cnt = 0,i;
		sum = mid;
		for(i=0;i<N;i++)
		{
			if(sum  < arr[i])
			{
				sum = mid;
				i--;
				if(++cnt >= M)
					break;
				continue;
			}
			else
				sum -= arr[i];
		}
		if(i == N)
			hi = mid-1;
		else
			lo = mid+1;
	}
	cout << lo;
}