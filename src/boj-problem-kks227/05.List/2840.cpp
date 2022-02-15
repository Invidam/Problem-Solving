#include <iostream>
#include <list>
using namespace std;
//acmicpc.net/problem/2840

/*
문제명: 행운의 바퀴
TL: 1s
ML: 128MB



Good
1. 코드를 짧고 시간도 오래 걸리지 않게 짰다. (예외 처리를 시간복잡도를 적게 쓰는 방향으로 잘하였다.)
하지만, N이 얼마없어 굳이 그렇게 짜 이유는 없었던 것 같다.
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

NEW :#include <cstring> memset(시작 주소, 채워 넣을 값, 한 값의 크기 ) 
memset이 for문보다 빠르니 이걸 사용하자. 그 이유는 어셈블리어수준에서 동작이 다르기(memset이 더 빠르게 되게끔) 때문이라고 한다.
keypoint: 

TU: 55m
TS: 0ms
MS: 2016KB
*/



int arr[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,K,num,sum = 0;
	char c;
	list<char> l;
	cin >> N >> K;
	
	for(int i=0;i<N;i++)
	{
		l.push_back('?');
	}
	
	list<char>::iterator itr = l.begin();
	while(K--)
	{
		cin >> num >> c;
		sum+= num;
		for(int i=0;i<num;i++)
		{
			if(itr == l.end())
				itr = l.begin();
			itr++;
			if(itr == l.end())
				itr = l.begin();
		}
		if(((*itr) != '?' && (*itr) != c )  || (arr[c-65] != 0 && (sum - arr[c-65])%N != 0))
		{
			//?가 아닌 다른 문자에 또 다른 문자가 들어올 때
			//이미 들어온 문자가 들어왔는데 
			cout <<"!";
			return 0;
		}
		(*itr) = c;
		arr[c-65] = sum;
	}
	
	while(N--)
	{
		cout << (*itr);
		if(itr == l.begin())
			itr = l.end(); 
		itr--;
	}
}