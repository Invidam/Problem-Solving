#include <iostream>
#include <list>
//acmicpc.net/problem/1021

/*
문제명: 회전하는 큐
TL: 2s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. list를 오랜만에 써봐서 기능들을 찾아보느라 시간이 좀 걸렸다.
2. 다른 풀이도 있어,보면 좋을 것 같다.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h
TS: 2ms
MS: 128KB
*/

int N,M,cnt;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	
	list<int> l;
	for(int i=1;i<=	N;i++)
		l.push_back(i);
	
	int num,temp,idx = 0;
	while(M--) {
		cin >> num;
		for(auto& elem : l) {	
			if(elem == num)
				break;
			idx++;
		}
		while(idx != 0)
		{
			if(idx <= l.size()/2) // 정방향
			{
				temp = l.front();
				l.pop_front();
				l.push_back(temp);
				cnt++;
				idx--;
			}
			else // 역방향
			{
				temp = l.back();
				l.pop_back();
				l.push_front(temp);
				cnt++;
				idx = (idx == l.size()-1) ? 0 : idx + 1;
			}
			  // for(auto& elem : l) { cout << elem << ',';}
			  // cout <<"idx :"<<idx << "cnt : "<< cnt<<'\n';
			// if(cnt > 20) break;
			
		}
		l.pop_front();
	}
	cout << cnt;
}