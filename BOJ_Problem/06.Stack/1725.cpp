#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
//acmicpc.net/problem/1725

/*
문제명: 히스토그램
TL: 2s
ML: 128MB



Good
1. stack 연습에 도움이 되었다.
2. 
3. 

Bad
1. 어떻게 해야 코드를 줄일 지 (중복되는 부분) 계속 고민하기. 
2. 예외경우 반례 찾기가 부족했다.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h
TS: 12ms
MS: 2284KB
*/
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[100'001], N;
	stack<int> s;
	ll ans;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	
	ans = arr[0];
	arr[N] = 0;
	for(int i=0;i<N+1;i++)
	{
		while(!s.empty() && arr[s.top()] >= arr[i])
		{
            int val = arr[s.top()];
			s.pop();
			if(s.empty())
                ans = ans > (ll)val*i ? ans : (ll)val*i;
			else 
                ans = ans > (ll)(val)*(i- s.top()-1) ? ans : (ll)(val)*(i- s.top()-1);
		}
		s.push(i);
	}
	cout << ans;
}
