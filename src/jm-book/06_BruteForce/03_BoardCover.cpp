#include <iostream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
//algospot.com/judge/problem/read/BOARDCOVER

/*
문제명: BOARDCOVER
TL: 2s
ML: 64MB

-jm-
TU 30m
TS 0ms
LEN: 1.5kb
-my-
TU: 1h
TS: 4ms
LEN: 1.4KB


Good
1. set 사용으로 O(WH) -> O(log(WH))로 감소 (검색, 삭제, 추가 시)


Bad
1. 

IAN
1. insert, erase 햇갈림.

NEW
1. 

#복습해야할 것
1. set, map + 이에 대한 cmp함수.

Q1: 
A1: 


Solution: white를 저장해 놓은 뒤, L자에 해당하는 글자들을 지우고 다시 자신을 호출 후 L자를 추가시켰다.

Approach: 
보글 문제처럼 판을 이용한 재귀함수였다.

Clue: 
변수의 범위가 작았고, bfs에서 풀었던 것들이랑 비슷해 보였다.


Reconstruction : 
*/
int offset[4][3][2] =
{
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool setBoard(vector<vector<int> >& board,int y, int x , int coverType, int delta)
{
	bool ok = true;
	for(int i=0;i<3;i++)
	{
		int yoff = y + offset[coverType][i][0];	
		int xoff = x + offset[coverType][i][1];
		
		if(yoff <0 || yoff >= board.size() || xoff < 0 || xoff >= board[0].size())
			ok = false;
		else if((board[yoff][xoff] += delta) > 1) // 검은 색이거나 이미 덮여있는 경우
			ok = false;
	}
	return ok;

}

int coverWhite(vector<vector<int> >& board)
{
	int ret = 0,y= -1, x = -1;
	
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[i].size();j++)
		{
			if(board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1)
			break;
	}
	
	if(y == -1) // 기저사례: 흰색을 찾지못함
		return 1;
	
	for(int coverType = 0; coverType<4; ++coverType)
	{
		if(setBoard(board,y,x,coverType,1)) // 추가
			ret += coverWhite(board);
		setBoard(board,y,x,coverType,-1); // 다시 제거한다.
	}
	
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,H,W;
	cin >> TC;
	
	while(TC--)
	{
		cin >> H >> W;
		
		char c;
		vector<vector<int> > board(H,vector<int>(W));
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				cin >> c;
				
				if(c == '.')
					board[i][j] = 0;
				else
					board[i][j] = 1;
			}
		}
		cout << coverWhite(board) << '\n';
	}
}

/*
typedef pair<int, int> p;
int TC,H,W;
struct cmp {
    bool operator() (const p& a, const p& b) const {
		if(a.second == b.second)
     	   return a.first < b.first;
		return a.second < b.second;
    }
};

int offset[4][2][2] =
{
	{{0,1},{1,0}},
	{{1,0},{0,1}},
	{{1,0},{-1,1}},
	{{0,1},{-1,0}}
};


int coverWhite(set<p,cmp>& whiteList)
{
	if(whiteList.size() == 0)
		return 1;
	else if(whiteList.size() < 3)
		return 0;
	
	int ret = 0;
	auto itr_front = whiteList.begin();//set<p>::iterator
	auto p_front = *itr_front;
	itr_front = whiteList.erase(itr_front);
	for(int i=0;i<4;i++)
	{
		int xoff = p_front.first + offset[i][0][0]; 
		int yoff = p_front.second + offset[i][0][1];
		p L_first = p(xoff,yoff);
		auto next = whiteList.find(L_first);
		if(next == whiteList.end())
			continue;
		next = whiteList.erase(next);
		
		xoff += offset[i][1][0]; 
		yoff += offset[i][1][1];
		
		p L_second = p(xoff,yoff);
		next = whiteList.find(L_second);
		if(next == whiteList.end())
		{
			whiteList.insert(L_first);
			continue;
		}
		whiteList.erase(L_second);
		
		ret += coverWhite(whiteList);
		whiteList.insert(L_first);
		whiteList.insert(L_second);
	}
	whiteList.insert(p_front);
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
		cin >> H >> W;
		
		char c;
		set<p,cmp> whiteList;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				cin >> c;
				
				if(c == '.')
				{
					//cout << "j : " << j << "i: " << i <<'\n';
					whiteList.insert(p(j,i));
				}
			}
		}
		
		cout << coverWhite(whiteList) << '\n';
	}
}
*/