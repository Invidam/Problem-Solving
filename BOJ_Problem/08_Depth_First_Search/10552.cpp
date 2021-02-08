#include <iostream>
using namespace std;
//acmicpc.net/problem/1.552

/*
문제명: DOM
TL: 1s
ML: 128MB



Good
1. 상황에 맞는 코드 작성 -> 메모리 시간 단축
2. 
3. 

Bad
1.예외 처리 못하였다. 다른수가 반복될 때가 예외이다. 
2.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h?
TS: 20ms
MS: 2676KB
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M,P,cnt = 0;
	
	int hate[100'001];// idx채널을 싫어하는 막내의 번째가 value
	int like[100'001];		  // idx번째가 좋아하는 채널이 value
	bool visited[100'001];
	fill(hate,hate+100'001,-1);
	fill(visited,visited+100'001,false);
	cin >> N >> M >> P;
	int channel = P;
	visited[channel] = true;
	for(int i=0;i<N;i++)
	{
		int tmp;
		cin >> like[i];
		cin >> tmp;
		if(hate[tmp] == -1)
			hate[tmp] = i;
	}
	while(1)
	{
		if(hate[channel] == -1)
			break;
		
		visited[channel] = true;
		channel = like[hate[channel]];
		cnt++;
		
		if(visited[channel])
		{
			cnt = -1;
			break;
		}
	}
	cout << cnt;
	
}

/*
메모리 단축위해 작성한 코드
bool visited[100'001]을
hate[100'001]을 -2로 설정하는 것으로 대신하였다.

#include <iostream>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M,P,cnt = 0;
	
	int hate[100'001];// idx채널을 싫어하는 막내의 번째가 value
	int like[100'001];		  // idx번째가 좋아하는 채널이 value
	bool visited[100'001];
	fill(hate,hate+100'001,-1);
	//fill(visited,visited+100'001,false);
	cin >> N >> M >> P;
	int channel = P;
	//visited[channel] = true;
	for(int i=0;i<N;i++)
	{
		int tmp;
		cin >> like[i];
		cin >> tmp;
		if(hate[tmp] == -1)
			hate[tmp] = i;
	}
	while(1)
	{
		int bef_channel = channel;
		if(hate[channel] == -1)
			break;
		
		channel = like[hate[channel]];
		hate[bef_channel] = -2;
		cnt++;
		
		if(hate[channel] == -2)
		{
			cnt = -1;
			break;
		}
	}
	cout << cnt;
	
}
*/