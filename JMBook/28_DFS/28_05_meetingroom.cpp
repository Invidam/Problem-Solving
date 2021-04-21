#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

vector<vector<int>> adj;
vector<p> meetings;
vector<int> sccId,discovered,st;
int sccCounter, vertexCounter;

void initializing(int N)
{
	meetings = vector<p>(2*N);
	adj = vector<vector<int>>(4*N,vector<int>(0));
	sccId = discovered = vector<int>(4*N,-1);
	sccCounter = vertexCounter = 0;
}

int scc(int here)
{
	int ret = discovered[here] = vertexCounter++;
	st.push_back(here);
	
	for(int i=0;i<adj[here].size();++i)
	{
		int there = adj[here][i];
		
		if(discovered[there] == -1)
			ret = min(ret,scc(there));
		
		else if(sccId[there] == -1)
			ret = min(ret,discovered[there]);
	}
	
	if(ret == discovered[here])
	{
		while(1)
		{
			int t = st.back();
			st.pop_back();
			sccId[t] = sccCounter;
			if(t == here) break;	
		}
		
		sccCounter++;
		
	}
	
	return ret;
}

vector<int> tarjanSCC()
{
	for(int i=0;i<adj.size();++i)
		if(discovered[i] == -1) scc(i);
	
	return sccId;
}

vector<int> solve2SAT()
{
	int n = adj.size() /2;
	
	vector<int> label = tarjanSCC();
	
	for(int i=0;i<2*n;i +=2)
		if(label[i] == label[i+1]) return vector<int>();
	
	vector<p> order(2*n);
	vector<int> ret(2*n,-1);
	
	for(int i=0;i<2*n;++i)
		order[i] = p(-label[i],i);
	
	sort(order.begin(),order.end());
	
	for(int i=0;i<2*n;++i)
	{
		int labelIdx = order[i].second, valueIdx = order[i].second / 2;
		bool isTrue = !(labelIdx % 2);
		
		if(ret[valueIdx] != -1) continue;
		
		ret[valueIdx] = !isTrue;
	}
	
	return ret;
	
}

bool disjoint(const p& a, const p& b)
{
	return (a.first >= b.second || a.second <= b.first);
}
void makeGraph()
{
	for(int i=0;i<meetings.size();i+=2)
	{
		int j = i + 1;
		adj[2*i].push_back(2*j+1);
		adj[2*j].push_back(2*i+1);
		adj[2*i+1].push_back(2*j);
		adj[2*j+1].push_back(2*i);
	}
	
	for(int i=0;i<meetings.size();++i)
	{
		for(int j=0;j<i;++j)
		{
			if(!disjoint(meetings[i],meetings[j]))
			{
				adj[2*i].push_back(2*j+1);
				adj[2*j].push_back(2*i+1);
			}
		}
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
		int N;
		cin >> N;
		initializing(N);
		
		int a,b;
		for(int i=0;i<2*N;++i)
		{
			cin >> a >> b;
			meetings[i] = p(a,b);
		}
		
		makeGraph();
		// for(int i=0;i<adj.size();++i)
		// {
		// 	for(int j=0;j<adj[i].size();++j)
		// 	{
		// 		cout << "i:"  << i << " j: " << j  <<" : "<< adj[i][j];
		// 	}
		// 	cout << '\n';
		// }
		vector<int> ret = solve2SAT();
		if(ret.empty())
		{
			cout << "IMPOSSIBLE\n";
			continue;	
		}
		
		cout << "POSSIBLE\n";
		for(int i=0;i<2*N;i +=2)
		{
			int idx = i;
			if(!ret[i])
				idx +=1;
			
			cout << meetings[idx].first <<" "<< meetings[idx].second << '\n';
		}
	  
	}
}


