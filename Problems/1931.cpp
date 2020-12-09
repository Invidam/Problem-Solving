#include <iostream>//1931
#include <utility>
#include <algorithm>
/*
G
1 많은 고민을 함. 시간복잡도 측면 / 그리드 알고리즘에 대해서
2 소트 정렬 람다함수 활용하여 짧게 코딩함
3 구현이 오래걸리지않음

B
1 바로 생각해내지 못함. (주어진 조건에서, 고려해볼만한 값이 3개가 있어서 충분히 유추가 가능했다.)
2 정렬 comp를 어떻게 할지 검색을 함.
3 pair을 사용하는 방법을 검색하였으며, pair이 sort에서 어떻게 작용하는지 알았더라면 람다함수를 안써도 되었을 것.


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