#include <iostream>
#include <utility>
#include <list>
using namespace std;
typedef pair<int, int> p;
//acmicpc.net/problem/2346

/*
문제명: 풍선 터뜨리기
TL: 2s
ML: 4MB



Good
1. -인 경우를 +로 치환하여 문제 해결하였다.
2. 
3. 

Bad
1. -인 경우 begin과 +인 경우 end는 의미가 다르다.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h
TS: 0ms
MS: 2148KB
*/
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,input_num,move = 0;
    
	cin >> N ;
	list<p> l;
	
	for(int i=0;i<N;i++) {
		cin >> input_num;
		l.push_back(p(i+1,input_num));
	}
	list<p>::iterator itr = l.begin();
	
	while(l.size() != 1)
	{
		while (move > 0)
		{
			if(itr == l.end())
				itr = l.begin();
			
			itr++;
			move--;
			
			if(itr == l.end())
				itr = l.begin();

		}
		cout <<(*itr).first<<" ";
		move = (*itr).second;
		itr = l.erase(itr);
        
		if(move > 0)
			move--;
		while(move < 0)
			move += l.size();
        
		if(itr == l.end())
			itr = l.begin();
	}
	cout << (*l.begin()).first;
	
}