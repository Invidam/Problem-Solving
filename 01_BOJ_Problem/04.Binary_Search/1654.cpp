#include <iostream>
using namespace std;
//acmicpc.net/problem/1654

/*
문제명: 랜선 자르기
TL: 2s
ML: 128MB



Good
1. 잘 응용하여 짧은 시간에 짰다.
2. 
3. 

Bad
1. cnt 작성을 하지 않았다. 출력에 있어 hi가 아닌 lo를 하였다.
2. 
3. 


방법 1.
조건	lo + 1 < hi
참	hi = mid
거짓	lo = mid
cout << hi
: hi 가 ans, lo가 ans-1에 위치.
: 범위는 (initial lo, initial hi]

방법 2.
조건	lo <= hi
참	hi = mid - 1
거짓	lo = mid + 1
cout << lo
: hi가 ans-1 lo = ans에 위치.
: 범위는 [initial low, inital MAX] ㅇㅎ
장점 : 범위가 가시성 높으며, 좀더 공격적으로 범위를 줄여나간다.


*방법 2가 나은 듯 하다.
*참이 때의 mid값을  hi or lo중 어디에 넣느냐에 따라 달라지니 이 점도 유의해야한다.
참일때 low = mid +1  -> cout << hi;
참일때 high = mid - 1  -> cout << low;

으로 하자.
conceipt: 
solution: 
Q1: 
A1: 

NEW : long = long long (in 64bit)
keypoint: 

TU: 48m
TS: 4ms
MS: 2056KB
*/

int K,N,arr[10'001];
long lo=1,hi,mid,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> N;
	
	for(int i=0;i<K;i++)
	{
		cin >> arr[i];
		hi = hi > arr[i] ? hi : arr[i];	
	}
	
	
	while(lo <= hi)
	{
		cnt = 0;
		mid = (lo + hi) /2;
		for(int i=0;i<K;i++)
			cnt+= (arr[i]/mid);
		
		if(cnt >= N)
			lo = mid +1;
		else
			hi = mid - 1;
	}
	
	cout << hi;
}