#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
//acmicpc.net/problem/10265

/*
문제명: MT
TL: 1s
ML: 256MB
2	1	4	5	6	7	8	9	10	11	12	13	10	15	16	17	18	19	14



Good
1. 
2. 
3. 

Bad
1. 앞으로 메모장에 적어놓은 것들다 못풀면 여기에 주석처리해 남겨놓자. 도움을 얻을 수 있을 것 같다.
2. 가방 문제 탑다운 바텀업 다시 복습하기 dp 시간복잡도 복습하기 탑다운 시 dp(0,0) or dp(M,N) 인지 찾아보기 (내 깃헙 혹은 다른 자료들) 이 문제 다ㅡㄴ사람 코드도 보기
3. 가방문제 짧은 풀이법 다시 보기.

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 4h
TS: 0ms
MS: 5944KB
*/

using namespace std;
typedef pair<int, int> p;
int dp[1'001];
p arr[1001];
int n,k,max_idx = 0, graph[1001],ans = 0;
const int CHECK = 1000;
bool visited[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
	{
		cin >> graph[i];
		graph[i]--;
	}
	
	for(int i=0;i<n;i++)
	{
		if(visited[i])
			continue;
		vector<int> s;
		int cycle_nodes = 0;
		int tail_nodes = 0;
		
		s.push_back(i);
		visited[i] = true;
		
		while(!s.empty())
		{
			//cout << "In s," << i << "s back : " << s.back() << " grpah : " << graph[s.back()] << '\n';
			if(visited[graph[s.back()]]) // cycle 감지
			{
				int cycle_point = graph[s.back()];
				if(graph[cycle_point] < CHECK) // 이번 stack에서 cycle 발생
				{
					while(s.back() != cycle_point)
					{
						cycle_nodes++;
						graph[s.back()] = max_idx + CHECK;
						s.pop_back();
					}
					cycle_nodes++;
					graph[s.back()] = max_idx + CHECK;
					s.pop_back();
					//cycle_point에 대해서도 실행.
					tail_nodes = s.size();
					while(!s.empty())
					{
						graph[s.back()] = max_idx + CHECK;
						s.pop_back();
					}
					arr[max_idx++] = p(cycle_nodes,tail_nodes); // 새로운 cycle,tail을 가지는 arr idx 생성
				}
				else // 다른 cycle에 접근
				{
					int tail_idx = graph[cycle_point] - CHECK;
					tail_nodes = s.size();
					while(!s.empty())
					{
						graph[s.back()] = tail_idx + CHECK;
						s.pop_back();
					}
					arr[tail_idx].second += tail_nodes; // 다른 cycle이 가지고있던 tail의 개수에 자신의 tail 개수 더함.
				}
			}
			else // 일반적인 그래프 순회
			{
				s.push_back(graph[s.back()]);
				visited[s.back()] = true;
			}
		}
	}
	// 여기까지는 완료함.
	
	
	//arr[idx]에 필요한 수들이 들어있다고 치자.
	//fill(&dp[0][0], &dp[1001][1001],0);
	for(int i=0;i<max_idx;i++)
	{
		for(int j=0;j<=k;j++)
		{
			int ret;
			//arr의 i까지를 사용해서 j이하의 수를 만들때, 그 수의  최대값.
			if(j == 0)
			{
				if(arr[i].first < j)
					dp[j] = 0;
				else if(arr[i].first + arr[i].second >= k)
					dp[j] = j;
				else
					dp[j] = arr[i].first + arr[i].second;
			}
			else
			{
				ret = dp[j];
				if(ret == j);
				else if(j - arr[i].first - arr[i].second <= 0 && j - arr[i].first >= 0) // j 가 arr를 통해 만들 수 있는 값보다 작을 때, 즉 arr가 j이상일 때
					ret = j;
				else if(j - arr[i].first - arr[i].second > 0)
					for(int k=0;k<=arr[i].second;k++)
						ret = max(ret,dp[j-k-arr[i].first] +dp[arr[i].first + k]);
				
			}
			if(ret > ans)
				ans = ret;
			dp[j] = ret;
			
		}
	}
	cout << ans;
	
	/*
	9 6
	2 3 4 5 1 7 6 6 9
	->
	0	1	2
	5,0 2,1 1,0
	*/
}
//https://m.blog.naver.com/PostView.nhn?blogId=angs91&logNo=220930702887&navType=tl

/*
dp[1000][1000]
을 dp[2][1000]을 바꾸고 idx에 따라 idx%2로 전에것과 최신것을 구분하였다.

메모리가 2036으로 많이 감소하였다.



#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> p;
int dp[2][1'001];
p arr[1001];
int n,k,max_idx = 0, graph[1001],ans = 0;
const int CHECK = 1000;
bool visited[1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	
	for(int i=0;i<n;i++)
	{
		cin >> graph[i];
		graph[i]--;
	}
	
	for(int i=0;i<n;i++)
	{
		if(visited[i])
			continue;
		vector<int> s;
		int cycle_nodes = 0;
		int tail_nodes = 0;
		
		s.push_back(i);
		visited[i] = true;
		
		while(!s.empty())
		{
			//cout << "In s," << i << "s back : " << s.back() << " grpah : " << graph[s.back()] << '\n';
			if(visited[graph[s.back()]]) // cycle 감지
			{
				int cycle_point = graph[s.back()];
				if(graph[cycle_point] < CHECK) // 이번 stack에서 cycle 발생
				{
					while(s.back() != cycle_point)
					{
						cycle_nodes++;
						graph[s.back()] = max_idx + CHECK;
						s.pop_back();
					}
					cycle_nodes++;
					graph[s.back()] = max_idx + CHECK;
					s.pop_back();
					//cycle_point에 대해서도 실행.
					tail_nodes = s.size();
					while(!s.empty())
					{
						graph[s.back()] = max_idx + CHECK;
						s.pop_back();
					}
					arr[max_idx++] = p(cycle_nodes,tail_nodes); // 새로운 cycle,tail을 가지는 arr idx 생성
				}
				else // 다른 cycle에 접근
				{
					int tail_idx = graph[cycle_point] - CHECK;
					tail_nodes = s.size();
					while(!s.empty())
					{
						graph[s.back()] = tail_idx + CHECK;
						s.pop_back();
					}
					arr[tail_idx].second += tail_nodes; // 다른 cycle이 가지고있던 tail의 개수에 자신의 tail 개수 더함.
				}
			}
			else // 일반적인 그래프 순회
			{
				s.push_back(graph[s.back()]);
				visited[s.back()] = true;
			}
		}
	}
	// 여기까지는 완료함.
	
	
	//arr[idx]에 필요한 수들이 들어있다고 치자.
	//fill(&dp[0][0], &dp[1001][1001],0);
	for(int i=0;i<max_idx;i++)
	{
		for(int j=0;j<=k;j++)
		{
			int ret;
			//arr의 i까지를 사용해서 j이하의 수를 만들때, 그 수의  최대값.
			if(j == 0)
			{
				if(arr[i].first < j)
					dp[i%2][j] = 0;
				else if(arr[i].first + arr[i].second >= k)
					dp[i%2][j] = j;
				else
					dp[i%2][j] = arr[i].first + arr[i].second;
			}
			else
			{
				ret = dp[!(i%2)][j];
				if(ret == j);
				else if(j - arr[i].first - arr[i].second <= 0 && j - arr[i].first >= 0) // j 가 arr를 통해 만들 수 있는 값보다 작을 때, 즉 arr가 j이상일 때
					ret = j;
				else if(j - arr[i].first - arr[i].second > 0)
					for(int k=0;k<=arr[i].second;k++)
						ret = max(ret,dp[!(i%2)][j-k-arr[i].first] +dp[i%2][arr[i].first + k]);
				
			}
			if(ret > ans)
				ans = ret;
			dp[i%2][j] = ret;
			
		}
	}
	cout << ans;
}

*/