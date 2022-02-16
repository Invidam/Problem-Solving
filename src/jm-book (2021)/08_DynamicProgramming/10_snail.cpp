#include <iostream>
#include <cstring>
using namespace std;

int n,m,cache[1001][1001];
double cache2[1001][1001];
int pow(int base,int  n)
{
	int ret = 1;
	while(n--) ret *= base;
	
	return ret;
}
int climb(int day,int height)
{
	if(day == m) return (height >= n);
	
	int& ret = cache[day][height];
	if(ret != -1) return ret;
	
	return ret = climb(day+1,height+1) + climb(day+1,height+2);
}
double climb2(int day, int height)
{
	if(day == m) return (double)(height >= n);
	
	double& ret = cache2[day][height];
	if(ret != -1) return ret;
	
	return ret = 0.25 * climb2(day +1, height + 1) + 0.75* climb2(day+1,height + 2);
}
int main(void)
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
		cin >> n >> m;
		fill(&cache2[0][0],&cache2[1000][1000],-1);
		//memset(cache,-1,sizeof(cache));
		//double ans = (double)climb(0,0) / pow(2,m);
	//	memset(cache2,-1,sizeof(cache2));
		cout << climb2(0,0) << '\n';
	}

}