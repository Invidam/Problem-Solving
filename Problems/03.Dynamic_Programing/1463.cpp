#include <iostream>
#include <algorithm>
//acmicpc.net/problem/1463

/*
문제명: 1로 만들기
TL: 2s
ML: 128MB



G
1 기본적인 dp문제를 통해 dp문제가 어떻게 구성되어 있는지를 배웠다.
2
3

B
1 빨리푸느라 조금의 실수가 있었다. (temp 에 1 더하지 않았던 것.)
2
3

conceipt: 기본적인 dp 문제.
solution: f(n) = max(f(n-1) , f(n/2) , f(n,3)) + 1 임을 이용.
Q1: 
A1: 

NEW :
keypoint: 

TU: 5m
TS: 36ms
MS: 37052KB
*/

int arr[1000001];
int N;

int solve(int n)
{
	if(arr[n] != -1)
		return arr[n];
	
	int temp = solve(n-1);
	if(n % 3 == 0)
		temp = std::min(temp,solve(n/3));
	else if(n %2 == 0)
		temp = std::min(temp,solve(n/2));
	arr[n] = ++temp;
	return temp;
	
}

int main()
{
	scanf("%d",&N);
	
	for(int i=2;i<=N;i++)
		arr[i] = -1;
	printf("%d",solve(N));
}