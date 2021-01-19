#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int N,K;
ll cnt,lo,hi,mid;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	lo =1;
	hi =N;
	while(lo <= hi)
	{
		mid = lo + hi >> 1;
		cnt = 0;
		if(2*mid-1 <= N)
			cnt = 2*mid*(2*mid-1)/2;
		else
			cnt =  N*N -(2*N - (2*mid-1))*(2*N - (2*mid-1) -1)/2;

		if(cnt >= K )
			hi = mid -1;
		else
			lo = mid + 1;
	}
	int B[200'001] = {0,};
	//cout <<"lo :" <<lo <<"idx :";
	int idx = 2*lo -1 <= N ? 4*lo -3 :   4*(N - lo)+3;
	
	for(int i=0;i<idx;i++)
	{
		if(2*lo -1 <= N)
		{
			if(i < idx/2)
				B[i] = (idx/2-i)*(i+1);
			else
				B[i] = (2*lo - i + idx/2-1)*(i -idx/2+1);
		}
		else
		{
			if(i < idx/2)
				B[i] = (N - i)*(2*lo - N + i);
			else
				B[i] = (2*lo- i)*(i-1);
		}
		//cout << "i :" << i << "val :" << B[i] << "v2 : "<<(2*lo   - i ) << "v3 :" << (i-1) <<'\n';
	}
	sort(B,B+idx,greater<int>());
	//sort(B,B+idx);
	//cout << cnt - K << '\n';
	cout << B[cnt-K];
	
}
// 	if(lo <= N)
// 		cnt = lo*(lo+1)/2;
// 	else
// 		cnt = (ll)N * N - ((2*N - lo)*(2*N -lo - 1))/2;
		
// 	cout << (((lo-(cnt-K))+1)/2) * ((lo+ (cnt-K))/2 +1);
// }