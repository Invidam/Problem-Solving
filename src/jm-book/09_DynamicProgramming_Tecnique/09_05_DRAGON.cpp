#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1e9 + 100;
const string CURVE = "-FX+YF+FX-YF";
/*
20ms
ERROR1: getCurveLength을 n에 대해서 해서 MAX case에 작동X.
ERROR2: char cache[MAX] 선언 -> 1*10^9 byte = 1GB = 메모리 초과.
*/
int cache[101];

int getCurveLength(int n)
{
	if(n==0) return 5;
	int& ret = cache[n];
	if(ret != -1) return ret;
	
	long long cand = 2*getCurveLength(n-1)+1;
	if(cand > MAX) return ret = MAX;
	
	return ret = cand;
}

char getCurveChar(int n,int idx)
{
	if(idx < CURVE.length()) return CURVE[idx];
  
	if(idx%3 != 0) 
		return CURVE[idx%6];
	if(getCurveLength(n-1) >= idx)
		return getCurveChar(n-1,idx);
	
	int divideValue = (getCurveLength(n-1)+1)/2;
	
	if(idx%divideValue == 0)
		return (idx/divideValue == 3) ? '-' : '+';
	
	return getCurveChar(n-1,idx%(2*divideValue));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	memset(cache,-1,sizeof(cache));
	
	while(TC--)
	{
		int N,P,L;
		cin >> N >> P >> L;
		
		for(int i=P;i<P+L;++i)
			cout << getCurveChar(N,i); 
		cout << '\n';
	}
}