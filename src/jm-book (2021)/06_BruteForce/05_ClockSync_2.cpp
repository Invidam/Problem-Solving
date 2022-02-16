#include <iostream>
#include <vector>
using namespace std;
const int SWITCHES = 10;
const int CLOCKS = 16;
const int INF = 987654321;
const char linked[SWITCHES][CLOCKS+1] = { "xxx.............", "...x...x.x.x....", "....x.....x...xx", "x...xxxx........", "......xxx.x.x...", "x.x...........xx", "...x..........xx", "....xx.x......xx", ".xxxxx..........", "...xxx...x...x.."};

void shiftClock(vector<int>& clockList, int idx)
{
	for(int i=0;i<CLOCKS;++i)
	{
		if(linked[idx][i] == '.')
			continue;
		clockList[i] +=3;
		
		while(clockList[i] > 12 )
			clockList[i] %= 12; 
	}
}

bool allAligned(vector<int>& clockList)
{
	for(int i=0; i< CLOCKS; ++i)
		if(clockList[i] != 12) return false;
	
	return true;
}

int syncClock(vector<int>& clockList, int curr)
{
	if(curr == SWITCHES) return allAligned(clockList) ? 0 : INF;
	
	int ret = INF;
	
	for(int cnt = 0; cnt <4; cnt++)
	{
		int cand = cnt + syncClock(clockList, curr + 1);
		ret = ret < cand ? ret : cand;
		shiftClock(clockList, curr);
	}
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
		vector<int> clockList(CLOCKS);
		for(int i=0;i<CLOCKS;++i)
		{
			cin >> clockList[i];
		}
		int ans = syncClock(clockList,0);
		if(ans == INF) ans = -1;
		cout << ans << '\n';
	}

}