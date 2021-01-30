#include <iostream>
#include <queue>
using namespace std;
//acmicpc.net/problem/1966

/*
문제명: 프린터 큐
TL: 2s
ML: 128MB



Good
1. 배열을 이용한 것이 적절하였다. (왜냐하면 큐는 iterator을 못쓰기 때문에 모든 원소 참조가 어렵기 때문이다.)
2. 
3. 

Bad
1. 모든 순서를 구상한 뒤 작성하자.!
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 26m
TS: 0ms
MS: 2016KB
*/
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while(TC--)
	{
		int idx = 1,i,num,N,M,arr[10] = {0,};
		queue<int> q;
		cin >> N >> M;
		for(int i=0;i<N;i++)
		{
			cin >> num;
			q.push(num);
			arr[num]++;
		}
		while(1)
		{
			num = q.front();
			for(i=9;i>num;i--)
			{
				if(arr[i])
					break;
			}
			if(i == num) // 높은 중요도가 없을 때
			{
				if(idx == M+1)
				{
					cout << idx << '\n';
					break;
				}
				q.pop();
				arr[num]--;
				idx++;
			}
			else
			{
				if(idx == M+1)
				{
					q.pop();
					M += q.size();
					q.push(num);
				}
				else
				{
					q.pop();
					M -=1;
					q.push(num);
				}
			}
		}
		
	}
}