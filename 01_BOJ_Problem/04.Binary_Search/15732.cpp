#include <iostream>
using namespace std;
//acmicpc.net/problem/15732

/*
문제명: 도토리 숨기기
TL: 1s
ML: 128MB



Good
1. 시간복잡도를 잘 계산하였음(문제 잘못 이해한 것을 이것으로 캐치함.)
2. 
3. 

Bad
1. 문제를 잘못 이해함. (도토리가 들어있는 마지막 번호의 상자를 마지막에 넣는 도토리의 번호로 이해함.) -> 예제를 제대로 풀어보았다면 이해했을 것.

2. 조건에 따른 lo,hi값 조정을 헷갈려함 -> 예제보고, 근처값 (+-1) 넣어봐서 어떻게 작동해야할 지 정하기. [예제를 출력해서 참이 나오는 것도 중요하지만, 예제 응용으로 어떻게 동작해야할 지를 정하기.]

3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW : BS문제에서, 참/거짓이 어떠한 조건일 때인지 스스로 선택해야할 경우도 있다는 것을 배웠다. (sum vs D 부분.)
keypoint: 

TU: m
TS: ms
MS: KB
*/


int N,K,D,A,B,C,lo=1e6,hi,mid,sum;
struct _rule {
	int A,B,C;
};
_rule rule[10'001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K >> D;
	for(int i=0;i<K;i++)
	{
		cin >> rule[i].A >> rule[i].B >> rule[i].C;
		lo = lo < rule[i].A ? lo : rule[i].A;
		hi = hi > rule[i].B ? hi : rule[i].B;
	}
	while(lo<=hi)
	{
		int i;
		mid = (lo + hi) / 2;
		sum = 0;
		for(i=0;i<K;i++)
		{
			if(mid >= rule[i].A)
			{
				if(mid < rule[i].B)
					sum += (mid-rule[i].A) / rule[i].C + 1;
				else
					sum += (rule[i].B-rule[i].A) / rule[i].C + 1;
				
				if(sum > D)
					break;
			}
		}
		if(sum >= D)
			hi = mid -1;
		else
			lo = mid + 1;
	}
	
	cout << lo;
	
}