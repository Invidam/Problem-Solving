#include <iostream>
#include <queue>
using namespace std;
//acmicpc.net/problem/2164

/*
문제명: 카드 2
TL: 2s
ML: 128MB



Good
1. 기본 예제.
2. 
3. 

Bad
1. 
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 3m
TS: 4ms
MS: 4152KB
*/
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	queue<int> q;
	cin >> N;
	for(int i=0;i<N;i++)
		q.push(i+1);
	while(q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}