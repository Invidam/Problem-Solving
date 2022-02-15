#include <iostream>
#include <stack>
using namespace std;
//acmicpc.net/problem/5076

/*
문제명: Web Pages
TL: 1s
ML: 128MB



Good
1. 문제가 예외경우가 꽤 있었고, 코드 양이 길었지만(본인이 길게 짠것이지만) 도움없이 스스로 해결하였다.
2. 
3. 

Bad
1. i가 아니라 j를 idx로 선언하였는데, 자꾸 i로 입력하여 오류가 있었다.
-> 흐름을 잘 생각하기. i안에서 일어나고 있다는 것을 인지하기.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW : 논리연산자 우선순위는 && > || 이다. 그냥 괄호로 내가 원하던 우선순위를 적는 것이 간편해보인다.
Difference(다른 분들과의 차이점): 본인은 기존 stack문제를 풀던 논리 그대로 적용하였는데, 다른 분들은 idx를 변경시키며 코드 양과 변수를 줄여 해결하였다.
본인의 코드가 길긴하지만, 스스로의 해결법을 지키며 풀었다는 점에서 굳이 바꿀 이유는 없는 것 같다.
keypoint: 

TU: 1h30m
TS: 0ms
MS: 2020KB
*/
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	stack<char> s;
	while(1)
	{
		getline(cin,str);
		if(str.size() == 1 && str[0] == '#')
			return 0;
		bool ans = true;
		bool flag_slash = false;
		bool flag_tag = false;
		for(int i=0;i<str.size();i++)
		{
			if((str[i] == '/')  && (i+1 != str.size() && str[i+1] == '>' || i != 0 && str[i-1] == '<')) //<br /> or </tag>일 때만 작동
				flag_slash = true;
			if(str[i] == '<')
				flag_tag = true;
			if(flag_tag)
				s.push(str[i]);
			if(str[i] == '>')
				flag_tag = false;
			
			if(flag_slash == true && str[i] == '>')
			{
				string str1 = "",str2 = "";
				int idx_slash,idx_str = 0;
				while(1)
				{
					str1.push_back(s.top());
					s.pop();
					if(str1[idx_str] == '/')
						idx_slash = idx_str;
					if(str1[idx_str] == '<')
						break;
					idx_str++;
				}
				flag_slash = false;
				if(idx_slash == 1 && str1[3] == 'r' && str1[4] == 'b')
					continue;
				else if(s.empty())
				{
					ans = false;
					i = str.size();
				}
				else
				{
					idx_str = 0;
					while(1)
					{
						str2.push_back(s.top());
						s.pop();
						if(str2[idx_str] == '<')
							break;
						idx_str++;
					}
					for(int j=1;(str1[idx_slash - j] != '>' || str2[str2.size()-j -1] != '>')&& ans == true;j++)
					{
						if(str1[idx_slash - j] != str2[str2.size() - j - 1])
						{
							ans = false;
							i = str.size();
						}
					}
				}
			}
		}
		if(ans == false || !s.empty())
			cout << "illegal\n";
		else
			cout <<"legal\n";
		while(!s.empty())
			s.pop();
	}
}