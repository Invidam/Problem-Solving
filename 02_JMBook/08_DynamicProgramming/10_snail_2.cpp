#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const double RAIN_PERCENT = 0.75;
double cache[1001][1001];
int N,M;

double climb(int curr,int day)
{
	if(curr >=N) return 1;
	if(day ==0) return curr >= N;
	
	double& ret = cache[curr][day];
	if(ret != -1) return ret;
	
	return ret = climb(curr+2,day-1)*(RAIN_PERCENT) + climb(curr+1,day-1)*(1-RAIN_PERCENT);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	
	cout.precision(10);
	int TC;
	cin >> TC;	
	
	while(TC--)
	{
		fill(&cache[0][0],&cache[1000][1000],-1);
		cin >> N >> M;
		
		cout << climb(0,M) << '\n';
	}
}