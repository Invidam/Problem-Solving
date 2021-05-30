#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//acmicpc.net/problem/1700

/*
문제명: 멀티탭 스케쥴링
TL: 2s
ML: 128MB


G
1 문제의 조건을 바로 이해하였다
2 pq를 사용하여 복습을 하였다.(시간 복잡도 측면에서 적절하였음)
3 2시간동안 열심히 풀었다. 포기하지 않았다. (집중력 발휘함)

B
1 구현시에 모두 다 꼳혀있는 상태를 만드려고 조금 복잡해졌다.. 수정하면 좋을듯. -> 문제의 동작을 나눠서 생각해보자.
2 굳이 pq를 쓸 이유가 없었다. 이유는 변수의 크기가 적기 때문이다.
3 반례를 잘 못찾았다.... 코드를 짜기 전에 어떠한 반례가 생길 수 잇는지 미리 고민해보자 왜냐면 짜다보면 뭔가 제한적인 생각만 하게된다.

H :2h8m

*: 우선순위를 정해야겠다는 생각이 들었고. 1.사용빈도 2.다음사용시간 으로 반례를 찾으며 기준을 바꿔갔다.근데 이런거보다 단순히 생각하면 될 듯하다.
*/



*/
int main()
{
	int cnt = 0,K,m,N,k=0;
	bool flag;
	int arr[101];
	int temp[101];
	priority_queue<int,vector<int>,greater<int> > pq[101];
	int tmp;
	scanf("%d %d",&N, &K);
	tmp = N;
	for(int i=0;i<K;i++)
	{
		scanf("%d",arr+i);
		if(i < tmp)
		{
			flag = true;
			for(int j=0;j<k;j++)
			{
				if(temp[j] == arr[i])
				{
					flag = false;
					break;
				}
			}
			if(flag)
				temp[k++] = arr[i];
			else
				tmp++;
		}
		else 
			pq[arr[i]].push(i);
	};
	
	if(tmp >= K)
	{
		printf("0");
		return 0;
	}
	
	
	for(int i=tmp;i<K;i++)
	{
		for(int j=1;j<101;j++)
		{
			if(!pq[j].empty())
				if(pq[j].top() == i)
				{
					pq[j].pop();
					j = 101;
				}
		}
		flag = false;
		while(1)
		{
			for(int j=0;j<N;j++)
				if(temp[j] == arr[i])
				{
					j = N;
					flag = true;
				}
			if(flag)
				break;
			
			cnt++;
			for(int j=0;j<N;j++)
				if(pq[temp[j]].empty())
				{	
					temp[j] = arr[i];
					j = N;
					flag = true;
				}
			if(flag)
				break;
			
			m = 0;
			
			for(int j=1;j<N;j++)
			{
				if(pq[temp[j]].top() > pq[temp[m]].top())
					m = j;
			}
			temp[m] = arr[i];
			break;
		}
	}
	printf("%d",cnt);
}