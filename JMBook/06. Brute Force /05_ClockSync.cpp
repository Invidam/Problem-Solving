#include <iostream>
#include <vector>
using namespace std;

//algospot.com/judge/problem/read/CLOCKSYNC

/*
문제명: CLOCKSYNC
TL: 10s
ML: 64MB

TU: 1h40m
TS: 3092ms
LEN: 1.5KB


Good
1. 

Bad
1. 시계의 주기성을 이용하지 못함
2. 때문에 시간복잡도 계산을 못하고, 기저사례를 잘 찾지못함.

IAN
1. 만들어놨던 데이터(arr)에 오류가 있을 수도 있음을 인지 못했다.

NEW
1. & 사용시 무조건 vector로 할 것.
2. 배열과 레퍼런스 동시 사용에 대해 공부할 것.
3. 최적화 문제의 특징을 공부하기. (차피 다 끝났으니 전부 복습)

Q1: 
A1: 


Solution: 시계를 저장한뒤 0~3번 돌리고 다음번 스위치에 대해 재귀함수 실행

Approach: 예제로 주어진 외판원 문제

Clue: 시계라는 특성을 이용한 주기성.(기저사례가 제시)
+ 작았던 변수의 범위(시계가 16개 밖에 없고, 스위치가 10개밖에 없음.) -> 낮은 시간복잡도.

Reconstruction : 
*/

//종만북 풀이 TS:  1440ms Len : 1.5kb
const int INF = 987654321, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS+1] = {
  "xxx.............",
  "...x...x.x.x....",
  "....x.....x...xx",
  "x...xxxx........",
  "......xxx.x.x...",
  "x.x...........xx",
  "...x..........xx",
  "....xx.x......xx",
  ".xxxxx..........",
  "...xxx...x...x.."};
	
void push(vector<int>& clockList, int switchNum)
{
	for(int clockIndex=0;clockIndex<CLOCKS;clockIndex++)
	{
		char clockChar = linked[switchNum][clockIndex];
		if(clockChar == '.')
			continue;
		
		clockList[clockIndex] += 3;
		if(clockList[clockIndex] > 12)
			clockList = 3;
	}
}

bool areAligned(vector<int>& clockList)
{
	bool ret =true;
	for(int i=0;i<16;i++)
		if(clockList[i] != 12) ret = false;
	return ret;
}

int solve(vector<int>& clockList,int currSwitch)
{
	
	if(currSwitch == SWITCHES) return areAligned(clockList) ? 0 : INF;
	
	int ret = INF;
	
	for(int i=0;i<4;i++)
	{
		int ans = syncClock(clockList,currSwitch + 1) + i;
		ret = ret < ans ? ret : ans;
		push(clockList,currSwitch);
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
		vector<int> clockList(16);
		for(int i=0;i<16;i++)
			cin >> clockList[i];
		
		int ans = syncClock(clockList,0);
		if(ans == INF)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}
}

/*
const int INF = 987654321;
int modifyList[10][5] = {
{0, 1, 2,-1,-1},
{3, 7, 9, 11,-1},
{4, 10, 14, 15,-1},
{0, 4, 5, 6, 7},
{6, 7, 8, 10, 12},
{0, 2, 14, 15,-1},
{3, 14, 15,-1,-1},
{4, 5, 7, 14, 15},
{1, 2, 3, 4, 5},
{3, 4, 5, 9, 13}
};

void changeClock(vector<int>& clockList, int modifyType,int delta)
{
	for(int i=0;i<5;i++)
	{
		int modifyIndex = modifyList[modifyType][i];
		
		if(modifyIndex == -1)
			continue;
		
		clockList[modifyIndex] += (delta *3);
		
		while(clockList[modifyIndex] <= 0)
			clockList[modifyIndex] += 12;
		while(clockList[modifyIndex] > 12)
			clockList[modifyIndex] %= 12;
		
	}
}

bool syncAll(vector<int>& clockList)
{
	bool ret =true;
	for(int i=0;i<16;i++)
		if(clockList[i] % 12 != 0) ret = false;
	return ret;
	
}
int syncClock(vector<int>& clockList,int currSwitch)
{
	
	
	if(currSwitch != 10);
	else if(syncAll(clockList))
		return 0;
	else
		return INF;
	
	int ret = INF;
	
	for(int i=0;i<4;i++)
	{
		changeClock(clockList,currSwitch,i);
		int ans = syncClock(clockList,currSwitch + 1) + i;
		ret = ret < ans ? ret : ans;
		changeClock(clockList,currSwitch,-i);
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
		vector<int> clockList(16);
		for(int i=0;i<16;i++)
			cin >> clockList[i];
		
		int ans = syncClock(clockList,0);
		if(ans == INF)
			cout << "-1\n";
		else
			cout << ans << '\n';
	}
}
*/