#include <iostream>
#include <vector>
using namespace std;
const double INF = 99999;
const int MAX = 9;
double dist[MAX][MAX];
int N;
//algospot.com/judge/problem/read/TSP1

/*
문제명: TSP1 
TL: 1s
ML: 64MB

TU: 40m
TS: 36ms
LEN: 1.3KB


Good
1. 

Bad
1. 

IAN
1. 공백이 2칸인데 1칸으로 고려해서 오류 뜸. cin.get으로 한글자 입력받아 해결함.

NEW
1. 


Q1: 
A1: 


Solution:

Approach: 

Clue:

Reconstruction : 
*/


double shortestPath(vector<int>& path, vector<bool>& visited, double currLen)
{
	if(path.size() == N)
		return currLen;
	
	double ret = INF,cand;
	for(int next =0 ; next < N; next++)
	{
		
		if(path.size() == 0)
		{
			path.push_back(next);
			visited[next] = true;
			cand = shortestPath(path,visited,currLen);
			ret = ret < cand ? ret : cand;
			path.pop_back();
			visited[next] = false;
			
			continue;
		}
		if(visited[next])
			continue;
		
		visited[next] = true;
		int here = path.back();
		path.push_back(next);
		
		cand = shortestPath(path,visited,currLen + dist[here][next]);
		ret = ret < cand ? ret : cand;
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	char trash;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin >> dist[i][j];
				cin.get(trash);
			}
		}
		vector<bool> visited(N+1);
		vector<int> path;
		cout << fixed;
   		cout.precision(9);
		cout << shortestPath(path,visited,0) << '\n';
	}
}