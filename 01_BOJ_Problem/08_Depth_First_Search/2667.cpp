#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/2667

/*
문제명: 단지번호붙이기
TL: 1s
ML: 128MB



Good
1. 입력을 잘 만들었다.
2. 변형이 아니라 스스로 만들었다.
3. 

Bad
1. X
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 25m
TS: 0ms
MS: 2020KB
*/


bool visited[26][26];
bool arr[26][26];
int ans[313];
int idx,N;
int movement[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int i,int j)
{
	int nodes = 1;
	visited[i][j] = true;
	for(int k=0;k<4;k++)
	{
		if(i + movement[k][0] <0 || i + movement[k][0] >= N || j + movement[k][1] <0 || j + movement[k][1] >= N)
			continue;
		if(!visited[i + movement[k][0]][j + movement[k][1]] && arr[i + movement[k][0]][j + movement[k][1]])
			nodes += dfs(i + movement[k][0], j + movement[k][1]);
	}
	return nodes;
}
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j] && arr[i][j])	ans[idx++] = dfs(i,j);
	
	cout << idx << '\n';
	sort(ans,ans+idx);
	for(int i=0;i<idx;i++)
		cout << ans[i] << '\n';

}
