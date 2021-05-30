#include <iostream>
#include <algorithm>
using namespace std;

int fence[20001];

int solve(int start,int end) // [start,end]
{
	if(start==end)	
		return fence[start];
	
	int mid = (start + end) / 2;
	int ret = max(solve(start,mid),solve(mid +1, end)); 
	
	int minHeight = fence[mid], s = mid, e = mid+1;
	
	while(s >= start || e <= end)
	{
		int len =  e-s;
		
		if(s >= start && (e > end || fence[s] >= fence[e]))
		{
			minHeight = min(minHeight,fence[s]);
			ret = max(ret,len*minHeight);
			s--;
		}
		else
		{
			minHeight = min(minHeight,fence[e]);
			ret = max(ret,len*minHeight);
			e++;
		}
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N;
		for(int i=0;i<N;++i)
			cin >> fence[i];
		
		cout << solve(0,N-1) << '\n';
	}
	
}