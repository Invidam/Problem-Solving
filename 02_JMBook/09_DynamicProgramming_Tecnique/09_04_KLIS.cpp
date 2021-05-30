#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 2*1e9;
int cache[501],arr[501],cnt[501][501];
int N;
pair<int, int> sorted[501];

/*
148sec
사전순을 잘못 이해해서(예제를 제대로 보지 않음) 한번 틀림
오버플로우에서, ret설정 잘못해서 한번 틀림

*/
int LIS(int n)
{
	int& ret = cache[n+1];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int i=n+1;i<N;++i)
		if(n == -1 || arr[n] < arr[i])
			ret = max(ret,LIS(i) + 1);
	
	return ret;
}

int makeCnt(int n,int len)
{
	if(len == 1) return 1;
	
	int& ret = cnt[n+1][len];
	if(ret != -1) return ret;
	
	ret = 0;
	long long cand = 0;
	for(int i=n+1;i<N;++i)
	{
		if(n == -1 || arr[n] < arr[i])
		{
			cand += (long long)makeCnt(i,len-1);
			if(cand > MAX) return ret = MAX;
		}
	}
	
	return ret = (int)cand;
}
string KLIS(int n,int k,int len)
{
	 // cout << " n : " << n << " k: "  << k << '\n';
	
	for(int i=0;i<N;++i)
	{
		if(sorted[i].second < n) continue;
		int next = sorted[i].second;
		if(n != -1 && arr[n] >= arr[next]) continue;
		// cout << "next: " << next << " ";
		 // cout << " makeCnt : " <<makeCnt(next,len) << '\n';
		if(makeCnt(next,len) >= k) return to_string(arr[next]) + " " +KLIS(next,k,len-1);
		else k -= makeCnt(next,len);	
	}
	
	return "";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int TC;
	cin >> TC;
	
	while(TC--)
	{
		memset(cache,-1,sizeof(cache));
		memset(cnt,-1,sizeof(cnt));
		int K;
		cin >> N>> K;
		for(int i=0;i<N;++i)
		{
			cin >> arr[i];
			sorted[i] = make_pair(arr[i],i);
		}
		sort(sorted,sorted + N);
		int len =  LIS(-1);
		cout << len << '\n';
		
		makeCnt(-1,len+1);
		cout << KLIS(-1,K,len) << '\n';
	}
}