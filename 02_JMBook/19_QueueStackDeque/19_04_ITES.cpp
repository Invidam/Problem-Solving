#include <iostream>
#include <queue>
using namespace std;
//algospot.com/judge/problem/read/ITES

/*
문제명:  외계 신호 분석
TL: 15s
ML: 64MB

TU: 10m
TS: 5000ms
LEN: 941B


Good
1. 

Bad
1. for문이 아닌 while문을 이용해 가시성이 떨어졌다.

IAN
1. X

NEW
1. 온라인 알고리즘을 배웠다 (구조체를 이용한 구현 + unsigned을 이용한 mod연산도 배움.)


Q1: 
A1: 


Solution: queue를 이용한 값들을 추가/제거 시켜 비교.

Approach: brackets와 비슷했으나, clue가 달라 queue를 이용함을 알 수 있었다.

Clue: sum의 작동원리 (맨앞에서 빼고 뒤에서 더한다) 가 queue와 유사하였다.

Reconstruction : 
*/


struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next()
	{
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1 ;
	}
};


const long long  MOD = ((long long)1 << 32);
int N,K,TC;

long long getNext(long long value)
{
	if(value == -1) return 1983;
	long long ans = ((long long)value * 214013 + 2531011 ) % MOD;  
	
	return ans;
}

int getInput(long long value)
{
	return (int)(value% 10000 + 1);
}

int findK()
{
	int ret = 0, i=0, sum = 0, inputValue;
	long long arrValue = -1;
	queue<int> q;
	while(!q.empty() || i < N)
	{
		if(sum >= K)
		{
			if(sum == K) ret++;
			sum -= q.front();
			q.pop();
		}
		else
		{
			if(i >= N) break;
			arrValue = getNext(arrValue);
			inputValue = getInput(arrValue);
			sum +=inputValue;
			q.push(inputValue);
			++i;
		}
	}
	
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	
	while(TC--)
	{
		RNG rng;
		cout << rng.next() << '\n';
		cout << rng.next() << '\n';
		cout << rng.next() << '\n';
		//cin >> K >> N;
		
		//cout << findK() << '\n';
	}
}