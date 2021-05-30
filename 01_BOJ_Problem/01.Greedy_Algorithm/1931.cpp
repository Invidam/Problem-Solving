#include <iostream>
//https://www.acmicpc.net/problem/1931
#include <utility>
#include <algorithm>
/*
문제명 : 회의실배정
TL 2s
DL 128MB


G
1 많은 고민을 하였다.. 시간복잡도 측면 / 그리드 알고리즘에 대해서
2 소트 정렬 람다함수 활용하여 짧게 코딩하였다.
3 구현이 오래걸리지않았다.

B
1 구상에 어려움이 있었다.. (주어진 조건에서, 고려해볼만한 값이 3개가 있어서 충분히 유추가 가능했다.)
2 정렬 comp를 어떻게 할지 기억을 잘 못했다.
3 pair을 사용하는 방법을 검색하였으며, pair이 sort에서 어떻게 작용하는지 알았더라면 람다함수를 안써도 되었을 것같다.

+
1.왜 끝나는 시점을 기준으로 했을까?
ㄴ반례 찾기 처음기준, 짧은 순 기준에서로 했을 때 틀리다.
ㄴ논리로 이해하기 : 다음 강의가 끝나는 시간이 적다 -> 많은 강의를 넣을 수 있다. 즉 빨리 다음 강의를 시작할 수 있도록 끝나는 시간이 빠른걸 넣는다.

TS <?>
MS <?>
*/
int main()
{
	std::pair<int,int> p[100001];
	int N,cnt = 1,idx = 0;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
		scanf("%d %d",&p[i].first,&p[i].second);
	
	sort(p,p+N,[](std::pair<int,int> p1,std::pair<int,int> p2) 
		 {
			 if(p1.second == p2.second)
				 return p1.first < p2.first;
			 return p1.second < p2.second;
		 });
	
	for(int i=1;i<N;i++)
	{
		if(p[idx].second <= p[i].first)
		{
			idx = i;
			cnt++;
		}
	}
	printf("%d",cnt);
	
}