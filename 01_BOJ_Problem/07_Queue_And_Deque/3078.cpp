#include <iostream>
#include <queue>
using namespace std;
//acmicpc.net/problem/3078

/*
문제명: 좋은 친구
TL: 1s
ML: 128MB



Good
1. 짧은 시간 내 구현하였다.
2. 
3. 

Bad
1. 시간복잡도를 고려하지 않았다. 풀기 전, 시간복잡도를 보고 어떠한 방법이면 안되는 지 생각한 뒤 구상을 해야한다. 또, 구상을 한 후 했던 구상의 시간복잡도도 고려해야한다.
2. 배열을 이용한 풀이도 존재한다. q.size()가 아니라 cnt[num]을 이용한다.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 25m
TS: 60ms
MS: 2680KB
*/
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int N,K;
	queue<int> q[21];
	cin >> N >> K;
	long long cnt = 0;
    
	for(int i=0;i<N;i++)
	{
		string str;
		cin >> str;
		const int& num = str.size();
		while(i > K && !q[str.size()].empty() && q[num].front() < i-K)
			q[num].pop();
		cnt += q[num].size();
		q[num].push(i);
	}
	cout << cnt;
}


/*
---cnt[num]을 이용한 풀이---
3188 56
장점: pop,push,size가 아닌 ++ -- value를 이용해 시간복잡도 단축.
단점: arr[N]을 이용하여 공간복잡도가 컸다. arr[N]대신 queue[K]를 쓸수도 잇었지만
K <= N이기에 다른점은 없었을 것 같다.

#include <iostream>
#include <queue>
using namespace std;

int cnt[21];
int arr[300'001];
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int N,K;
	cin >> N >> K;
	long long ans = 0;
    
	for(int i=0;i<N;i++)
	{
		string str;
		cin >> str;
		const int& num = str.size();
		arr[i] = num;
		
		if(i > K)
		{
			cnt[arr[i-K]]--;
		}
		
		ans += cnt[num];
		cnt[num]++;
	}
	cout << ans;
}*/

