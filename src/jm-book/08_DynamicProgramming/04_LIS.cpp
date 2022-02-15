#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, dp[501][501];
vector<int> arr(501);
int LIS(int max_idx,int start)
{
	if(start >= N) return 0;
	int& ret = dp[max_idx][start];
	if(ret != -1) return ret;
	int cand1 = 0, cand2;
	
	if(arr[start] > arr[max_idx]) cand1 = LIS(start,start + 1) + 1;
	
	cand2 = LIS(max_idx, start + 1);
	
	return ret = cand1 > cand2 ? cand1 : cand2;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		memset(dp,-1,sizeof(dp));
		cin >> N;
		for(int i=0;i<N;++i)
		{
			cin >> arr[i];
		}
		arr[N] = -1;
		cout <<  LIS(N,0) << '\n';
	}

}