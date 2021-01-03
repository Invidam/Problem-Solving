#include <iostream>
#include <algorithm>
typedef unsigned long long ll;
//acmicpc.net/problem/2104

/*
문제명: 부분배열 고르기
TL: 2s
ML: 128MB



Good
1. 알고리즘 배우는 용도로 다른 사람 코드를 조금 참고했지만, 나름 안보고 하였다.. 
2. 좌 우를 잘나눠서 했다
3. ll사용, 시간복잡도 구하기에 잘 하였다.

Bad
1. 가운데 에서, 오류가 많았음 1. 범위 2. O(n)을 계속하여 실행됨을 인지하엿는데 시간 복잡도를 미쳐 생각하지 못하였다.
2. 그래도 예시보며 고쳤다.
3. (ll)[int] 여야 ll에 int가 들어갔음을 배웠다.

conceipt: 부분정복 이용하여 3등분
solution: 좌우는 쉬운데, 가운데 할 때 시간초과 안나게 조심하자.
Q1: 
A1: 
keypoint: 

TU: 2h 20m
TS: 24ms
MS: 2796KB
*/
int N;
ll arr[100001];
ll get_sum(int s,int e)
{
	ll ret = 0;
	int min_idx;
	min_idx = s;

	for(int i = s;i<e;i++)
	{
		ret += arr[i];
		if(arr[i] < arr[min_idx])
			min_idx = i;
	}
	return ret*arr[min_idx];
}

ll solve(int s,int e)
{
	if(s == e)
		return 0;
	if(s == e-1)
		return arr[s]*arr[s];
	
	int mid = (s+e)/2;
	int idx_l = mid, idx_r = mid, min_idx = mid;
	ll ret = std::max(solve(s,mid),solve(mid+1,e));
	ll sum = arr[mid];
	while(s <= idx_l && idx_r <= e)
	{
		int num_l = -1,num_r = -1;
		
		if(idx_l-1 >= 0) 
			num_l = arr[idx_l-1];
		if(idx_r+1 < N )
			num_r = arr[idx_r+1];
        if(idx_l -1 < 0 && idx_r+1 >= N)
            break;
        
		if(num_l > num_r)
		{
			sum += arr[--idx_l];
			min_idx = arr[min_idx] < arr[idx_l]  ? min_idx : idx_l;
		}
		else
		{
			sum +=arr[++idx_r];
			min_idx = arr[min_idx] <arr[idx_r] ? min_idx : idx_r;
		}	
		ret = ret >= sum* arr[min_idx] ? ret : sum*  arr[min_idx] ;
	}
	return ret;
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%lld",arr+i);
	printf("%lld",solve(0,N));
}