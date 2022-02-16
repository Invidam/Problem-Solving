#include <iostream>
#include <cstring>
using namespace std;
double cache[101][101];

int n,d,P,TC,t,town;
bool junction[101][101];
int hasRoad[101];

double getPos(int num,int day)
{
	if(day ==0) return (num == P);
	double& ret =cache[num][day];
	if(ret != -1.0) return ret;
	ret = 0;
	for(int bef = 0; bef<n;++bef)
	{
		if(!junction[num][bef]) continue;
		
		ret += getPos(bef,day -1) / (double)hasRoad[bef];
	}
	
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(8);
	cin >> TC;
	while(TC--)
	{
		cin >> n >> d >> P;
		fill_n(cache[0],101*101,-1.0);
		memset(hasRoad,0,sizeof(hasRoad));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				cin >> junction[i][j];
				if(junction[i][j]) hasRoad[i]++;
			}
		}
		
		cin >> t;
		while(t--)
		{
			cin >> town;
			cout << getPos(town,d) << ' ';
		}
		cout << '\n';
	}

}