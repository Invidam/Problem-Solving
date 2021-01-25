#include <iostream>
#include <stack>
using namespace std;
//acmicpc.net/problem/10828

/*
문제명: 스택
TL: 0.5s
ML: 256MB



Good
1. 기본 문제이다.
2. 
3. 

Bad
1. 
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1s
TS: 4ms
MS: 2020KB
*/


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,num;
	cin >> N;
	stack<int> s;
	string str;
	while(N--)
	{
		cin >> str;
		
		if(str == "push")
		{
			cin >> num;
			s.push(num);
		}
		else if(str == "pop")
		{
			if(s.size() == 0)
				cout << "-1";
			else
			{
				cout <<s.top();
				s.pop();	
			}
		}
		else if(str == "size")
			cout <<s.size();
		else if(str == "empty")
			cout << s.empty();
		else if(str == "top")
		{
			if(s.size() == 0)
				cout << "-1";
			else
				cout <<s.top();
		}
		if(str != "push")
			cout <<'\n';
	}
}