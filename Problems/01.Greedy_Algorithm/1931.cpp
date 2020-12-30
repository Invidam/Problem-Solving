#include <iostream>
//https://www.acmicpc.net/problem/1931
#include <utility>
#include <algorithm>
/*
문제명 : 회의실배정
TL 2s
DL 128MB

문제
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

입력
첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.



G
1 많은 고민을 함. 시간복잡도 측면 / 그리드 알고리즘에 대해서
2 소트 정렬 람다함수 활용하여 짧게 코딩함
3 구현이 오래걸리지않음

B
1 바로 생각해내지 못함. (주어진 조건에서, 고려해볼만한 값이 3개가 있어서 충분히 유추가 가능했다.)
2 정렬 comp를 어떻게 할지 검색을 함.
3 pair을 사용하는 방법을 검색하였으며, pair이 sort에서 어떻게 작용하는지 알았더라면 람다함수를 안써도 되었을 것.

+
1.왜 끝나는 시점을 기준으로 했을까?
ㄴ반례 찾기 처음기준, 짧은 순 기준에서의
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