#include <iostream>
//https://www.acmicpc.net/problem/4796
/*
문제명 캠핑
TL 1s
ML 128MB

문제
등산가 김강산은 가족들과 함께 캠핑을 떠났다. 하지만, 캠핑장에는 다음과 같은 경고문이 쓰여 있었다.

캠핑장은 연속하는 20일 중 10일동안만 사용할 수 있습니다.

강산이는 이제 막 28일 휴가를 시작했다. 이번 휴가 기간 동안 강산이는 캠핑장을 며칠동안 사용할 수 있을까?

강산이는 조금 더 일반화해서 문제를 풀려고 한다. 

캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다. 강산이는 이제 막 V일짜리 휴가를 시작했다. 강산이가 캠핑장을 최대 며칠동안 사용할 수 있을까? (1 < L < P < V)

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, L, P, V를 순서대로 포함하고 있다. 모든 입력 정수는 int범위이다. 마지막 줄에는 0이 3개 주어진다.

출력
각 테스트 케이스에 대해서, 강산이가 캠핑장을 최대 며칠동안 사용할 수 있는지 예제 출력처럼 출력한다.

G
1. 그래도 생각보다 빠르고 잘풀음. 
2. 소요시간을 적었으면 좋았을 듯.
3. 완성된 코드가 굉장히 짧고 간단함. (문제가 간단한걸수도, 그래도 용량은 너무 큼 왜큰지는 모르겠음)
B
1. TC가 몇번인지도 모르는데 너무 막돌림
2. 범위가 int전체라 O(n)로 하면  TC*N만큼의 수가 반복가능해서, 1초 초과할 것이었음. 
3. 따라서 사실 어느정도 O(1)로 가능하다고 유츄가 됬어야 함.(?)

*/
int main()
{
	// L P V  P일중 L일만 사용가능하며, V일의 휴가가 있음.
	int L,P,V,cnt = 0;
	while(1)
	{
		scanf("%d %d %d",&L,&P,&V);
		if(L == 0 && P == 0 && V == 0)
			break;
		printf("Case %d: %d\n",++cnt,(V%P < L ? V%P : L) + V/P*L);
	}
}


/*
틀렸던 코드
#include <iostream>
//4796

int fun(int L, int P, int V)
{
	int ret = 0;
	int pass = 0;
	while(1)
	{
		if(pass + L > V)
		{
			ret += V-pass;
			break;
		}
		ret+= L;
		pass += L;
		if(pass + P - L > V)
			break;
		pass += P - L;
	}
	return ret;
}
int main()
{
	int L,P,V,cnt = 0;
	while(1)
	{
		scanf("%d %d %d",&L,&P,&V);
		if(L == 0 && P == 0 && V == 0)
			break;
		printf("Case %d: %d\n",++cnt,fun(L,P,V));
	}
}


*/