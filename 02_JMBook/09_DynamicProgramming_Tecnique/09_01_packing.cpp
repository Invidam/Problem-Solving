#include <iostream>
#include <cstring>
using namespace std;
const int VOLUME = 0, IMPORTANCE = 1;
string lists[1001];
int cache[102][1002],arr[2][1001],N,W,maxPath[1001][1001];
//344ms
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




//20ms

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int VOLUME = 0, IMPORTANCE = 1;

string lists[1001];
int cache[102][1002],arr[2][1001],N,W;

int packing(int choosen,int capacity)
{
	if(choosen == N) return 0;
	int& ret = cache[choosen][capacity];
	if(ret != -1) return ret;
	
	ret = packing(choosen+1,capacity);
	
	if(capacity >= arr[VOLUME][choosen] )
		ret = max(ret,packing(choosen+1,capacity - arr[VOLUME][choosen]) + arr[IMPORTANCE][choosen]);
	
	return ret;
}

void reconstruct(int choosen,int capacity, vector<string>& picked)
{
	if(choosen == N) return; 
	
	if(packing(choosen,capacity) == packing(choosen+1,capacity))
		reconstruct(choosen+1,capacity,picked);
	else
	{
		picked.push_back(lists[choosen]);
		reconstruct(choosen+1,capacity- arr[VOLUME][choosen],picked);
	}
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
		vector<string> path;
		memset(cache,-1,sizeof(cache));
		
		cin >> N >> W;
		for(int i=0;i<N;++i)
			cin >> lists[i] >> arr[VOLUME][i] >> arr[IMPORTANCE][i];
		
		int ans = packing(0,W);
		reconstruct(0,W,path);
		
		cout << ans << ' ';
		cout << path.size() << '\n';
		
		for(auto& elem : path)
			cout << elem << '\n';
	}
}
