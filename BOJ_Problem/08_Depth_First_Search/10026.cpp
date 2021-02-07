#include <iostream>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/10026

/*
문제명: 적록색약
TL: 1s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. 
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 24m
TS: 0ms
MS: 2112KB
*/

bool visited[101][101];
char arr[101][101];
int movement[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int N;

void dfs(int i,int j,bool impairment)
{
	visited[i][j] = true;
	for(int k=0;k<4;k++)
	{
		if(i + movement[k][0] < 0 || i + movement[k][0] >= N|| j + movement[k][1] < 0 || j + movement[k][1] >= N)
			continue;
		if(!visited[i + movement[k][0]][j + movement[k][1]])
		{
			if(arr[i][j]==arr[i + movement[k][0]][j + movement[k][1]])
				dfs(i + movement[k][0],j + movement[k][1],impairment);	
			else if(impairment && ((arr[i][j]== 'R' && arr[i + movement[k][0]][j + movement[k][1]] == 'G') ||(arr[i][j]== 'G' && arr[i + movement[k][0]][j + movement[k][1]] == 'R')))
				dfs(i + movement[k][0],j + movement[k][1],impairment);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	int cnt_normal = 0, cnt_impairment = 0;
	//impairment는 적록색약을 의미한다.
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cin >> arr[i][j];
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!visited[i][j])
			{
				dfs(i,j,false);
				cnt_normal++;
			}
		}
	}
	
	fill(visited[0],visited[101],false);
	
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!visited[i][j])
			{
				dfs(i,j,true);
				cnt_impairment++;
			}
		}
	}
	cout << cnt_normal <<" "<< cnt_impairment;
}