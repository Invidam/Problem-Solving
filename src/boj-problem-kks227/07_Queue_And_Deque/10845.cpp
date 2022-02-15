#include <iostream>
#include <queue>
using namespace std;
//acmicpc.net/problem/10845

/*
문제명: 큐
TL: 0.5s
ML: 256MB



Good
1. 큐의 기본문제이다.
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

TU: 10m
TS: 0ms
MS: 2020KB
*/

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	queue<int> q;
	cin >> N;
	while(N--)
	{
		string str;
		cin >> str;
		if(str[1] == 'u') // push
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if(str[0] == 's') // size
			cout << q.size() << '\n';
		else if(str[0] == 'e') //empty
			cout << q.empty() << '\n';
		else//pop front back
		{
			if(q.empty())
			{
				cout << "-1\n";
				continue;
			}
			else if(str[2] == 'p') //pop
			{
				cout << q.front();
				q.pop();
			}
			else if(str[0] == 'f') // front
				cout << q.front();
			else
				cout << q.back();
			cout <<'\n';
		}
		
	}
	
}