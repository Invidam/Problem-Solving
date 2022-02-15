#include <iostream>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/2110

/*
문제명: 공유기 설치
TL: 2s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. 변수 point를 쓸 때, distnace[C]를 선언하였었다. 
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 문제의 분류가 무엇인지 헷갈릴 수도 있을 것 같다.

TU: 40m
TS: 20ms
MS: 2796KB
*/

2796 20

int N,C,arr[200'001],i;
long mid,lo,hi;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> C;
	for(i=0;i<N;i++)
		cin >> arr[i];
	
	sort(arr,arr+N);
	
	lo = 1;
	hi = arr[N-1] - arr[0];
	
	while(lo <= hi)
	{
		int point = arr[0], j = 1;
		mid = (lo + hi) / 2;
 		for(i=1;i<N && j<C;i++)
			if(arr[i] - point >= mid)
			{
				point = arr[i];
				j++;
			}
		
		if(j == C)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	
	cout << hi;
}