#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1e9 + 1;
int cache[101][101];

int makeMorse(int n,int m)
{
	if(n*m == 0) return 1;
	int& ret = cache[n][m];
	if(ret != -1) return ret;
	
	ret = makeMorse(n-1,m) + makeMorse(n,m-1);
	if(ret > MAX) ret = MAX;
	return ret;
}

string getKth(int n,int m,int k)
{
	if(n*m == 0) return (n==0) ? string(m,'o') : string(n,'-');
	
	if(makeMorse(n-1,m) >= k) return "-" + getKth(n-1,m,k);
	else return "o" + getKth(n,m-1,k-makeMorse(n-1,m));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(cache,-1,sizeof(cache));
	
	int TC;
	cin >> TC;
	
	while(TC--)
	{
		int n,m,k;
		cin >> n >> m >> k;
		cout << getKth(n,m,k) << '\n';
	}
}