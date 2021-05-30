#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/2583

/*
문제명: 영역 구하기
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

NEW :	지역변수가 메모리 적게 든다고 한다.
keypoint: 

TU: 36m
TS: 0ms
MS: 2372KB
*/
bool visited[101][101];
bool arr[101][101];
int movement[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int M,N;

int dfs(int i,int j)
{
	int nodes = 1;
	visited[i][j] = true;
	for(int k=0;k<4;k++)
	{
		if(i + movement[k][0] < 0 || i + movement[k][0] >= M|| j + movement[k][1] < 0 || j + movement[k][1] >= N )
			continue;
		if(!visited[i + movement[k][0]][j + movement[k][1]] && !arr[i + movement[k][0]][j + movement[k][1]])
			nodes += dfs(i + movement[k][0],j + movement[k][1]);
	}
	
	return nodes;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> ans;
	int K,a,b,c,d;
	cin >> M >> N >> K;
	
	for(int i=0;i<K;i++)
	{
		cin >> a >> b >> c >> d;
		//arr[b][a] ~ arr[d-1][c-1]까지 채우기
		for(int x=b;x<d;x++)
			for(int y=a;y<c;y++)
				arr[x][y] = true;
	}
	
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(!visited[i][j] && !arr[i][j])
				ans.push_back(dfs(i,j));
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(vector<int>::iterator itr = ans.begin();itr != ans.end();itr++)
	{
		cout << *itr;
		if(itr != ans.end() -1 )
			cout << " ";
	}
}