#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef int ll;
typedef std::pair<ll, ll> P;

//acmicpc.net/problem/15748

/*
문제명: Rest stop
TL: 2s
ML: 512MB



Good
1. 비슷한 아이디어를 바로 떠올림
2. 저장을 잘해놨음.
3. 

Bad
1. 아이디어 변경에 따른 시간복잡도 생각X
2. pq를 괜히 씀 (정렬이 매 루프마다 바뀌어야하면 pq를쓰고, 정렬이 유지되도 괜찮으면 vector로 sort한다.)
3. ll를 써야했음 int가 아니라 왜냐면  (arr-cur)*arr 를 했을 때 int를 넘어가기 때문이다.

conceipt: 
solution: 
Q1: 
A1: 
keypoint: 

TS: 44ms
MS: 3460KB
*/

bool cmp(P p1, P p2)
{
	return p1.first > p2.first;
}
int main()
{
	ll L,N,rF,rB,x,c,cur = 0;
	P arr[100001] = {};
	scanf("%d %d %d %d",&L,&N,&rF,&rB);
	long long ret = 0;
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&x,&c);
		arr[i] = P(c,x);
	}
	
	sort(arr,arr+N,cmp);
	for(int i=0;i<N;i++)
	{
		if(cur > arr[i].second)
			continue;
		ret += (arr[i].second - cur) * arr[i].first;
			
		cur = arr[i].second;
	}
	printf("%lld",ret*(rF-rB));
}