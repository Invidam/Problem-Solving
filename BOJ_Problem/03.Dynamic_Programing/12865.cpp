#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/12865

/*
문제명: 평범한 배낭
TL: 2s
ML: 512MB



Good
1. 동전 2와 유사한 문제임을 인식하여 해결하였다.
2. 
3. 

Bad
1. 동전 2와 동일한 문제로 착각하여 다소 해맸다. -> 비슷한 문제의 풀이법을 참고할 경우 같은 점 뿐만이 아닌 다른 점이 있음을 유의한다.
2. 
3. 

conceipt: 
solution: 물건을 넣었을 때, 넣지 않았을 때로 나누며,  최대 가치를 dp로 기록하며 해결.

Q1: 풀이 2도 dp라고 봐야하나?
A1: dp란 문제를 쪼개서 풀며, 그 결과로 주어진 문제를 푸는 것. 즉 dp라고 보기 어렵다고 생각한다.
https://www.acmicpc.net/board/view/61739 참고
+ dp중에서 바로 직전의 정보만 참고하는 dp도 존재한다. 따라서 dp가 맞다.


NEW : 숫자 사이에 '을 넣어 1,000 처럼 표현할 수 있다 (separator이라고 한다.)
https://en.cppreference.com/w/cpp/language/integer_literal 참고.

keypoint: 

TU: 1h20m
TS: 60ms
MS: 42252KB
*/

// 풀이 2
int dp[100'001];
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);		
	int N,K,w,v;
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> w>> v;
		if(w <= K)
		{
			for(int j=K;j>=w;j--)// 추가 입력된 w까지 고려하여 만들수 있는 dp[]의 최댓값을 갱신한다.
				dp[j] = max(dp[j] , dp[j-w]+ v), printf("%d : %d\n",j,dp[j]);
			
		}
	}
	cout << dp[K];
}
/*
//풀이 1
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int > p;
int dp[101][100001];
p arr[100001];

int solve(int idx, int max_w)
{
	if(idx < 0)
		return 0;
	
	if(arr[idx].first > max_w)
	{
		dp[idx][max_w] = solve(idx-1,max_w);
		return dp[idx][max_w];
	}
	
	if(dp[idx][max_w] != 0)
		return dp[idx][max_w];
	
	dp[idx][max_w] = arr[idx].second;
	if(max_w - arr[idx].first >= 0 )
		dp[idx][max_w] = max(dp[idx][max_w],solve(idx-1,max_w -arr[idx].first)+arr[idx].second);
	dp[idx][max_w] = max(dp[idx][max_w],solve(idx-1,max_w));
	
	return dp[idx][max_w];
	
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);		
	int N,K;
	cin >> N >> K;
	for(int i=0;i<N;i++)
	{
		cin >> arr[i].first >> arr[i].second;
		if(arr[i].first > K || arr[i].second == 0 )
		{
			N--;
			i--;
		}
	}
	sort(arr,arr+N);
	
	cout << solve(N-1,K);
}
*/