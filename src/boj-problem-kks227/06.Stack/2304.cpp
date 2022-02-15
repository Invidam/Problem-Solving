#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
//acmicpc.net/problem/2304

/*
문제명: 창고 사각형
TL: 2s
ML: 128MB



Good
1. 
2. 
3. 

Bad
1. arr안에 무엇이 들어있는지, first, second는 무슨 값인지 잘 인지하기.
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
MS: 2020KB
*/
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	p arr[1'001];
	int N,ans=0, max_h = 0,a,b,i,j;
	stack<int> s;
	cin >> N;
    
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		arr[i] = p(a,b);
		if(max_h < arr[i].second )
			max_h = arr[i].second;
	}
    
	sort(arr,arr+N);
	
	for(i=0;;i++)
	{
		if(s.empty() || arr[s.top()].second < arr[i].second)
			s.push(i);
		if(arr[i].second == max_h)
			break;
	}
	while(1)
	{
		int idx = s.top();
		s.pop();
		if(s.empty())
			break;
		else 
			ans += (arr[idx].first - arr[s.top()].first) * (arr[s.top()].second);
	}
	for(j=N-1;;j--)
	{
		if(s.empty() || arr[s.top()].second < arr[j].second)
			s.push(j);
		if(arr[j].second == max_h)
			 break;
	}
	while(1)
	{
		int idx = s.top();
		s.pop();
		if(s.empty())
			break;
		else 
            ans += (arr[s.top()].first - arr[idx].first ) * (arr[s.top()].second);
	}
    
	ans += (arr[j].first-arr[i].first+1) * max_h;
    
	cout << ans;
}