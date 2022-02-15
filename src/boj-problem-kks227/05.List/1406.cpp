#include <iostream>
#include <list>
using namespace std;
//acmicpc.net/problem/1406

/*
문제명: 에디터
TL: 0.3s
ML: 512MB



Good
1. 
2. 
3. 

Bad
1. 구현을 하는데 어려움을 겪었다. 구현을 잘한다고 생각했었는데 그게 아니라, 구현이 쉬운 문제들을 풀어서 그렇게 생각이 된 것같다. 나는 구현을 못한다.
2. stack을 이용한 풀이도 존재한다.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW : itr을 이용한 insert , string변수에 문자열 입력받기. (string은 좀 더 알아보기.)
keypoint: 

TU: 1h30m
TS: ms
MS: KB
*/


char a,b;
string str;		
list<char> l;
int M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	for(auto ch : str)
		l.push_back(ch);
    
	list<char>::iterator itr = l.end();
	
	cin >> M;
	while(M--) {
		cin >> a;
		
		if(a == 'P')
		{
			cin >> b;
			itr = l.insert(itr,b);
			itr++;
		}
		else if(l.size() == 0);
		else if(a == 'L')
		{
			if(itr != l.begin())	
			   itr--;
		}
		else if(a == 'D')
		{
			if(itr != l.end())	
				itr++;
		}
		else if(a == 'B')
		{
			if(itr == l.begin())
				continue;
			itr--;
			itr = l.erase(itr);
		}
	}
	for(auto& elem : l)
		cout << elem;
}