#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> discovered;
vector<int> childDiscovered;
vector<bool> isCutVertex;
vector<pair<int, int>> bridgeList;
vector<vector<int>> adj;

int cnt = 0;

void initializing(int N)
{
	discovered = vector<int>(N,-1);
	childDiscovered = vector<int>(N,987654321);
	isCutVertex =  vector<bool>(N,0);
	adj = vector<vector<int>>(N,vector<int>(0));
}

int findCutVertex(int here, bool isRoot)
{
	discovered[here] = cnt++;
	int ret = discovered[here],children = 0;
	
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		
		if(discovered[there] == -1)
		{
			children++;
			int subtree = findCutVertex(there,false);
			childDiscovered[here] = min(childDiscovered[here],subtree);
			//if(here == 1) cout << "st: " << subtree << "here: " << discovered[here] <<'\n';
			if(subtree >=discovered[here])
			{
				if(!isRoot)isCutVertex[here] = true;
				
				//there의 자식들과 연관된((자식->there->XX) 은 제외 왜냐면 else문에는 갱신을 안했으므로) 간선들 중 dis가 가장 높은게 here보다 높을 때, 다리가 된다. (같거나 작으면 더 상위나, here로 갈 수 있으므로 컴퍼넌트 분리가 안되며 즉 다리가 아니다.)
				if(childDiscovered[there] > discovered[here])
					bridgeList.push_back(pair(here,there));
			}
			ret = min(ret,subtree);	
		}
		else
			ret = min(ret,discovered[there]);
		
	}
	if(isRoot)
		isCutVertex[here] = (children >= 2);
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	initializing(N);
	
	while(1)
	{
		int u,v;
		cin >> u >> v;
		if(u == -1) break;
		if(u >= N || v >= N) break;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	findCutVertex(0,true);
	
	for(int i=0;i<isCutVertex.size();++i)
		if(isCutVertex[i]) cout << i << '\n';
	
	for(int i=0;i<bridgeList.size();++i)
		cout << bridgeList[i].first <<", "<< bridgeList[i].second << '\n';
}