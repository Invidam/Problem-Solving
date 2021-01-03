#include <iostream>
#include <algorithm>
#include <set>
//https://www.acmicpc.net/problem/2212
/*
문제명: 센서 
TL: 2s
ML: 128MB

Good
1. 기준을 잘 찾았다.
2. set을 복습하였다.
3. 예외케이스도 잘 찾았다.

Bad
1. 기준을 찾는데 시간이 오래 걸렸다.
2. set에 대해 자세히 알지 못했다.
3. 이를 검색하는데 시간이 오래 걸렸다.

conceipt: 
입력된 수들을 K개의 집단으로 나눈다.
그후 집단의 M-m을 전부 더한다.

solution: 좌표간의 distance를 구해 sum을 구하는데, 높은 수들을 K만큼 방어해 준다고 생각해야 한다.
Q1: 
A1: 
틀렸던 거 : i를 하나더 추가시켜 dis[N+1] 인 0값 까지도 추가시켰다.
배운 점 : set는 배열 범위안에서 정의되지 않은 값은 0이다.
keypoint: 

TS: 2ms
MS: 2416KB
*/
int main()
{
	int N,K,i=0,sum = 0;
	scanf("%d %d",&N,&K);
	if(N <= K)
	{
		printf("0");
		return 0;
	}

	std::set<int> s;
	int dis[10001];
	for(int i=0;i<N;i++)
	{
		int n;
		scanf("%d",&n);
		s.insert(n);
	}
	auto itr = s.begin();
	for(i=0; i<s.size()-1; ++itr,++i)
	{
		auto next = std::next(itr,1);
		dis[i] =*next - *itr;
	}
	if(++i <= K)
	{
		printf("0");
		return 0;
	}
	std::sort(dis,dis+i);
	for(int j=0;j<i-K+1;j++)
		sum+= dis[j];
	
	printf("%d",sum);
}