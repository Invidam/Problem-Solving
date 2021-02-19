#include <iostream>
#include <queue>
#include <utility>
using namespace std;
//acmicpc.net/problem/9019

/*
문제명: DSLR
TL: 6s
ML: 256MB



Good
1. 
2. 
3. 

Bad
1. L,R 구현에 실수.
2. 출력방식이 재귀가 낫다.
3. 예외 발생시 오류 출력시키면 오류 찾기가 쉬울 것.

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: m
TS: ms
MS: KB
*/


typedef pair<int, char> ic;
int A,B,TC;
const int MAX_RANGE = 9'999;
int adj[MAX_RANGE +2];
char arr[MAX_RANGE +2];

void for_print(int before)
{
	if(adj[before] == -1)
		return;
    for_print(adj[before]);
    cout << arr[before];
}
void bfs()
{
	bool visited[MAX_RANGE + 2] = {false,};
	
	queue<int> q;
	q.push(A);
	visited[A] = true;
	adj[A] = -1;
	int next;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		next = (2*curr) % 10000;
		if(!visited[next])
		{
			q.push(next);
			adj[next] = curr;
			arr[next] = 'D';
			visited[next] = true;
		}
		if(next == B)
			break;
		next = ((curr -1) + 10000 ) % 10000;
		if(!visited[next])
		{
			q.push(next);
			adj[next] = curr;
			arr[next] = 'S';
			visited[next] = true;
		}
		if(next == B)
			break;
		
		next = (curr % 1000) * 10+ curr / 1000;
		if(!visited[next])
		{
			q.push(next);
			adj[next] = curr;
			arr[next] = 'L';
			visited[next] = true;
		}
		if(next == B)
			break;
		
		next = curr%10 * 1000 + curr/10;
		
		if(!visited[next])
		{
			q.push(next);
			adj[next] = curr;
			arr[next] = 'R';
			visited[next] = true;
		}
		if(next == B)
			break;
	}
    for_print(next);
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	while(TC--)
	{
		cin >> A >> B;
		bfs();
	}
}