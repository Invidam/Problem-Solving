#include <iostream>
#include <stack>
using namespace std;
//acmicpc.net/problem/1935

/*
문제명: 후위 표기식2
TL: 2s
ML: 128MB



Good
1. 
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

TU: 25m
TS: 0ms
MS: 2020KB
*/

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int val[27];
	string str;
	stack<double> s;
	int N;
	double a,b;
	cin >> N;
	cin >> str;
	for(int i=0;i<N;i++)
		cin >> val[i];
	
	for(int i=0;i<str.size();i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			s.push((double)val[str[i] - 'A']);
		else
		{
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			if(str[i] == '*')
				s.push(a*b);
			else if(str[i] == '/')
				s.push(a/b);
			else if(str[i] == '+')
				s.push(a+b);
			else if(str[i] == '-')
				s.push(a-b);
			
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top(); 
}