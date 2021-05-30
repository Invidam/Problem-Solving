#include <iostream>
#include <deque>
using namespace std;
//acmicpc.net/problem/5430

/*
문제명: AC
TL: 1s
ML: 256MB



Good
1. 
2. 
3. 

Bad
1. 아래 언급한 버그로 인해 시간이 지체되었는데, 해결하려하지않고 str2을 이용했으면 되었을 듯하다. (산을 만나면 돌아가자)
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
cin의 버그 여러 자료형을 같이 입력받을 경우 모두 입력받지 않고, 그전에 출력된다. cin.clear cin.ignore을 사용하여 해결가능하다.
(출처: https://m.blog.naver.com/PostView.nhn?blogId=ksowk87&logNo=150160483851&proxyReferer=https:%2F%2Fwww.google.com%2F)

keypoint: 

TU: 1h30m
TS: 69 ms
MS: 2652 KB
--

TS: 36 ms
MS: 3344KB
*/

/* 
[1,2,3,4]의 입력을
나누어 char, int을 이용해 받은 코드 

두가지 풀이의 차이 : 입력을 많이 받으니, (1)이 시간이 오래 걸린다.
int n char c vs string str2, (1)이 더 메모리사용이 적다.
#include <iostream>
#include <deque>
using namespace std;


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	deque<int> dq;
	int TC,N;
	cin >> TC;
	while(TC--)
	{
		string str;
		bool flag_err = false;
		bool is_forward = true;
		cin >> str;
		cin >> N;
		while(1)
		{
			char c;
			int n;
			cin >> c;
			
			if(c == '[' || c == ',')
			{
				cin >> n;
				if(n != 0)
				{
					dq.push_back(n);
					
					if(dq.size() > N)
						flag_err = true;
				}
				else // []일 때
				{
					cin.clear();
					cin.ignore();
					break;
				}
			}
			else if(c== ']')
				break;
		}
		
		
		if(flag_err == true || dq.size() != N)
		{
			cout<< "error\n";
			while(!dq.empty())
				dq.pop_front();
			continue;
		}
		for(int i=0;i<str.size();i++)
		{
			if(str[i] == 'R')
			{
				is_forward = !is_forward;
			}
			else //D
			{
				if(!dq.empty())
				{
					if(is_forward)
						dq.pop_front();
					else
						dq.pop_back();
				}
				else
				{
					flag_err = true;
					break;	
				}
			}
		}
		if(flag_err)
		{
			cout<<  "error\n";
			while(!dq.empty())
				dq.pop_front();
			continue;
		}
		
		cout <<"[";
		while(!dq.empty())
		{
			if(is_forward)
				cout << dq.front();
			else
				cout << dq.back();

			if(dq.size() != 1)
				cout << ",";

			if(is_forward)
				dq.pop_front();
			else
				dq.pop_back();
		}
		cout <<"]\n";	
		  
	}
}
*/
// str2를 이용해 받은 코드.
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	deque<int> dq;
	int TC,N;
	cin >> TC;
	while(TC--)
	{
		string str,str2;
		bool is_forward = true,flag_err = false;
		int input_num = 0;
		
		cin >> str >> N >> str2;
		for(int i=0;i<str2.size();i++)
		{
			while(str2[i] >= '0' && str2[i] <= '9')
			{
				input_num *= 10;
				input_num += (str2[i] - '0'); 
				i++;
			}
			if(input_num != 0)
				dq.push_back(input_num);
			input_num = 0;
		}
		if( dq.size() != N)
		{
			cout<< "error\n";
			while(!dq.empty())
				dq.pop_front();
			continue;
		}
		for(int i=0;i<str.size();i++)
		{
			if(str[i] == 'R')
			{
				is_forward = !is_forward;
			}
			else //D
			{
				if(!dq.empty())
				{
					if(is_forward)
						dq.pop_front();
					else
						dq.pop_back();
				}
				else
				{
					flag_err = true;
					break;	
				}
			}
		}
		if(flag_err)
		{
			cout<<  "error\n";
			while(!dq.empty())
				dq.pop_front();
			continue;
		}
		
		cout <<"[";
		while(!dq.empty())
		{
			if(is_forward)
				cout << dq.front();
			else
				cout << dq.back();

			if(dq.size() != 1)
				cout << ",";

			if(is_forward)
				dq.pop_front();
			else
				dq.pop_back();
		}
		cout <<"]\n";	
		  
	}
}
