#include <iostream>
#include <algorithm>
//https://www.acmicpc.net/problem/1992
/*
문제명: 쿼드트리
TL: 2s
ML: 128MB



Good
1. 잘배웠다.
2. 메모하는 습관이 좋았다.
3. 

Bad
1. 입출력에 있어서 모르는 점이 있었다. (cin.ignore = 앞의 문자 비움 , scanf(" ") = 같은 기능  scanf("%1d") 1개만 받음)
2. () 사용에 있어서 조금 실수가 있었다
3. x

conceipt: 
solution: 
Q1: 
A1: 

NEW : 메모리 많던게 컴파일러나 환경이 바뀌어서 그런 거였다.
keypoint: 

TU: 40m
TS: 0ms
MS: 2020KB
*/
int N, i, j;
char arr[1 << 6+1][1 << 6+1];
void solve(int s1,int s2,int len)
{
	printf("(");
	for(i=s1;i<s1+len;i++)
		for(j=s2;j<s2+len;j++)
			if(arr[s1][s2] != arr[i][j])
			{
				i = s1 + len + 1;
				j = s2 + len + 1;
			}
	if(i != s1 + len && j != s2 + len)
	{
		//4개 실행
		len /=2;
		
		solve(s1,s2,len);
		solve(s1+len,s2,len);
		solve(s1+len,s2+len,len);
		solve(s1,s2+len,len);
	}
	printf("%d)",arr[s1][s2]);
	
}

int main()
{
	scanf("%d",&N);
	cin.ignore();
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			arr[i][j] = cin.get();
		}
		cin.ignore();
		
	}
	
	solve(0,0,N);
}