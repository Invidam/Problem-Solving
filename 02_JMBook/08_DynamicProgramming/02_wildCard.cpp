#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

string W,S;
int cache[101][101];

bool wildCard(int w, int s)
{
	int& ret = cache[w][s];
	
	if(ret != -1) return ret;
	
	while(w < W.size() && s < S.size() && (W[w] == S[s] || W[w] == '?'))
	{
		w++; 
		s++;
	}
	
	if(w == W.size()) return ret = (s == S.size());
	if(W[w] == '*')
	{
		for(int step = 0; s + step <= S.size();++s)
		{
			if(wildCard(w+1,s+step)) return ret = 1;
		}
	}
	return ret = 0;
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
		vector<string> list;
		cin >> W;
		cin >> N;
		for(int i=0;i<N;++i)
		{
			cin >> S;
			list.push_back(S);
		}
		sort(list.begin(),list.end());
		for(int i=0;i<N;++i)
		{
			memset(cache,-1,sizeof(cache));
			S = list[i].substr(0);
			if(wildCard(0,0)) cout << S << '\n';
		}
	}
}