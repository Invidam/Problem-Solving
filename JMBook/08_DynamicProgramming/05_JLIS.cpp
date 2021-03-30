#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N1,N2, cache[501][501];
vector<int> arr1(501),arr2(501);
int LIS(int s1,int s2)
{
	int& ret = cache[s1+1][s2+1];
	if(ret != -1) return ret;
	
	ret = 1;
	for(int next = s1+1;next < N1;++next)
	{
		if((s1 == -1 || arr1[s1] < arr1[next] )&&(s2 == -1  ||arr2[s2] < arr1[next]))
			ret = max(ret,LIS(next,s2)+1);
	}
	for(int next = s2+1;next < N2;++next)
	{
		if((s2== -1 || arr2[s2] < arr2[next] )&& (s1 == -1 || arr1[s1] < arr2[next]))
			ret = max(ret,LIS(s1,next)+1);
	}
	//ret = ret -(s1 == N1-1) - (s2 == N2-1);
	return ret;
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
		memset(cache,-1,sizeof(cache));
		cin >> N1 >> N2;
		for(int i=0;i<N1;++i)
			cin >> arr1[i];
			
		for(int i=0;i<N2;++i) 
			cin >> arr2[i];
			
		cout <<  LIS(-1,-1) - 1<< '\n';
	}

}