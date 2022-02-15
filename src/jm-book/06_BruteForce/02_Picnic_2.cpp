#include <iostream>
#include <vector>
using namespace std;
//algospot.com/judge/problem/read/PICNIC

/*
문제명: PICNIC
TL: 1s
ML: 64MB

TU: 2h
TS: 0ms
LEN: 1.4KB


Good
1. 배운 것을 이용한 시간복잡도 계산
2. 배운 것을 이용한 함수 구현

Bad
1. 쪼개어진 unpicked를 많이 응용하지 못했다.
(for문에서의 elem사용 + pick을 unpicked.front()로의 응용)
2. vector보다 deque가 나았을 듯함.

IAN
1. for문에서 i를 사용하여 여러번 출력이 됨.
2. unpicked 최신화가 안되었음.

NEW
1. itr = v.erase 복습.
2. vector은 pop_back가 없다.


Q1: 
A1: 


Solution:
1. arr에 친구관계를 담고, 재귀함수로 친구를 매긴다.

Approach: 
문자열을 분리했던 Pick문제와 비슷하였다.
Clue:
문제의 분할이 가능해보였다.
Reconstruction : 
*/


int TC,N,M;
bool isFriend[11][11];
bool noFriend[11];

void print_vector(int picked, vector<int>& v)
{
	
	cout << picked << " (picked): ";
	for(auto& elem : v)
		cout << elem << ',';
	cout << '\n';
}
int makePair(int picked,vector<int>& unpicked)
{
	
	if(unpicked.size() == 0)
		return 1;
	else if(picked <0 || picked >= N)
	{
		cout << "Err";
		return false;
	}
	else if(noFriend[picked])
	{
		cout <<"solo";
		return false;
	}
	
	int i,ret = 0;
	vector<int>::iterator itr = unpicked.erase(unpicked.begin());
	
	//print_vector(picked,unpicked);
	for(auto& elem: unpicked)
	{
		if(isFriend[picked][elem] == false)
			continue;
		int tmp = elem;
		if(ret < 0)
			return ret * 10;
		for(itr = unpicked.begin(); itr != unpicked.end(); ++itr)
		{
			//cout << *itr <<", ";
			if(*itr == elem)
			{
				itr = unpicked.erase(itr);
				break;
			}
		}
		//cout << "[start]ret: " << ret  << " picked : " << picked << " i : " << tmp << '\n';
		ret += makePair(unpicked.front(),unpicked);
		//cout << "[end]ret: " << ret  << " picked : " << picked << " i : " << tmp << '\n';
		unpicked.insert(itr,tmp);
	}
	itr = unpicked.insert(unpicked.begin(),picked);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> TC;
	
	while(TC--)
	{
		cin >> N >> M;
		fill(&isFriend[0][0],&isFriend[10][10],false);
		fill(&noFriend[0],&noFriend[10],true);
		int a,b;
		vector<int> unpicked;
		for(int i=0;i<M;i++)
		{
			cin >> a >> b;
			isFriend[a][b] = true;
			isFriend[b][a] = true;
			noFriend[a] = false;
			noFriend[b] = false;
		}
		if(N%2 != 0 || M == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		for(int i=0;i<N;i++)
			unpicked.push_back(i);
		
		cout << makePair(0,unpicked) << '\n';
	}
}