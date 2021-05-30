#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const double INIT_VALUE   = 987654321;
double dist[9][9], minDistance;
int N;

/*
minDistance 갱신 안해서 1번 틀림.

기존 코드와 차이점 

1.함수를 2개로 쪼개어 훨씬 보기 편해짐
(기존에는 재귀함수 임에도, firstcase를 분리하기 위해 코드가 부득이하게 길었음)

2. minDistance를 전역으로 빼놔서 갱신을 쉽게함.
(장단점이 있을 듯.)
[2번의 경우를 빼낸 함수도 작성함.]

*/
void makeDistance(vector<bool>& visited,double sum,int curr)
{
	bool allVisited = true;
	
	for(int next=0;next<N;++next)
	{
		if(visited[next]) continue;
		
		allVisited = false;
		
		visited[next] = true;
		sum += dist[curr][next];
		
		makeDistance(visited,sum,next);
		
		sum -= dist[curr][next];
		visited[next] = false;
	}
	
	if(allVisited)
		minDistance = min(minDistance,sum);
}

double getMinDistance()
{
	vector<bool> visited(N,false);
	for(int next=0;next<N;++next)
	{
		visited[next] = true;
		makeDistance(visited,0,next);
		visited[next] = false;
 	}
	
	return minDistance;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int TC;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N;
		minDistance = INIT_VALUE;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				cin >> dist[i][j];
		
		cout << getMinDistance() << '\n';
	}
}

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
double dist[9][9];
int N;

double makeDistance(vector<bool>& visited,double sum,int curr)
{
	double ret = 987654321;
	bool allVisited = true;
	
	for(int next=0;next<N;++next)
	{
		if(visited[next]) continue;
		
		allVisited = false;
		
		visited[next] = true;
		sum += dist[curr][next];
		
		double cand = makeDistance(visited,sum,next);
		
		ret = min(ret,cand);
		sum -= dist[curr][next];
		visited[next] = false;
	}
	
	if(allVisited)
		return sum;
	
	return ret;
}

double getMinDistance()
{
	double ret = 987654321;
	vector<bool> visited(N,false);
	for(int next=0;next<N;++next)
	{
		visited[next] = true;
		double cand = makeDistance(visited,0,next);
		ret = min(ret,cand);
		visited[next] = false;
 	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int TC;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				cin >> dist[i][j];
		
		cout << getMinDistance() << '\n';
	}
}
*/