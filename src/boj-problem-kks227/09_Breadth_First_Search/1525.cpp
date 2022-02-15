#include <iostream>
#include <queue>
#include <cmath>
#include <set>
#include <utility>
using namespace std;
//acmicpc.net/problem/1525

/*
문제명: 퍼즐
TL: 1s
ML: 32MB



Good
1. 문제해결방법을 잘 고민하여 접근하였다.
(가능한 모든 경우를 미리 저장하려하였다. -> 메모리 초과 [32MB = 32*10^6 byte / 모든 경우는 최대 10^10 이므로 당연히 초과이다.])
(입력된 수를 변환시키고 visited가 초과되면 -1 ANS와 같으면 cnt 출력한다 -> 올바름.)
2. 
3. 

Bad
1. set,map에 대해 공부할 것.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
1. 메모리에 대해 정확히 알게 되었다.
(배열의 메모리는 변수의 크기* 배열의 size).
int 4byte 범위는 2^4^8
bool,char 1byte 2^1^8
long long 8byte 2^8^8 
2. 레퍼런스, 포인터, 일반변수가 함수의 인자로 줄 때 어떻게 다른지 확인하기. (어떠한 방식으ㅗ 이루어지ㅡ 지도.)
keypoint: 

TU: 2h40m
TS: 256ms
MS: 10786KB
*/


typedef pair<int , int> p;
set<int> s;
int N;
int offset[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
const int ANSWER = 123456780;

p find_zero_coord(int curr)
{
	for(int i=8;i>=0;i--)
	{
		if(curr / (int)pow(10,i) % 10 == 0)
			return p((8-i)/3,(8-i)%3);
	}
	return p(-1,-1);
}

int swap_zero(int curr,p zero,int roff,int coff)
{
	int tmp =  curr / (int)pow(10,8 - (roff * 3 + coff)) % 10;
	curr += tmp * (int)pow(10,8-(zero.first * 3 + zero.second));
	curr -= tmp * (int)pow(10,8 - (roff * 3 + coff));
	return curr;
}

bool visited(int val)
{
	if(s.find(val) != s.end())
		return true;
	else
		return false;
}

int bfs()
{
	s.insert(N);
	queue<int> q;
	int qsize,cnt_move = 1;
	q.push(N);
	//cout << swap_zero(N,find_zero_coord(N),1,2);
	//return -1;
	
	while(!q.empty())
	{
		qsize = q.size();
		for(int i=0;i<qsize;i++)
		{
			int curr = q.front();
			q.pop();
			p zero_coord = find_zero_coord(curr);
			
			for(int j=0;j<4;j++)
			{
				int roff = zero_coord.first + offset[j][0];
				int coff = zero_coord.second + offset[j][1];
				
				if(roff <0 || roff >= 3 || coff < 0 || coff >= 3)
					continue;
				int next = swap_zero(curr,zero_coord,roff,coff);
				if(visited(next))
					continue;
				if(next == ANSWER )
					return cnt_move;
				//cout << "lev :" << cnt_move << "next : " << next << '\n';
				q.push(next);
				s.insert(next);
			}
		}
		cnt_move++;
		if(cnt_move > 5)
			return -1;
	}
	
	
	return -1;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tmp;
	for(int i=8;i>=0;i--)
	{
		cin >> tmp;
		N += tmp * pow(10,i);
	}
	
	//cout << N << '\n';
	if(N == ANSWER)
	{
		cout << 0;
		return 0;
	}
	cout << bfs();
}