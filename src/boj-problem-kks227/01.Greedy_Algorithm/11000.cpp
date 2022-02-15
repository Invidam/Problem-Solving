#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//acmicpc.net/problem/11000

/*
문제명:  강의실 배정
TL: 1s
ML: 256MB



Good
1 시간복잡도 파악을 잘하였다.
2 구현 방법에 문제가 없었다.
3 pq를 배웠다..

Bad
1 어디에서 시간복잡도가 문제가 되는 지 중간에 잊었고, 시간이 오래 걸렸다 이는 푸는 시간이 연속적이지 않아 그런 것 같다. 다음부터는 관련 키워드나 구상을 잘 적어놓아야 겠다.
2 pq size함수를 쓰지 않았다
3 왜 시작시간을 기준으로 하는지 이해를 잘못하였다. -> 예제를 풀고 그 생각을 문제에 적용하면 된다.

Key :이번 문제 같은 경우는 강의를 모두 해야하기에, 최대한 빈틈을 없애는 게 중점이었음 따라서 시작시간을 기준으로하여 빈틈을 최소화한 것이다..


conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h 
TS: ms
MS: KB
*/
bool compare(pair<int,int> p1, pair<int,int> p2)
{
	return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
	//return p1.second != p2.second ? p1.second < p2.second : p1.first < p2.first;
}
int main()
{
	int N,cnt = 1;
	scanf("%d",&N);
	int a,b;
	pair<int,int> arr[200001];
	int M;
	priority_queue<int, vector<int>,greater<int> > pq;//top : m
	for(int i=0;i<N;i++)
	{
		scanf("%d %d",&a,&b);
		arr[i] = make_pair(a,b);
	}
	sort(arr,arr+N,compare);
	pq.push(arr[0].second);
	for(int i=1;i<N;i++)
	{
		a = arr[i].first;
		b = pq.top();
		if(b <= a) 
		{
			M = arr[0].second;
			pq.pop();
			pq.push(arr[i].second); //**pq에 있던 수들 과 arr[i].second중 가장 작은 수를 꺼내야 할 때 pq를 사용하면 logN이 소요된다.
		}
		else
		{
			pq.push(arr[i].second);
			cnt++;
		}
	}
	printf("%ld",pq.size());
}