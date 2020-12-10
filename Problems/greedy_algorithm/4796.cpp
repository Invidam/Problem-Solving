#include <iostream>
//4796
/*
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