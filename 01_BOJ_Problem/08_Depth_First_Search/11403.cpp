#include <iostream>
using namespace std;
//acmicpc.net/problem/11403
오후 1:54 2021-02-07

경로 찾기 1 1256 
11403

/*
문제명: 경로 찾기
TL: 1s
ML: 256MB



Good
1. 시간지체 -> 다른 풀이를 고려하였다.
2. 정확히 알지 못하엿으나 다른 사람의 코드를 이해하려 노력하였다.
3. 

Bad
1. stack으로 풀었던 기존의 문제와 다름을 인지못하였다. (stack구현시의 특징을 이해하지 못하였다.)
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h
TS: 3ms
MS: 2036KB
*/
bool visited[101][101]; // x행에서 시작되어  y열을 거쳤음을 의미
bool arr[101][101];
int N;
void dfs(int start,int x,int y)
{
	visited[start][y] = true; // y는 이동할 행의 주소
	arr[start][y] = 1;  //start는 시작되었던 행의 주소
	for(int i=0;i<N;i++)
		if(arr[y][i] && !visited[start][i]) // arr는 참인지 조사 visite는 i행을 이미 start에 넣었는지 조사
			dfs(start,y,i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> arr[i][j];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			if(!visited[i][i] && arr[i][j]) dfs(i,i,j); // arr는 값이 참인지 조사 visit는 이미 ㅇ작업이 완료된 행인지 조사.(중복 조사)
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << arr[i][j];
			if(j != N-1)
				cout << " ";
			else
				cout <<"\n";
		}
	}
}

/*
dfs(1~N)을 N번 실행한다.
간선의 수가 N이하이므로 N번실행하면 모두 맞춰진다.
시간도 100^3이므로 안전하다.
하지만 dfs라고 부를 순 없다.

bool visited[101];
bool arr[101][101];
int N;
vector<int> s;
void dfs(int idx)
{
	for(int i=0;i<N;i++)
	{
		if(arr[idx][i])
		{
			for(int j=0;j<N;j++)
				arr[idx][j] += arr[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> arr[i][j];
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			dfs(j);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout << arr[i][j];
			if(j != N-1)
				cout << " ";
			else
				cout <<"\n";
		}
	}
}
*/