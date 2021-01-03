#include <iostream>
//acmicpc.net/problem/17509

/*
문제명: And the WInner Is... Ourseleves!


입력
11 lines are given as the input. The -th line contains two space-separated integers, 
 and 
, where 
 is the amount of minutes required to solve the -th problem, and 
 is the number of incorrect verdicts on the -th problem.

For each , 
 and 
. Also, 
.

출력
Output the minimum penalty if we solve all problems.

<그림파일이라 짤린 게 좀 있음.>

해석 : D V가 연속적으로 주어짐.
D는 푸는데 걸린 시간 V는 발생한 오류들.
문제를 마쳤을 때, 걸린 총 시간(이전 시간까지 합한 값)이 T인데,
각 문제를 마칠 때 마다 T+20V만큼 페널티가 생김.
입력된 여러 문제와 오류를 잘 배열시키면 페널티를 줄일 수 있는데, 이 때 최소 페널티값을 구하는 문제.
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