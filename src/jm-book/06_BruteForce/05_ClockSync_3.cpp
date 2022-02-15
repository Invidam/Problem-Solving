#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 987654321,MAX_CLOCK = 16;
int arr[MAX_CLOCK];
const vector<vector<int>> clockList = 
{
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

void clickSwitch(int idx)
{
	for(int i = 0;i<clockList[idx].size();++i)
	{
		int clockIdx = clockList[idx][i];
		int& linkedClock = arr[clockIdx];
		linkedClock += 3;
		
		while(linkedClock > 12)
			linkedClock -= 12;
	}
}

bool isSync()
{
	for(int i=0;i<MAX_CLOCK;++i)
		if(arr[i] != 12) return false;
	
	return true;
}

int operateClock(int here,int clickCnt)
{
	if(isSync()) return clickCnt;
	if(here >= clockList.size()) return INF;
	
	int ret = INF;
	
	for(int i = 0;i<4;++i)
	{
		int cand = operateClock(here+1,clickCnt +i);
		ret = min(ret,cand);
		clickSwitch(here);
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	
	int TC;
	cin >> TC;
	
	while(TC--)
	{
		for(int i=0;i<MAX_CLOCK;++i)
			cin >> arr[i];
		
		int ans = operateClock(0,0);
		if(ans == INF) cout << "-1\n";
		else cout << ans << '\n';
	}
}