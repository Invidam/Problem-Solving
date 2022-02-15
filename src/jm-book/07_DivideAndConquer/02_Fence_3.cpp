#include <iostream>
#include <algorithm>
using namespace std;
/*
while문의 시간복잡도가 O(부분문제의 크기)가 되어야 전체 시간복잡도가 O(nlgn)이 된다.
*/
int arr[20001], N;

int makeFence(int start, int end)
{
	if(start == end) return arr[start];
	
	int mid = (start + end) /2;
	int ret = max(makeFence(start,mid),makeFence(mid+1,end));
	int low = mid, high = mid + 1, height = min(arr[mid],arr[mid+1]);
	
	ret = max(ret,height*2);
	
	while(start < low || high < end)
	{
		if((start < low ) && ((high >= end) || arr[low -1] >= arr[high+1]))
		{
			low--;
			height = min(height,arr[low]);
		}
		else
		{
			high++;
			height = min(height,arr[high]);
		}
		
		ret = max(ret,height * (high - low +1));
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
		cin >> N;
		
		for(int i=0;i<N;++i)
			cin >> arr[i];
		
		cout << makeFence(0,N-1) << '\n';
	}
}