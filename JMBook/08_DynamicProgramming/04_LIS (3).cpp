#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[502],cache[502][502],N;
//cache[n][n] = 45ms / cache[n] + for(n) : 12ms
//last까지 선택하였을 때, from에서부터의 길이를 리턴
int LIS(int last, int from)
{
	if(last >= N || from >= N) return 0;
	
	int& ret = cache[last+1][from];
	if(ret != -1) return ret;
	
	if(last == -1 || arr[from] > arr[last])
		ret = LIS(from,from+1)+1;
	
	return ret = max(ret,LIS(last,from+1));
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
		cin >> N;
		memset(cache,-1,sizeof(cache));
		
		for(int i=0;i<N;++i)
				cin >> arr[i];
		
		cout << LIS(-1,0) << '\n';
		
	}
}