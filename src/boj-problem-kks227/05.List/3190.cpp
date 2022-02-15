#include <iostream>
#include <list>
#include <utility>
using namespace std;
//acmicpc.net/problem/3190

/*
문제명: 뱀
TL: 1s
ML: 128MB



Good
1. 구현을 잘 했다. (1학년 때 풀어본 문제와 비슷하였는데 그걸 잘 기억 및 응용하였다.)
2. 
3. 

Bad
1. movement_idx 설정에서, 정확히 양수부분인 1~4만 움직이도록 설계했어야 했다. <- 오류의 원인이 되었다.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h30m
TS: 0ms
MS: 2028KB
*/

typedef pair<int, int> p;
bool arr[101][101];
int movement_list[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int movement_idx = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,K,L,r,c,X, cnt = 0;
	char C;
	int movement[2] = {0,1};
	cin >> N;
	cin >> K;
	
	while(K--)
	{
		cin >> r >> c;
		arr[r-1][c-1] = true;
	}
	
	cin >> L;
	cin >> X >> C;
	L--;
	list<p> snake;
	snake.push_back(p(0,0));
	
	while(1)
	{
		cnt++;
		if(cnt == X+1)
		{
			if(C == 'L')
				movement_idx++;
			else
				movement_idx--;
			while(movement_idx < 0)
				movement_idx +=4;
			
			movement_idx %=4;
			
			if(L-- > 0 )
				cin >> X >> C;
		}
		snake.push_back(p(snake.back().first + movement_list[movement_idx][0], snake.back().second + movement_list[movement_idx][1]));
		
		if(snake.back().first < 0 || snake.back().first >= N || snake.back().second < 0 || snake.back().second >= N)
		{
			cout << cnt;
			return 0;
		}
		for(list<p>::iterator itr = snake.begin(); itr != (snake.end()); itr++)
		{
			itr++;
			if(itr == snake.end())
				break;
			itr--;
			if(itr->first == snake.back().first && itr->second == snake.back().second)
			{
				cout << cnt;
				return 0;
			}
		}
			
		if(arr[snake.back().first][snake.back().second] == true)
			arr[snake.back().first][snake.back().second] = false;
		else
		{
			snake.pop_front();
		}
	}
	
}