#include <iostream>
#include <stack>
using namespace std;

//acmicpc.net/problem/1918
/*
문제명: 후위 표기식
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

TU: 1d
TS: 0ms
MS: 2024KB
*/
/*
풀이법 및 고찰
1. if문 ()에 대해 공부하기
2. 문제에서 주어진 설명이 잇으면 그 설명대로 예시를 풀거나 문제해결하기 위해 노력하기.
(여러가지 답이 존재하는 경우, 문제에서 설명한 경우만 '정답'으로 인정되므로 그러한 방법으로 풀기 위함이다. 또한 여러 답이 잇어도 모든 경우에 하나의 답으로 귀결되는 방법이 정답인 방법이다.)
3. 시간날 때, "명시된 풀이법"으로도 풀어보기. (같은 원리이지만, 구현법이 최소화되어있다.)

나의 해결법
1. 괄호 안을 전부 해결하는 코드
2. 괄호 밖 마지막 하나를 해결하는 코드

2가지가 존재한다.
두개는 결과만 다를 뿐(push or 출력) 과정은 동일하다.

1은 괄호안을 {}로 만들어 문자취급시킨다.
ex) (a+b) -> {ab+}

2는 괄호밖인 A*B+C/D 꼴인 문자열을 해결하여 출력한다.


문자열 해결원리(괄호는 없다는 가정하에 왜냐하면 {}로 전부 처리시켰으므로)
{
	 문자와 사칙연산을 s에 저장한다.


	 ) -> (으로 역순으로 가는 동안
	 temp에 s를 넣는다.

	 temp를 비우는 동안(정순)
	 +-를 만나면 전부 s로 pop
	 * or /을 만나면 *or /만 s로 pop한다.

	 s (문자
	 up (* or / 
	 down (+-
	 로 저장시킨다.

	 temp를 다비웠을 때,
	 * or /   +=t순으로 s로 pop한다. (남아있을수도 있으므로)
}


'{}' 인식 처리 및 방법:
{
	 {}를 만날경우, {}의 안쪽에 사칙연산이든 뭐든 전부 push시킨다. 이는 {}전부를 하나의 문자취급한다는 것과 같다.
 {	}의 안쪽임은 {이 나오면 + }이 나오면 -를 하여 0이 아닌경우가 안쪽이다. ({ 만나왔을 경우 즉 + 이므로 0이아니고 안이다.)
}


1에서는 s로 push하며
s를 다시 temp에 저장하고(역순으로 만들고 즉 바닥에 Z가 앞에 A가 있게한다.)
2에서는 temp를 읽으며 저장이 아닌 출력시킨다. (A-Z로 출력된다)

*/
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<char> s; //출력용
	stack<char> temp; //임시
	stack<char> s_down; //+- 저장
	stack<char> s_up; // */ 저장
	string str;
	int cnt = 0;
	bool flag = false;
	cin >> str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i] != ')')
		{
			s.push(str[i]);
			continue;
		}
		//else :
		while(s.top() != '(') // (이 나올때 까지
		{
			temp.push(s.top());
			s.pop();	
		}
		s.pop();
		s.push('{');
		cnt = 0;
		while(!temp.empty())
		{
			if((cnt == 0 )&&(temp.top() == '+' || temp.top() == '-'))
			{
				while(!s_up.empty())
				{
					s.push(s_up.top());
					s_up.pop();
				}
				while(!s_down.empty())
				{
					s.push(s_down.top());
					s_down.pop();
				}
			}
			else if((cnt ==0) && (temp.top() == '*' || temp.top() == '/'))
			{
				while(!s_up.empty())
				{
					s.push(s_up.top());
					s_up.pop();
				}
			}
			
			if(temp.top() == '{' || temp.top() == '}')
			{
				cnt += temp.top() == '{' ? 1 : -1;
				s.push(temp.top());
			}
			else if((cnt == 0 )&& (temp.top() == '+' ||temp.top() == '-'))
				s_down.push(temp.top());
			else if((cnt == 0 )&& (temp.top() == '*' || temp.top() == '/'))
				s_up.push(temp.top());
			else 
				s.push(temp.top());
			
			temp.pop();
			
		}
		while(!s_up.empty())
		{
			s.push(s_up.top());
			s_up.pop();
		}
		while(!s_down.empty())
		{
			s.push(s_down.top());
			s_down.pop();
		}
		s.push('}');
	}
	while(!s.empty()) //s에 c-b+a가 들어가 있다. s에 a*(bc+)가 들어가있다.
	{
		temp.push(s.top());
		s.pop();
	}
	cnt = 0;
	while(!temp.empty())
	{
		if((cnt == 0 )&&(temp.top() == '+' ||temp.top() == '-'))
		{
			while(!s_up.empty())
			{
				cout << s_up.top();
				s_up.pop();
			}
			while(!s_down.empty())
			{
				cout << s_down.top();
				s_down.pop();
			}
		}
		else if((cnt ==0) && (temp.top() == '*' || temp.top() == '/'))
		{
			while(!s_up.empty())
			{
				cout << s_up.top();
				s_up.pop();
			}
		}
		
		if(temp.top() == '{' || temp.top() == '}')
			cnt += temp.top() == '{' ? 1 : -1;
		else if((cnt == 0 )&& (temp.top() == '+' ||temp.top() == '-'))
			s_down.push(temp.top());
		else if((cnt == 0 )&& (temp.top() == '*' || temp.top() == '/'))
			s_up.push(temp.top());
		else 
			cout << temp.top();
		
		temp.pop();

	}
	while(!s_up.empty())
	{
		cout << s_up.top();
		s_up.pop();
	}
	while(!s_down.empty())
	{
		cout << s_down.top();
		s_down.pop();
	}
}