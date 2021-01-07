#include <iostream>
//https://www.acmicpc.net/problem/1449
//acmicpc.net/problem/1449

/*
문제명: 동전 0
TL: 2s
ML: 256MB



G
1 그리디 알고리즘의 전형적인 문제를 바로 풀수있었다.
2 case분리를 하였는데 잘했지만 case가 최대 10개라 무의미했다. -> case의 개수를 고려하여 해야한다.
3 빨리 풀었다.
B
1 while문을 이용했는데 for문을 이용하는게 더 가시성이 좋다.
2 if문으로 비교하는 문장은 필요가 없었다 가시성을 해쳤다.
3 idx가 아니라 i를 썻으면 더 좋았을것같다. 여기서 한번 틀렸다. (idx의 값을 설정하는 부분)

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 20m
TS: 0ms
MS: 2016KB
*/



G
1 그리디 알고리즘의 전형적인 문제를 바로 풀수있었다.
2 case분리를 하였는데 잘했지만 case가 최대 10개라 무의미했다.
3 빨리풀긴했다. 20분정도
B
1 while문을 이용했는데 for문을 이용하는게 더 가시성이 좋다.
2 if문으로 비교하는 문장은 필요가 없었다 가시성을 해쳤다.
3 idx가 아니라 i를 썻으면 더 좋았을것같다. 여기서 한번 틀렸다. (idx의 값을 설정하는 부분에서)

Q1.도중에 멈춰도 작동하나?
A1. O

TS : 20m

*/

int main()
{
	int N,K,cnt = 0, idx;
	int money[11];
	
	scanf("%d %d",&N,&K);
	idx = N - 1 ; //오류 케이스 보고 ㅁ나듬
	for(int i=0;i<N;i++)
	{
		scanf("%d",money + i);
		if(money[i] > K)
		{
			idx = i-1;
			i= 12;
		}
	}
	while(idx >= 0 && K != 0)
	{
		cnt += K / money[idx];
		K = K %money[idx];
		idx--;
	}
	printf("%d",cnt);
	
	//오류 케이스 1 17 1 일 때
	
}