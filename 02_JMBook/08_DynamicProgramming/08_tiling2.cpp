#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const ll  REST = 1000000007;
ll cache[101];

ll getCase(int n)
{
	if(n <= 1) return 1;
	ll& ret = cache[n];
	
	if(ret != -1) return ret;
	
	ret = getCase(n-1) + getCase(n-2);
	ret %= REST;
	return ret;
	
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N;
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		memset(cache,-1,sizeof(cache));
		cout << getCase(N) << '\n';
	}

}