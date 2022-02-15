#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N,TC;// rus[101],kor[101];
/*
int match()
{
	sort(rus,rus+N);
	sort(kor,kor+N);
	
	int i=0,ret = 0,j=0;
	
	while(i<N && j< N)
	{
		if(rus[i] <= kor[j])
		{
			i++;
			ret++;
			j++;
			continue;
		}
		j++;
	}
	
	return ret;
}
*/
int order(const vector<int>& russian , const vector<int>& korean)
{
	int n= russian.size(), wins =0;
	multiset<int> ratings(korean.begin(),korean.end());
	
	for(int rus=0;rus<n;++rus)
	{
		if(*ratings.rbegin() < russian[rus]) ratings.erase(ratings.begin());
		else
		{
			wins++;
			ratings.erase(ratings.lower_bound(russian[rus]));
		}
	}
	
	return wins;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		vector<int> russian(N),korean(N);
		for(int i=0;i<N;++i) cin >> russian[i];
		for(int i=0;i<N;++i) cin >> korean[i];
		
		cout << order(russian,korean) << '\n';
	}

}