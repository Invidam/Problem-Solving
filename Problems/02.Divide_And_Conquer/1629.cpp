#include <iostream>
typedef unsigned long long ll;
//acmicpc.net/problem/1629

/*
문제명: 곱셈
TL: 0.5s
ML: 128MB



Good
1. 논리적으로 나머지에 대한 증명을 함.
2. 분할정복을 조금이나마 이해를 함.
3. 반례를 잘 구함

Bad
1. 오버플로우 계산을 잘 못했음. 가장 최악을 고려해보기!
2. 분할에 부족한 점이 많았음
3. 시간복잡도 이해도 잘못한듯.

conceipt: 
solution: 
Q1: 
A1: 
keypoint: 

TU: 2h
TS: 0ms
MS: 2016KB
*/
ll a,b,c,temp;
ll fun(ll bb)
{
	ll ret;
	a %=c;
	
	if (bb == 1)	
	{
		ret = a;
	}
	else
	{
		temp = fun(bb/2);
		//printf("in %lld,temp : %lld\n",bb,temp);
		ret = temp * temp;
		ret *= (bb%2) ? a : 1;
	}
	return ret%c;
}
int main()
{
	scanf("%llu %llu %llu",&a,&b,&c);
	if(c == 1)
	{
		printf("0");
		return 0;
	}
	printf("%lld",fun(b));
}
//나머지 연산을 즉각즉각 하라는게 어디서 하ㅏ는건지 모르겠다!
/*
n제곱의 나머지 = 나머지의 n제곱
A / B = C . . . . D라고 할 때,
A = B *C + D라고 할 수 있다.
A^n	=(B*C+D)^n 
	=. . . + D^n (. . .은 B*C를 적어도 하나 가져갔으므로, B로 나눴을 때 나머지가 없다.)
따라서 A^n % B = D^N % B = {A % B (=D)}^n 이다.
이는 A^n의 나머지가 A의 나머지인 D의 n제곱과 같다는 것이다.

이 문제에서, A^n을 구하는 함수가 존재하므로 이를 변형하여 D^N을 구하게 끔 하면 된다.



*/

/*
1개로 나눠짐
크기는 n	
복잡도 1

2

*/