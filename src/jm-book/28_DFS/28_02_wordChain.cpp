#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_ALPHABET = 26;
//algospot.com/judge/problem/read/

/*
문제명: WORDCHAIN
TL: 1s
ML: 64MB

TU: 3h
TS: 4ms
LEN: 1.8KB


Good
1. 내부 구현을 스스로 구현시킴. (isCircuit, isTrail 등)

Bad
1. 

IAN
1. trail, adj[b][a]를 연결시킴 -> 1. 있찌도 않은걸 pop함 , 2. (1 3 zz zb bc) 같은 경우 다시 zb->bc->cz(만들어냄) -> z b c z(pop) -> zb bc cz(존재x)를 출력함 

NEW
1. 


Q1: 
A1: 


Solution:

Approach: 

Clue:

Reconstruction : 
*/


vector<int> indegree,outdegree;
vector<vector<int>> adj;
vector<string> graph[MAX_ALPHABET][MAX_ALPHABET];
int circuitStart,circuitEnd;

void initiazing(int N,vector<string>& words)
{
	adj = vector<vector<int>>(MAX_ALPHABET,vector<int>(MAX_ALPHABET,0));
	indegree = outdegree = vector<int>(MAX_ALPHABET,0);
	
	for(int i=0;i<MAX_ALPHABET;++i)
		for(int j=0;j<MAX_ALPHABET;++j)
			graph[i][j].clear();
	
	
	for(int i=0;i<words.size();++i)	
	{
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() -1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		indegree[b]++;
		outdegree[a]++;
	}
}

void makeEulerianCircuit(int here,vector<int>& circuit)
{
	for(int there=0;there<adj[here].size();++there)
	{
		while(adj[here][there] > 0)
		{
			adj[here][there]--;
			
			makeEulerianCircuit(there,circuit);
		}
	}
	circuit.insert(circuit.begin(),here);
}

bool isCircuit()
{
	circuitStart = circuitEnd = -1;
	for(int i=0;i<MAX_ALPHABET;++i)
	{
		int delta = indegree[i] - outdegree[i];
		if(delta != 0 ) return false;
		if(outdegree[i] != 0 && circuitStart == -1) circuitStart = i;	
	}
	
	return true;
}
bool isTrail()
{
	circuitStart = circuitEnd = -1;
	
	for(int i=0;i<MAX_ALPHABET;++i)
	{
		int delta = indegree[i] - outdegree[i];
		if(delta == -1)
		{
			if(circuitStart == -1) circuitStart = i;
			else return false;
		}
		else if(delta == 1)
		{
			if(circuitEnd == -1) circuitEnd = i;
			else return false;	
		}
		else if(delta != 0)
			return false;
		
	}
	if(circuitStart > -1 && circuitEnd > -1) return true;
	else return false;
}

void print_words(vector<int>& circuit)
{
	int curr, next;
	for(int i=0;i<circuit.size()-1;++i)
	{
		curr = circuit[i];
		next = circuit[i+1];
		
		if(!graph[curr][next].empty())
		{
 			cout << graph[curr][next].back() <<' ';
			graph[curr][next].pop_back();
		}
	}
	cout << '\n';
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
		
		vector<string> words(N);
  
		for(int i=0;i<N;++i)
			cin >> words[i];
		
		initiazing(N,words);
		
		vector<int> circuit;
		
		if(isCircuit())
		{
			makeEulerianCir555cuit(circuitStart,circuit);
			
			if(circuit.size() == N + 1)
			{
				print_words(circuit);
				continue;
			}
		}
		else if(isTrail())
		{
			adj[circuitEnd][circuitStart]++;
			makeEulerianCircuit(circuitStart,circuit);
			
			circuit.pop_back();
			if(circuit.size() == N + 1)
			{
				print_words(circuit);
				continue;
			}
		}
		cout << "IMPOSSIBLE\n";
	}	
}

/*

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_ALPHABET = 26;

vector<int> indegree,outdegree;
vector<vector<int>> adj;
vector<string> graph[MAX_ALPHABET][MAX_ALPHABET];
int circuitStart,circuitEnd;

void makeGraph(vector<string>& words)
{
	adj = vector<vector<int>>(MAX_ALPHABET,vector<int>(MAX_ALPHABET,0));
	indegree = outdegree = vector<int>(MAX_ALPHABET,0);
	
	for(int i=0;i<MAX_ALPHABET;++i)
		for(int j=0;j<MAX_ALPHABET;++j)
			graph[i][j].clear();
	
	
	for(int i=0;i<words.size();++i)	
	{
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() -1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		indegree[b]++;
		outdegree[a]++;
	}
}

void getEulerianCircuit(int here,vector<int>& circuit)
{
	for(int there=0;there<adj[here].size();++there)
	{
		while(adj[here][there] > 0)
		{
			adj[here][there]--;
			
			getEulerianCircuit(there,circuit);
		}
	}
	circuit.insert(circuit.begin(),here);
}

vector<int> makePath()
{
	vector<int> circuit;
	int circuitStart;
	for(int i=0;i<MAX_ALPHABET;++i)
	{
		if(outdegree[i] == indegree[i] + 1)
		{
			getEulerianCircuit(i,circuit);
			return circuit;
		}
		else if(outdegree[i] != 0)
			circuitStart = i;
	}
	
	getEulerianCircuit(circuitStart,circuit);
	
	return circuit;
}
bool checkPath()
{
	int outOver =0, inOver = 0;
	for(int i=0;i<indegree.size();++i)
	{
		int delta = outdegree[i] - indegree[i];
		if(delta == 1 )
			outOver++;
		else if(delta == -1)
			inOver++;
		else if(delta * delta > 1)
			return false;
	}
	
	return (inOver * outOver <= 1);
}
string solve(vector<string>& words)
{
	makeGraph(words);
	
	if(!checkPath())
		return "IMPOSSIBLE";
		
	string ret;
	vector<int> circuit = makePath();
	
	if(circuit.size() != words.size() +1) 
		return "IMPOSSIBLE";
	int curr, next;
	for(int i=0;i<circuit.size()-1;++i)
	{
		curr = circuit[i];
		next = circuit[i+1];
		
		if(!graph[curr][next].empty())
		{
			if(i != 0) ret += " ";
 			ret+= graph[curr][next].back();
			graph[curr][next].pop_back();
		}
	}
	
	return ret;
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
		
		vector<string> words(N);
  
		for(int i=0;i<N;++i)
			cin >> words[i];
		
		cout << solve(words) << '\n';
	}	
}

*/

