#include <iostream>
#include <vector>
using namespace std;


vector<bool> visited;
vector<vector<int>> adj;



void initiazing(int N)
{
	visited = vector<bool>(N,false);
	adj = vector<vector<int>>(N,vector<int>(N,0));
	
}

void makePath(int a,int b)
{
	adj[a][b]++;
	adj[b][a]++;
}

void makeEulerianCircuit(int here,vector<int>& circuit)
{
	for(int there=0;there < adj[here].size();++there)
	{
		while(adj[here][there])
		{
			adj[here][there]--;
			adj[there][here]--;
			
			makeEulerianCircuit(there,circuit);
		}
	}
	circuit.insert(circuit.begin(),here);
	//circuit.push_front(here);
}
bool getEulerianCircuit(int here,vector<int>& circuit)
{
	makeEulerianCircuit(here,circuit);
	
	if(circuit.back() == circuit.front()) return true;
	else return false;
}


bool getEulerianTrail(int from,int to, vector<int>& circuit)
{
	makePath(from,to);
	
	getEulerianCircuit(from,circuit);
	

	// 이 후 circuit에서, (from,to) 를 제거하여 시작점과 끝점이 같아야 참이다.
	int last = circuit.back();
	
	circuit.pop_back();
	
	if(last == from && circuit.back() == to)
		return true;
	else 
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N,K;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N >> K;
		initiazing(N);
		
		int a, b;
		
		for(int i=0;i<K;++i)	
		{
			cin >> a >> b;
			makePath(a,b);	
		}
		
		vector<int> circuit;
		
		//EulerianCircuit Example
		if(getEulerianCircuit(0,circuit)) cout << "T";
		else cout <<"F";
		//Input: 1 10 9 0 1 1 2 2 3 3 4 3 5 5 6 6 7 7 3 4 0
		
		
		// EulerianTrail Example
		// if(getEulerianTrail(0,4,circuit)) cout <<"T";
		// else cout << "F";
		
		//Input: 1 10 9 0 1 1 2 2 3 3 4 3 5 5 6 6 7 7 3 4 1 (F)	
		//Input: 1 10 8 0 1 1 2 2 3 3 4 3 5 5 6 6 7 7 3 (T) 	
		cout << '\n';
		
		for(auto& elem: circuit)
			cout << elem << ' ';
		cout << '\n';
	}
	
	
}