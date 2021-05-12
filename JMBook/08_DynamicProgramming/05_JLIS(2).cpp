#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const long long NEGATIVE_INF = numeric_limits<long long>::min();
int N,arrLen[2],cache[101][101],arr[2][101];
//420ms
int JLIS(int aIdx, int bIdx)
{
	int& ret = cache[aIdx+1][bIdx+1];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0;i<2;++i)
	{
		int idx = (i==0 ? aIdx : bIdx);
		long long aValue = (aIdx == -1 ? NEGATIVE_INF : arr[0][aIdx]);
		long long bValue = (bIdx == -1 ? NEGATIVE_INF : arr[1][bIdx]);854545454545
		long long maxValue = max(aValue,bValue);
		for(int start = idx+1;start<arrLen[i];++start)
		{
			if(maxValue < arr[i][start])
			{
				if(i==0)
					ret = max(ret,JLIS(start,bIdx)+1);
				else
					ret = max(ret,JLIS(aIdx,start)+1);
			}
		}
	}
	return ret;
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
		cin >> arrLen[0] >> arrLen[1];
		memset(cache,-1,sizeof(cache));
		
		for(int i=0;i<2;++i)
			for(int j=0;j<arrLen[i];++j)
				cin >> arr[i][j];
		
		cout << JLIS(-1,-1) << '\n';
	}
}