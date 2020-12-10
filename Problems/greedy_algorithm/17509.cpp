#include <iostream>
//17509
/*

G
1. stl이용 X 왜냐면 케이스가 몇개 없으니까.
2. 정렬 도중에 합하여 짧게 함
3. 입력 도중에 합하여 짧게함

B
1. 영어를 몰라 검색해서 함.
2. 왜케 용량이 큼? (stl과 용량에 대해서도 공부하기.) [작은거같기도하고 ]
3. 시간에 대한 이해를 못한거같기도함 영어문제가 아니라.
*/
int main()
{
	int min_idx,tmp,v,penalty = 0,t=0;
	int d[11];
	
	for(int i=0;i<11;i++)
	{
		scanf("%d %d",d + i,&v);
		penalty +=  v*20;
	}
	
	for(int i=0;i<11;i++)
	{
		min_idx = i;	
		
		for(int j=i;j<11;j++)
			if(d[min_idx] > d[j])
				min_idx = j;
				
		t+= d[min_idx];
		penalty += t;
		d[min_idx] = d[i];
	}
	
	printf("%d",penalty);
}