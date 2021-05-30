#include <iostream>
using namespace std;
//acmicpc.net/problem/1780

/*
문제명: 종이의 개수
TL: 2s
ML: 256MB



Good
1. 분할을 잘 했다.
2. for문을 잘 돌렸다 ( 범위 측면)
3. 빠른시간내에 풀엇다.

Bad
1. 인자로 4가지 점이 아닌 2개의 점 + 1개의 거리나타내는 수 엿으면 좀더 길이가 단축되었을 듯하다.
2. 문제가 쉬웠다.
3. x

conceipt: 
solution: 
Q1: 
A1: 

NEW :scanf보다  cin  iosbase를 쓰는게 더 빠르다.
keypoint: 분할정복.

TU: 25m
TS: 376ms	
MS: 20716KB
*/


int N,i,j;
int arr[2188][2188];
int cnt[3];

void solve(int s1,int s2,int e1, int e2)
{
	for(i=s1;i<e1;i++)
		for(j=s2;j<e2;j++)
			if(arr[s1][s2] != arr[i][j])
			{
				i = e1+1;
				j = e2+1;
			}
	if(i != e1 && j != e2)
		for(int ii=s1;ii<e1;ii += (e1-s1)/3)
			for(int jj=s2;jj<e2;jj += (e2-s2)/3)
				solve(ii,jj,ii+(e1-s1)/3 , jj + (e2-s2)/3);
	else 
		cnt[arr[s1][s2]+1] += 1;
    
	return;
}

int main()
{
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> arr[i][j];
	solve(0,0,N,N);
    
	for(i=0;i<3;i++)
		printf("%d\n",cnt[i]);
}