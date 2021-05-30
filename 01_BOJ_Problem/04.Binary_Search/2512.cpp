#include <iostream>
using namespace std;
//acmicpc.net/problem/2512

/*
문제명: 예산
TL: 1s
ML: 128MB



Good
1. 기존 코드를 잘 응용하였다.
2. 
3. 

Bad
1. sum과 M의 관계에 따라 어떠한 것을 변경해야하는지 결정하지 못하였다. (기존 코드와 다른 부분이 있다는 것을 알게되었다.)
2. long long이 아닌 int를 써도, lo,hi,mid등의 변수는 오버플로우 발생하지 않을 수 있었다.
3. 

conceipt: 
solution: 모든 수의 합이 M보다 작으면 최댓값을 출력 M보다 크면, 상한액을 이분탐색으로 골라 그것을 출력
Q1: 
A1: 

NEW :
keypoint: 

TU: 35m
TS: 0ms
MS: 2056KB
*/

int N,M,arr[10'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long lo = 1, hi = 0,mid,sum = 0;
	
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
		sum += arr[i];
		if(hi < arr[i])
			hi = arr[i];
	}
	cin >> M;
	if(sum <= M) // sum이 예산보다 적으면, 최댓값을 출력 후 종료.
	{
		cout << hi;
		return 0;
	}
	
	while(lo + 1 < hi) //아니면 이분탐색을 이용하여 최적의 값을 찾는다.
	{
		mid = (lo + hi) / 2;
		
		sum = 0;
		for(int i=0; i<N;i++)
		{
			if(mid < arr[i])
				sum += mid;
			else
				sum += arr[i];
			if(sum > M)
			{
				hi = mid;
				break;
			}
		}
		if(sum < M)
			lo = mid;
        if(sum == M)
		{
			lo = mid;
			break;
		}
		
	}
	cout << lo;
}