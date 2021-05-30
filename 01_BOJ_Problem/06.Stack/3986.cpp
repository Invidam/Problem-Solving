#include <iostream>
#include <stack>
using namespace std;
//acmicpc.net/problem/3986

/*
문제명: 좋은 단어
TL: 1s
ML: 256MB



Good
1. 
2. 
3. 

Bad
1. 오류를 범한 걸 인지했을 때, 범했던 오류를 제거한다.(인지하게 만든 부분 뿐만이 아닌 전체 코드과정에서)
2. 문제 이해를 잘 못하였다. -> 차분히 읽었으면 이해 못할 문제는 아니었다. "단어가 한줄에 하나씩", "쌍을 짓기"의 표현을 보았어야했다.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h
TS: 4ms
MS: 2388KB
*/
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans=0,N;
	string str;
	stack<char> s;
	
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> str;
		if(str.size()%2 == 1)
			continue;
		for(int j=0;str[j] != '\0';j++)
		{
			if((!s.empty()) && (str[j] == s.top()))
			{
				s.pop();
				continue;	
			}
			s.push(str[j]);
		}
		if(s.empty())
            ans++;
		
		while(!s.empty())
			s.pop();
	}
	cout << ans;
}