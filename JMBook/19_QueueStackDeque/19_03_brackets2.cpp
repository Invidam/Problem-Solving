#include <iostream>
#include <stack>
using namespace std;
//algospot.com/judge/problem/read/

/*
문제명: BRACKETS2
TL: 0.1s
ML: 64MB

TU: 50m
TS: 20ms
LEN: 1.0KB


Good
1. 저번보다 간단히 구현함(재귀 형식으로)
2. 에러 찾기를 잘함

Bad
1. 예외 케이스를 잘 몹솼음 ([[[[ 경우)
2. 출력 재대로 안봄.

IAN
1. 예외 케이스를 잘 몹솼음 ([[[[ 경우)
2. 출력 재대로 안봄.

NEW
1. string을 vector처럼 사용하기 ( push front 기능)


Q1: 
A1: 


Solution: stack을 이용함.

Approach: 넣은애를 바로 빼야하는 상황.

Clue:넣은애를 바로 빼야하는 상황.

Reconstruction : 
*/



bool isBelong(char c, string s)
{
	for(auto& elem : s)
		if(elem == c) return 1;
	
	return 0;
}
bool isPair(string& str)
{
	if(str.empty()) return 1;
	if(str.size()%2 == 1) return 0;
	string inside;
	stack<char> express;
	
	for(int i=0;i<str.length();++i)
	{
		if(isBelong(str[i],")}]"))
		{
			char bracketType = str[i];
			if(bracketType == ')') bracketType = '(';
			if(bracketType == ']') bracketType = '[';
			if(bracketType == '}') bracketType = '{';
			while(!express.empty() && express.top() != bracketType)
			{
				
				inside.insert(0,1,express.top());
				express.pop();	
			}
			if(express.empty()) return 0;
			if(!isPair(inside)) return 0;
			express.pop();
		}
		else 
			express.push(str[i]);
	}
	
	return express.empty();
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
		string str;
		cin >> str;
		int ans = isPair(str);
		if(ans) 
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
}