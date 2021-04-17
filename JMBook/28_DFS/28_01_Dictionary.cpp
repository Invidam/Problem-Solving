#include <iostream>
#include <vector>
using namespace std;

const int MAX_ALPHABET = 26;

vector<string> words;
vector<bool> visited;
vector<vector<int>> adj;
vector<char> dictionanyOrder;

void initiazing(int N)
{
	visited = vector<bool>(MAX_ALPHABET,false);
	
	words.clear();
	words.resize(N);
	for(int i=0;i<N;++i)
		cin >> words[i];
	
	
	for(int i=0;i<adj.size();++i)
		adj[i].clear();
	
	adj.clear();
	adj.resize(MAX_ALPHABET);
	//adj = vector<vector<int>>(MAX_ALPHABET,(MAX_ALPHABET,0)); adj[26][26] = {{0,},}
	dictionanyOrder.clear();
	
}
void dfs(int here)
{
	
	visited[here] = true;
	for(int next=0;next<adj[here].size();++next)
	{
		int there = adj[here][next];
		
		if(!visited[there])
			dfs(there);
	}
	dictionanyOrder.insert(dictionanyOrder.begin(),here+'a');
}

void print_topoloy()
{
	for(int i=0;i<MAX_ALPHABET;++i)
		if(!visited[i] && !adj[i].empty()) dfs(i);
	
	for(int i=0;i<MAX_ALPHABET;++i)
		if(!visited[i]) dictionanyOrder.push_back(i + 'a');
	
	for(auto& elem: dictionanyOrder)
			cout << elem;

	cout << '\n';
	
}

bool makeOrder()
{
	for(int i=0;i<words.size()-1;++i)
	{
		int currLen = words[i].length(), nextLen = words[i+1].length();
		
		for(int j=0;j<currLen;++j)
		{
			if(j >= nextLen) return false;
			
			char currChar = words[i][j], nextChar = words[i+1][j];
			
			if(currChar == nextChar) continue;
			
			for(int k=0;k<adj[nextChar-'a'].size();++k)
				if(adj[nextChar-'a'][k] == (currChar - 'a')) return false;
			
			
			for(int k=0;k<adj[currChar-'a'].size();++k)
				if(adj[currChar-'a'][k] == (nextChar - 'a')) break;
			
			adj[currChar-'a'].push_back(nextChar - 'a');
			break;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N;
		initiazing(N);
		
		if(!makeOrder()) cout << "INVALID HYPOTHESIS\n";
		else print_topoloy();
	}
	
	
}