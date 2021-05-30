#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> h;
int solve(int left, int right)
{
	if(left == right)
		return h[left];
		
	int mid = (left + right) /2;
	
	int ret = max(h[mid], solve(left,mid));
	ret = max(ret,solve(mid+1,right));
	
	int fenceHeight = h[mid];
	int lo = mid , hi = mid +1;

	while(lo >= left || hi <= right)
	{
	//	if(hi == right && lo == left)
		if(hi > right || (lo >= left && h[lo] >= h[hi]))
		{
			fenceHeight = min(fenceHeight, h[lo]);
			lo--;
		}
		else
		{
			fenceHeight = min(fenceHeight, h[hi]);
			hi++;
		}
		ret = max(ret, fenceHeight *(hi - lo - 1));	
	}
	
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC,N;
	
	cin >> TC;
	
	while(TC--)
	{
		cin >>N;
		h.resize(N);
		for(int i=0; i<N;++i)
			cin  >> h[i];
		cout << solve(0,N-1) << '\n';
	}

}