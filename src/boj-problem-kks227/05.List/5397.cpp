#include <iostream>
#include <list>
using namespace std;
//acmicpc.net/problem/5397

/*
문제명: 키로거
TL: 1s
ML: 256MB



Good
1. 이전 문제와 유사하였는데, 이전 문제를 보지 않고도 구현을 잘해냈다. 즉 잘 이해하였다고 볼 수 있다.
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

NEW : End of string에 '$'을 둬서 푸는 방법도 있다고 한다. & stack을 이용한 풀이도 있다.
keypoint: 

TU: 10m
TS: 264ms
MS: 19380KB
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	
	cin >> TC;
	while(TC--)
	{
		list<char> l;
		list<char>::iterator itr = l.end();
		string str;
		
		cin >> str;
		
		for(int i=0;i<str.size();i++)
		{
			if(str[i] == '-')
			{
				if(itr != l.begin())
				{
					itr--;
					itr = l.erase(itr);
				}
			}
			else if(str[i] == '<')
			{
				if(itr != l.begin())
					itr--;
			}
			else if(str[i] == '>')
			{
				if(itr != l.end())
					itr++;
			}
			else
			{
				l.insert(itr,str[i]);
				//itr = l.insert(itr,str[i]);	
				//itr++;
			}
		}
		for(auto& elem : l)
			cout << elem;
		cout <<'\n';
	}
}