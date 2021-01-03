#include <iostream>
#include <math.h>
#include <algorithm>
//acmicpc.net/problem/2447

/*
문제명: 별찍기 10
TL: s
ML: MB

-저장이 날라갔다.-

Good
1. 예전보다 간결하게 풀었다.
2. 다시 푸는 문제도 배울 게 있음을 알게 되었다.
3. 

Bad
1. 구상에 시간이 좀 걸렸다.
2. 
3. 

conceipt: i,j,len에 따라 규칙을 변환시켜 해결하였따.
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: m
TS: 252ms
MS: 2016KB
*/
//1100
#include <iostream>
int N;
void print_star(int i,int j,int len)
{
	if(len != 1)	
	{
		len /= 3;
		if(i/ (len) == 1 && j / (len) == 1)
			printf(" ");
		else
			print_star(i%len,j%len,len);
	}
	else
		printf("*");
	
}
int main()
{
	scanf("%d",&N);
    
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			print_star(i,j,N);
		}
		printf("\n");
	}	
}