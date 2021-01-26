//acmicpc.net/problem/

/*
문제명: 
TL: s
ML: MB



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

TU: m
TS: ms
MS: KB
*/

	cnt = 0;
	while(!temp.empty())
	{
		if((cnt == 0 )&&temp.top() == '+' ||temp.top() == '-')
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
		
		if(temp.top() == '(' || temp.top() == ')')
			cnt += temp.top() == '(' ? 1 : -1;
		else if(cnt == 0 && temp.top() == '+' ||temp.top() == '-')
			s_down.push(temp.top());
		else if(cnt == 0 && temp.top() == '*' || temp.top() == '/')
			s_up.push(temp.top());
		else 
			cout << temp.top();
		
		temp.pop();

	}