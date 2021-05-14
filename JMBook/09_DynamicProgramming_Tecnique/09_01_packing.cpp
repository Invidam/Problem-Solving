#include <iostream>
#include <cstring>
using namespace std;
const int VOLUME = 0, IMPORTANCE = 1;
string lists[1001];
int cache[102][1002],arr[2][1001],N,W,maxPath[1001][1001];

int packing(int choosen,int remainVolume)
{
	int& ret = cache[choosen+1][remainVolume];
	if(ret != -1) return ret;
	
	ret = 0;
	int bestNext = -1;
	
	for(int next = choosen +1; next < N; ++next)
	{
		if(remainVolume < arr[VOLUME][next]) continue;
		
		int cand = arr[IMPORTANCE][next] + packing(next,remainVolume - arr[VOLUME][next]);
		if(ret < cand)
		{
			bestNext = next;
			ret = cand;
		}
	}
	maxPath[choosen+1][remainVolume] = bestNext;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		int W;
		cin >> N >> W;
		memset(cache,-1,sizeof(cache));
		memset(maxPath,-1,sizeof(maxPath));
		
		for(int i=0;i<N;++i)
			cin >> lists[i] >> arr[VOLUME][i] >> arr[IMPORTANCE][i];
		int ans = packing(-1,W);
		cout << ans << ' ';
		
		int itr = maxPath[0][W],size = 0;
		while(itr != -1)
		{
			//lists에 최대경로의 size번째를 갱신.
			lists[size++] = lists[itr];
			
			W -= arr[VOLUME][itr];
			itr = maxPath[itr+1][W];
		}
		
		cout << size << '\n';
		for(int i=0;i<size;++i)
			cout << lists[i] << '\n';
		
	}
}