#include <iostream>
#include <vector>
using namespace std;
//fill 과 {0,} 차이점 알아보기

//acmicpc.net/problem/9466

/*
문제명: 텀 프로젝트
TL: 3s
ML: 256MB



Good
1. 고쳐야할 점이 많이 나오지만, 그래도 구현력 구상력등은 꾸준히 느는 것 같음. 또한, 반례찾거나 만들거나 시간초과 등 오류 찾는 능력이 많이 발전한 듯.
2. 
3. 

Bad
1. 굳이 기존 Graph를 변형하여 해결할 필요는 없었다. 즉, dfs를 구현할 때 n개의 간선을 가진 graph를 이용할 필요는 굳이 없다.(1개의 간선일수도 있고[이 경우는 배열로 구현가능] 아예 그래프와 관련이 없을 수도 있다.).
2. 문제의 n이 주어지면, 시간복잡도가 어떠한 경우에 안되는지(n*n이면 안되는군 nlogn이면 되는군)을 미리 파악하고, 이에 맞게 코딩을 하기. (짜면서 생각하는건 너무 어려울 것 같음.)
3. 

conceipt: 
solution: 
Q1: 
A1: 

NEW :
keypoint: 

TU: 2h10m
TS: 648ms
MS: 3644KB
*/


class Graph{
public:
	int N;
	vector<int> adj;
	vector<bool> visited;
	bool cycle[100'001] = {false,};
	bool cantcycle[100'001] = {false,};
	
	//생성자
	Graph(): N(0) {}
	Graph(int n) : N(n) {
		adj.resize(N);
		visited.resize(N);
	}
	
	void addEdge(int u,int v){ //u->v
		adj[u] = v;
	}

	int dfsAll(){
		
		int ans = 0;
		
		fill(visited.begin(),visited.end(),false);
		for(int i=0;i<N;i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		
		for(int i=0;i<N;i++)
			if(cantcycle[i]) ans++;
		
		return ans;
	}
	
private:
	
	void dfs(int curr){
		/*
		if(cycle[curr] || cantcycle[curr])
			return false; // '<-이미 추가되었거나 이미 안된느걸 아는 경우'는 이미 visited로 걸러짐.
		else */
		if(adj[curr] == curr) // 자시자신을 선택한 경우이며 이미 추가는 안된경우
		{
			visited[curr] = true;
			//cout << "self cycle \n";
			cycle[curr] = true;
			return;
		}
		
		vector<int> stack;
		stack.push_back(curr);
		//cout << "\nstart ->";
		//cout << curr <<" -> ";
		for(int i=1;i<N+1;i++)
		{
			visited[stack.back()] = true;
			stack.push_back(adj[stack.back()]);
			//cout << stack.back() <<" -> ";
			if(stack.back() == stack.front())
			{
				while(!stack.empty())
				{
					cycle[stack.back()] = true;
					stack.pop_back();
				}
				return;
			}
			
			//012345
			//123450
			//0123450
			
			if(cycle[stack.back()] || cantcycle[stack.back()])
			{
				stack.pop_back();
				while(!stack.empty())
				{
					cantcycle[stack.back()] = true;
					stack.pop_back();
				}
				return;
			}
			if(visited[stack.back()] == true)
			{
				int temp = stack.back();
				cycle[temp] = true;
				stack.pop_back(); // 두번째 temp가 stack에 들어있으므로 제거한다.
				while(stack.back() != temp)
				{
					cycle[stack.back()] = true;
					stack.pop_back();
				}
				stack.pop_back();//첫번재 temp가 들어있으므로 제거한다.
				
				while(!stack.empty())
				{
					cantcycle[stack.back()] = true;	
					stack.pop_back();
				}
				return;
			}
			/*
			for(int j=i-1;j>=0;j--) // n명째에 cycle이 생길경우 nn+1/2가 되서 시간초과. 따라서 bool arr[num] = {false,} 였다가 본인 등장하면 true로 바꾸고 이미 true인게 있으면 빼는걸로하기 빼는건 어차피 n번임.
			{
				//cout <<"\n\n== "<<j<< "==\n\n";
				//0~ j-1   | j~ i
				//012		345
				//123		454
				//cantcycle
				//			can cycle
				//j = 3 size = 4 j < size일때 
				if(stack[j] == stack.back())
				{
					//cout <<"\n\n=**= "<<j<< "=**=\n\n";
					while(!stack.empty())
					{
						if(j < stack.size())
							cycle[stack.back()] = true;
						else
							cantcycle[stack.back()] = true;	
						
						stack.pop_back();
					}
					
					return;// 하나의 사이클을 찾았으므로 true 리턴.
				}
			}
			*/
			
		}
		//cout <<" err";
		return;
	}
};



int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		int n,input_num;
		cin >> n;
		//0~ n-1까지 수들에 대해 graph 생성
		Graph G(n);
		for(int i=0;i<n;i++) // i -> (inp-1)을 선택하는 것
		{
			cin >> input_num;
			G.addEdge(i,input_num-1);
			/*
			if(i == input_num -1)
				cycle[i] = true;
			*/
		}
		int ans = G.dfsAll();
		cout << ans << '\n';
		
	}
}

/*
문제에 따라 가지고있던 그래프를 변형시켜 해결한 경우. 
#include <iostream>
#include <vector>
using namespace std;

bool cycle[100'001] = {false,};
bool cantcycle[100'001] = {false,};
bool visited[100'001] = {false,};
int adj[100'001] = {0,};

void dfs(int curr,int N)
{
	
	if(adj[curr] == curr)
	{
		visited[curr] = true;
		cycle[curr] = true;
		return;
	}

	vector<int> stack;
	stack.push_back(curr);
	for(int i=1;i<N+1;i++)
	{
		visited[stack.back()] = true;
		stack.push_back(adj[stack.back()]);
		//cout << stack.back() <<" -> ";
		if(stack.back() == stack.front())
		{
			while(!stack.empty())
			{
				cycle[stack.back()] = true;
				stack.pop_back();
			}
			return;
		}
		if(cycle[stack.back()] || cantcycle[stack.back()])
		{
			stack.pop_back();
			while(!stack.empty())
			{
				cantcycle[stack.back()] = true;
				stack.pop_back();
			}
			return;
		}
		if(visited[stack.back()] == true)
		{
			int temp = stack.back();
			cycle[temp] = true;
			stack.pop_back();
			while(stack.back() != temp)
			{
				cycle[stack.back()] = true;
				stack.pop_back();
			}
			stack.pop_back();

			while(!stack.empty())
			{
				cantcycle[stack.back()] = true;	
				stack.pop_back();
			}
			return;
		}
	}
	return;
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
		int n,input_num,ans = 0;
		cin >> n;
		
		fill(cycle,cycle + n+1,false);
		fill(cantcycle,cantcycle + n+1,false);
		fill(visited,visited + n+1,false);
		fill(adj,adj + n+1,0);
		
		for(int i=0;i<n;i++) 
		{
			cin >> input_num;
			adj[i] = input_num-1;
			
		}
		for(int i=0;i<n;i++)
			if(!visited[i]) dfs(i,n);
		
		for(int i=0;i<n;i++)
			if(cantcycle[i]) ans++;
		
		cout << ans << '\n';
	}
}
	
	
	

*/