#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int TOWER_SIZE = 4,INF = 987654321;
int N;
int sgn(int n) {if(!n) return 0; return n > 0 ? 1 : -1;}
int incr(int n) {if(n < 0) return n-1; return n+1;}


int getValue(int mask, int idx)
{
	return (mask >> (idx * 2)) & (3); 
}

int setValue(int mask, int idx, int value)
{
	return mask & ~(3 << (idx * 2)) | (value << (idx * 2));
}

void putValue(int& mask, int idx, int value)
{
	mask =  mask & ~(3 << (idx * 2)) | (value << (idx * 2));
}

void print_tower(int& mask)
{
	vector<vector<int>> top(4,vector<int>());
	
	for(int i=0;i<N;++i)
	{
		int idx = getValue(mask,i);
		top[idx].push_back(i);
	}
	
	for(int i=0;i<TOWER_SIZE;++i)
	{
		cout << i << ": ";
		for(auto& elem: top[i]) cout << elem <<' ';
		cout << '\n';
	}
	cout << '\n';
}

class State
{
	public:
	
	int tower;
	int top[4] = {INF,INF,INF,INF};
	
	State() {}
	State(const int& _tower) { tower = _tower;}


	bool operator < (const State& rhs) const
	{
		return tower < rhs.tower;
	}
	
	bool operator == (const State& rhs) const
	{
		return tower == rhs.tower;	
	}
	

	
};

void make_top(int& tower, vector<int>& top)
{
	for(int i=0;i<N;++i)
	{
		int idx = getValue(tower,i);
		top[idx] = min(top[idx],i);
	}
}	

typedef map<State, int> stateMap;
int bfs(State start, State finish)
{
	if(start == finish) return 0;
	
	stateMap c;
	queue<State> q;
	c[start] = 1;
	c[finish] = -1;
	q.push(start);
	q.push(finish);
	
	while(!q.empty())
	{
		State here = q.front();
		q.pop();
		int cost = c[here];
		vector<int> top(4,INF);
		
		make_top(here.tower, top);
		
		for(int i=0;i<TOWER_SIZE;++i)
		{
			if(top[i] == INF) continue;
			
			for(int j=0;j<TOWER_SIZE;++j)
			{
				if(i == j) continue;
				if(top[i]  > top[j]) continue;
				//top[i]에 있었던 원판의 위치가 있는 인덱스
				int IndexToMove = top[i];
				int ElemToMove = j;
				
				State there;
				int& next = there.tower;
				next = here.tower;
				next = setValue(next,IndexToMove,ElemToMove);
				
				if(c.count(there) != 0)
				{
					if(sgn(c[there]) != sgn(cost))
						return abs(c[there]) + abs(cost) -1;
					continue;
				}

				c[there] = incr(cost);
				q.push(there);
			}

			
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC, K;
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		int n;
		int startValue = 0, finishValue= 0;
		
		for(int i=0;i<TOWER_SIZE;++i)
		{
			cin >> K;
			for(int j=0;j<K;++j)
			{
				cin >> n;
				n--;
				//n번째 크기인 원판은 i번째 기둥에 있어야 한다.
				// arr[n] = i 이어야 한다.
				
				putValue(startValue,n,i);
				
			}
		}
		for(int i=0;i<TOWER_SIZE;++i)
		{
			cin >> K;
			for(int j=0;j<K;++j)
			{
				cin >> n;
				n--;
				//n번째 크기인 원판은 i번째 기둥에 있어야 한다.
				// arr[n] = i 이어야 한다.
				
				putValue(finishValue,n,i);
				
			}
		}
		State start(startValue), finish(finishValue);

		int ans = bfs(start,finish);	
		if(ans != -1) cout << ans << '\n';
		else cout << "IMPOSSIBLE\n";
	}
}