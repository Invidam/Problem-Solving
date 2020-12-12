#include <iostream>
//https://www.acmicpc.net/problem/11000
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
강의실 배정 

시간 제한	1초
메모리 제한	256MB
문제
수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다. 

김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 

참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)

수강신청 대충한 게 찔리면, 선생님을 도와드리자!

입력
첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200,000)

이후 N개의 줄에 Si, Ti가 주어진다. (1 ≤ Si < Ti ≤ 109)

출력
강의실의 개수를 출력하라.

걸린 시간 : about 2h 

Good
1 시간복잡도 파악을 잘함.
2 구현 방법에 문제가 X
3 pq를 습득함.

Bad
1 어디에서 시간복잡도가 문제가 되는 지 중간에 까먹음 -> 시간을 쪼개서 풀어서 그런듯
2 pq size함수도 안썻음 쓰면 좋았을텐데 -> 이를 알게 됨
3 왜 시작시간을 기준으로 하는지 이해를 잘못함. -> 단순히 생각.

Key :이번 문제 같은 경우는 강의를 모두 해야하기에, 최대한 빈틈을 없애는 게 중점이었음 따라서 시작시간을 기준으로하여 빈틈을 최소화함.

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