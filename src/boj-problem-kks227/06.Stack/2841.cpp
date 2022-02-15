#include <iostream>
#include <stack>
using namespace std;
//acmicpc.net/problem/2841

/*
문제명: 외계인의 기타 연주
TL: 1s
ML: 256MB



Good
1. 시간,공간복잡도,코드 크기를 효율적으로 작성하여 랭킹 21등에 들었다.
2. 기타의 개념을 몰라 문제를 조금 헷갈려했지만, 잘 읽고 예제를 분석하여 이해했다.
3. 

Bad
1. 
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW : stack의 배열도 가능하다. 
keypoint: 

TU: m
TS: ms
MS: KB
*/


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0,N,P,a,b;
	stack<int> s[6];
	cin >> N >> P;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		while(!s[a-1].empty()&&s[a-1].top() > b)
		{
			s[a-1].pop();
			ans++;
		}
		if(!s[a-1].empty()&&s[a-1].top() == b)
			continue;
		s[a-1].push(b);
		ans++;
	}
	
	cout << ans;
}