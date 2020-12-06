#include <iostream>
//4796

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