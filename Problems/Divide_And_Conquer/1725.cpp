#include <iostream>
#include <algorithm>
typedef unsigned long long ll;
//1420
//acmicpc.net/problem/1780
//1510~ 3^7 = 2187
//acmicpc.net/problem/

/*
문제명: 히스토그램
TL: 2s
ML: 128MB



Good
1. 배웠던 것을 잘 응용함
2. ll사용 잘했음. 캐스팅시켜서
3. 메모리 잘줄임

Bad
1. 분할때 mid+1한 것
2. length 설정에 있어 조금 실수한 것
3. 

conceipt: 
solution: 
Q1: 스택이용하면 더 메모리가 적던데 나중에 해보기.
A1: 

NEW :
keypoint: 

TS: 24ms
MS: 2408KB
*/
int N;
int arr[2188][2188];

ll solve(int s,int e)
{
	if(s == e)
		return 0;
	if(s == e -1)
		return arr[s];
	
	int mid = (s+e)/2;
	ll ret = std::max(solve(s,mid),solve(mid,e));
	int idx_l = mid,idx_r = mid, min_idx = mid;
	
	while(s <= idx_l && idx_r < e)
	{
		//length =  idx_r - idx_l + 1
		if(idx_l ==s && idx_r == e -1 )
		{
			ret = std::max(ret,(ll)arr[min_idx]* (idx_r - idx_l + 1));
			return ret;
		}
		else if(idx_r == e-1 )
		{
			if(arr[min_idx] > arr[--idx_l])
				min_idx = idx_l;
		}
		else if(idx_l == s)
		{
			if(arr[min_idx] > arr[++idx_r])
				min_idx = idx_r;
			
		}
		else if(arr[idx_l-1] >= arr[idx_r+1])
		{
			if(arr[min_idx] > arr[--idx_l])
				min_idx = idx_l;
		}
		else //  arrL <  arr R
		{
			if(arr[min_idx] > arr[++idx_r])
				min_idx = idx_r;
		}
		
		ret = std::max(ret,(ll)arr[min_idx]* (idx_r - idx_l + 1));
	}
	return ret;
	
	
	
}


int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",arr+i);
	
	printf("%lld",solve(0,N));
}