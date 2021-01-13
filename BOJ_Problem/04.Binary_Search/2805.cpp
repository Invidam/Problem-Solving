#include <iostream>
#include <algorithm>
using namespace std;


//acmicpc.net/problem/2805

/*
문제명: 나무자르기
TL: 1s
ML: 256MB



Good
1. 복잡도를 고려해 효율적인 코드를 작성하였다.
2. 
3. 

Bad
1. 문제의 조건을 잘 이해하지 못하였다. -> 이해가 안간건 인지하였는데, 빠르게 풀려다보니 제대로 이해하지 못하였다.
2. 탑다운 방식에서, 파라미터에 잘못된 값을 전달하려 했다.
3. for문을 돌 때, 어떠한 변수가 기준이 되는지 햇갈려하였다. ->변수명 잘 짓기.

conceipt: 
solution: 이분탐색 설명 문제.
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h
TS: 156ms
MS: 5924KB
*/

int N,M,arr[1'000'001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int lo = 0, hi = 0, H = 0;
	long long sum = 0;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
		if(hi < arr[i]) 
			hi = arr[i];
	}
	while(lo + 1 < hi)
	{
		H = (lo + hi) / 2;
		sum = 0;
		for(int i=0; i<N;i++)
		{
			if(H < arr[i])
				sum += arr[i] -H;
			if(sum >= M)
			{
				lo = H;
				break;
			}
		}
		if(sum < M)
			hi = H;	
	}
	cout << lo;
}
/*
-탑다운-
int N,M,arr[1'000'001];

int solve(int start,int end)
{
	if(start + 1 >= end)
		return start;
	int mid = (start + end) / 2, i,ret = 0;
	bool flag = false;
	long long sum = 0;
	for(i=0;i<N;i++)
	{
		if(arr[i] > mid)
			sum += arr[i] - mid;
		if(sum >= M)
			return solve(mid,end);
	}
	return solve(start,mid);
		
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int max_arr = 0;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	sort(arr,arr+N,greater<int>());
	
	cout << solve(0,arr[0]);
}
*/