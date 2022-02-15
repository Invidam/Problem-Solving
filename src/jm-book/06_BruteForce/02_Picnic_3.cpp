#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//acmicpc.net/problem/PICNIC

/*
문제명: 피크닉
TL: 1s
ML: 64mb

TU: 30m
TS: 4ms
LEN: 1.4kb


Good
1. 간결해짐

Bad
1. 

IAN
1. lastValue를 신경X
2. ++j를 ++i로함;

NEW
1. -


Q1: -
A1: -


Solution: 
1. 서로 친구인 2명을 notChoosed에서 제외한 후, 재귀함수 호출하여 ret 갱신
2. 단, 이미 뽑힌 친구들을 다시 선택 못하게 i는 이미 뽑힌 첫번째보다 크게 설정하며 j = i+1부터 한다.

Approach: 
1. pick문제와 유사함.

Clue:
1. 부분문제로 치환하여 풀 수 있는 문자열이 존재.

Reconstruction : 
*/

bool isFriend[11][11];

int makeArray(vector<int>& notChoosed,int lastValue)
{
	if(notChoosed.empty()) return 1;
	int ret = 0, n = notChoosed.size();
	
	for(int i=0;i<n;++i)
	{
		if(notChoosed[i] < lastValue) continue;
		
		for(int j=i+1;j<n;++j)
		{
			int a = notChoosed[i], b = notChoosed[j];
			if(!isFriend[a][b]) continue;
			
			notChoosed.erase(notChoosed.begin() + j);
			notChoosed.erase(notChoosed.begin() + i);
			
			ret += makeArray(notChoosed,a);
			
 			notChoosed.insert(notChoosed.begin() + i,a);
 			notChoosed.insert(notChoosed.begin() + j,b);
		}
	}
	
	return ret;
}

int arrayCnt(int N)
{
	vector<int> notChoosed;
	for(int i=0;i<N;++i)
		notChoosed.push_back(i);
	
	return makeArray(notChoosed,-1);
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
		memset(isFriend,false,sizeof(isFriend));
		int N,M,a,b;
		cin >> N >> M;
		
		if(N%2 == 1)
		{
			cout << 0 << '\n';
			continue;
		}
		
		for(int i=0;i<M;++i)
		{
			cin >> a >> b;
			isFriend[a][b] = true;
			isFriend[b][a] = true;
		}
		//makeArray(아직 짝이 안정해진 리스트)
		int ret = arrayCnt(N);
		cout << ret << '\n';
	}
}