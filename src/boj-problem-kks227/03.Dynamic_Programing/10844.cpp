#include <iostream>
using namespace std;//acmicpc.net/problem/10844

/*
1037~1216
10844
1
256
문제명: 쉬운 계단수
TL: 1s
ML: 256MB



Good
1. 구상이 떠올랐을 때, 바로 구현을 잘했다.
2. 수의 시간 복잡도를 생각해 구상이 올바른지 점검하하였다.
3. 수의 크기를 생각해 ll을 사용하였다.

Bad
1. 구상에 있어 시간이 오래 소요되었다. (떠오르긴 했으나, 기존 dp문제와 형식이 다르다고 생각해 다른 방법을 찾아보았다.) -> 떠오른 구상의 시간,공간복잡도+문제 해결 여부를 고려해보고 가능하면 바로 그 구상으로 해결한다.
2. ll이 아니라 int로 ret,temp를 선언하여 오류가 발생했다.
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 1h40m
TS: 0ms
MS: 2016KB
*/

typedef unsigned long long ll;
const ll rest = 1000000000;
ll arr[10] = {0,1,1,1,1,1,1,1,1,1};
ll dp[10] = {0,1,1,1,1,1,1,1,1,1};

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);		
	int N;
	ll ret = 0;
	cin >> N;
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<10;j++)
		{
			ll temp = 0;
			if(j-1 >= 0)
				temp += arr[j-1]%rest;
			if(j+1 <= 9)
				temp += arr[j+1]%rest;
			dp[j] = temp % rest;
		}
		for(int j=0;j<10;j++)
			arr[j] = dp[j]%rest;
	}
	for(int i=0;i<10;i++)
		ret += dp[i], cout <<"i :" <<i << "dp :" << dp[i] << '\n';
	cout << ret%rest;
}

