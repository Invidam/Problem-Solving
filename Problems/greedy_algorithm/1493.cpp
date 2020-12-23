#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
//acmicpc.net/problem/1493

/*
문제명: 
TL: 2s
ML: 128MB



Good
1. 구상을 하여 구현한거 자체로 잘한듯. 정답률이 낮은데
2. 그리디와 배운 것들을 잘 응용함
3. 시간이 오래걸렸지만 끝까지 푸

Bad
1. ll 사용 이유를 몰라서 몇 번 지체됨.
int max	2^31-1	2^9쯤
ll max	2^63-1	2^18쯤
2. 구상을 8개로 나눴는데 4개로 했어도 되었을듯. 조금 아쉬움
3. 코드가 너무 복잡해졌음. 함수 리턴을 이용하는게 pt은 줄어도 보기가 복잡해 st가 늘어남.

conceipt: 
solution: 
Q1: 
A1: 
keypoint: 

TS: 0ms
MS: 2112KB
CD: 1479B
*/

int arr[21] = {0,};
ll lwh[3];
int N,i,A,B;
ll ret=0;

bool subtract_arr(int idx,ll num)
{
	if(idx < 0)
		return false;
	if(arr[idx] - num >= 0) // 본인이 줄 수 있다면
	{
		ret+= num; //ret을 갱신
		arr[idx] -= num; //arr를 갱신
		return true;
	}
	//본인이 전부다 못푼다면
	num -= arr[idx];
	subtract_arr(idx,arr[idx]); //풀수 있을 만큼만 푼다.
	
	//그후 나머지를 밑에 인계한다.
	if(subtract_arr(idx-1,num*8)) //밑에서 가져올 수 있다면
		return true;
	else						 //아예 불가능하다면
		return false;
}

int fun(ll L,ll W,ll H)
{
	if(!L || !W || !H)
		return 0;
	ll m = min(min(L,W),H);
	int idx;
	int log_m = log(m)/log(2);
	ll unit[3], cnt = 1;
	for(idx=log_m;idx>=0 && !arr[idx];idx--) // 있는 곳을 찾아 idx가 멈춘다. 만약 없으면 -1을 리턴한다.
	if(idx == -1)
		return -1;
	//idx는 min(L,W,H)보다 작은 2^n중의 (가지고있는 수 중) 최대인 n이다.
	
	ll lwh_f[3] = {L,W,H};
	for(int i=0;i<3;i++)
	{
		unit[i] = lwh_f[i]/ (1 << idx); //
		cnt *=unit[i];
		unit[i] *= (1 << idx);
		//unit[i]에는 k가 들어가야 한다. 따라서 LWH를 2^n으로 나눠 k를 넣는다.
		//cnt는 k가 들어가야 한다. 따라서  / (1 << idx) 를 한다.
		//unit[i] 는 k*2^n이 되어야 한다. 즉 *= 1<< idx 이다.
		
	}
	//unit의 수들은 31 31 31이며 idx가 2일 때 즉 31 4 의 몫인 7을 의미한다.
	//printf("befor subt: idx :%d cnt :%d\n",idx, cnt);
	
	if(!subtract_arr(idx,cnt)) //가져올 수있는지 확인  [err occur] : 두번째 인자가 잘못된듯?
		return -1;
	//N N N을 놓는 코드
	
	for(int i=1;i<8;i++)
	{
			
		bool bfs[3] = {false, };
		int temp_i = i;
		bfs[0]= temp_i %2;
		bfs[1]= temp_i /2 %2 %2;
		bfs[2]= temp_i /4;
		//bfs[]는 {0,0,1} ~ {1,1,1}이다.
		
		if(fun(bfs[0] ? L - unit[0]: unit[0],bfs[1] ? W - unit[1]: unit[1],bfs[2] ? H - unit[2]: unit[2]) == -1) //실행시에 ret이 갱신. //[err occur] : 세그멘테이션 오류 코어 덤프드가 듬.
			return -1;
		
	}
	return 1;
	//7가지로 재실행하는 코드
	
}

int main()
{
	for(int i=0;i<3;i++)
		scanf("%lld",lwh+i);
	scanf("%d",&N);
	if(!N)
	{
		printf("-1");
		return 0;	
	}
		
	for(int i = 0;i<N;i++)
	{
		scanf("%d %d",&A,&B); // 2^A를 의미한다. 
		arr[A] = B;
	}
	if(fun(lwh[0],lwh[1],lwh[2]) == -1)
	{
		printf("-1");
		return 0;	
	}
	printf("%lld",ret);
}

/*

N N N		L-N N N
N W-N N	L-N W-N N

N N N-H		L-N N N-H
N W-N N-H	L-N W-N N-H
로 나눠서 해결함


//