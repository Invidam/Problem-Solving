#include <iostream>
#include <algorithm>
using namespace std;
//acmicpc.net/problem/1300

/*
문제명: K번째 수
TL: 2s
ML: 128MB



Good
1. 잘못된 방법이었지만 그대로 잘 진행해나갔다.
2. 
3. 

Bad
1. 구상이 안떠올랐다. 특정수가 몇번째 인지 or 특정 번째 수가 몇인지 를 알아내야 한다는 것을 알고있음에도 떠오르지 않았다.
-> 묘수를 찾으려 하지말고(대각선 방법), 기존 시간복잡도가 큰 문제에서 어떻게하여 줄일 것인지를 고민하자.
또한 떠오른 구상이 올바른지 확인하는 작업에 시간을 좀 더 투자해야 한다.
2. 
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2d
TS: 28ms
MS: 2016KB
*/

typedef long long ll;
int N,K;
ll cnt,lo,hi,mid;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	lo =1;
	hi =(ll)N*N;
	/*
	mid라는 수보다 작은 수가 몇개 있는지 구하자 = cnt.
	*/
	while(lo <= hi)
	{
		mid = lo + hi >> 1;
		ll cnt = 0;
		for(int i=1;i<=N;i++)
		{
			cnt += mid / i  >= N ? N : mid/i;
			if(cnt > K)
				break;
		}
		if(cnt >= K)
			hi = mid - 1;
		else
			lo = mid +1;
	}
	cout << lo;
}