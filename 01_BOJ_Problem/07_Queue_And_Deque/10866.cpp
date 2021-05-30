#include <iostream>
#include <deque>
using namespace std;
//acmicpc.net/problem/10866
/*
문제명: 덱
TL: 0.5s
ML: 256MB



Good
1. 
2. 
3. 

Bad
1. idx가 0일때부터 if문의 앞에 놓아야 한다. (왜냐하면 idx=5, 값이 입력되지 않았다면, 메모리주소에 남아있던 값(이전의 값)이 if문에 걸릴 수 있다.)
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: ?m
TS: 0ms
MS: 2020KB
*/
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	deque<int> dq;
	int N,X;
	cin >> N;
	while(N--)
	{
		string str;
		cin >> str;
		if(str[0] == 's')
		{
			cout << dq.size() << '\n';
		}
		else if(str[0] == 'e')
		{
			cout << dq.empty()<< '\n';
		}
		else if(str[5] == 'f')
		{
			cin >> X;
			dq.push_front(X);
		}
		else if( str[5] == 'b')
		{
			cin >> X;
			dq.push_back(X);
		}
		else
		{
			if(dq.empty())
			{
				cout << "-1\n";
				continue;	
			}
			else if(str[0] == 'p' && str[4] == 'f')
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else if(str[0] == 'p' &&  str[4] == 'b')
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else if(str[0] == 'f')
				cout << dq.front() << '\n';
			else
				cout << dq.back() << '\n';
		}
	}
	
	
}