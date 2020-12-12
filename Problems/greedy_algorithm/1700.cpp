#include <iostream>
//https://www.acmicpc.net/problem/1700
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
멀티탭 스케줄링

문제
기숙사에서 살고 있는 준규는 한 개의 멀티탭을 이용하고 있다. 준규는 키보드, 헤어드라이기, 핸드폰 충전기, 디지털 카메라 충전기 등 여러 개의 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다. 그래서 준규는 자신의 생활 패턴을 분석하여, 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.

예를 들어 3 구(구멍이 세 개 달린) 멀티탭을 쓸 때, 전기용품의 사용 순서가 아래와 같이 주어진다면, 

키보드
헤어드라이기
핸드폰 충전기
디지털 카메라 충전기
키보드
헤어드라이기
키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰충전기 플러그를 빼는 것이 최적일 것이므로 플러그는 한 번만 빼면 된다. 

입력
첫 줄에는 멀티탭 구멍의 개수 N (1 ≤ N ≤ 100)과 전기 용품의 총 사용횟수 K (1 ≤ K ≤ 100)가 정수로 주어진다. 두 번째 줄에는 전기용품의 이름이 K 이하의 자연수로 사용 순서대로 주어진다. 각 줄의 모든 정수 사이는 공백문자로 구분되어 있다. 

TL : 2초
ML : 128MB
G
1 문제의 조건을 바로 이해함
2 pq를 사용하여 복습을 함 (시간 복잡도 측면에서 적절하였음)
3 2시간동안 열심히 품 (집중력 발휘함)

B
1 구현시에 모두 다 꼳혀있는 상태를 만드려고 조금 복잡해짐. 수정하면 좋을듯. -> 문제를 나눠서 생각해보자.
2 굳이 pq를써야 했을까? N K 가 다 적어서 안써도 됐을듯. 
3 반례를 잘 못찾음... 코드를 짜기 전에 어떠한 반례가 생길 수 잇는지 미리 고민해보기 왜냐면 짜다보면 뭔가 제한적인 생각만 하게됨.

H
2h8m

*: 우선순위를 정해야겠다는 생각이 들었고. 1.사용빈도 2.다음사용시간 으로 반례를 찾으며 기준을 바꿔갔음.
근데 이런거보다 단순히 생각하면 될 듯.

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