#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef unsigned long long uint64;
const int VACUUM = 15, PUZZLE_SIZE = 16;
const uint64 BLANK = 0ull;

int sgn(int n) {if(!n) return 0; return n > 0 ? 1 : -1;}
int incr(int n) {if(n < 0) return n-1; return n+1;}

vector<int> getAdjacentIndex(int i)
{
	vector<int> adjacentIndex;
	
	if(i % 4 != 3) adjacentIndex.push_back(i+1);
	if(i % 4 != 0) adjacentIndex.push_back(i-1);
	if(i < 12) adjacentIndex.push_back(i+4);
	if(i > 3) adjacentIndex.push_back(i-4);
	
	return adjacentIndex;
	
}

int getValue(uint64 mask, int idx)
{
	return (mask >> (idx << 2)) & (PUZZLE_SIZE -1); 
}

int findPuzzleBlank(uint64 mask)
{
	for(int i=0;i<PUZZLE_SIZE;++i)
		if(getValue(mask,i) == BLANK) return i;
	
	return -1;
}

uint64 setValue(uint64 mask, int idx, uint64 value)
{
	return mask & ~(15ll << (idx << 2)) | (value << (idx << 2));
}

void putValue(uint64& mask, int idx, uint64 value)
{
	mask =  mask & ~(15ll << (idx << 2)) | (value << (idx << 2));
}

void print_puzzle(uint64 mask)
{
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			cout.width(2);
			cout << getValue(mask,4*i + j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

class State
{
	public:
	
	uint64 puzzle;
	
	State() {}
	State(const uint64& _puzzle) { puzzle = _puzzle;}
	
	
	vector<State> getAdjacent() const
	{
		int blankIndex = findPuzzleBlank(puzzle);
		vector<int> adjIndexList = getAdjacentIndex(blankIndex);

		int n = adjIndexList.size();
		vector<State> adj(n);

		for(int i=0;i<n;++i)
		{
			int j = adjIndexList[i];
			uint64& next = adj[i].puzzle;
			
			next = setValue(puzzle,blankIndex,getValue(puzzle,j));
			
			next = setValue(next,j,BLANK);
		}

		return adj;
	}

	bool operator < (const State& rhs) const
	{
		return puzzle < rhs.puzzle;
	}
	
	bool operator == (const State& rhs) const
	{
		return puzzle == rhs.puzzle;	
	}
	void print_state()
	{
		print_puzzle(puzzle);
	}
	
};
	

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
		vector<State> adj = here.getAdjacent();
		for(int i=0;i<adj.size();++i)
		{
			State there = adj[i];
			
			
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
	return -1;
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
		uint64 n;
		uint64 startValue = 0ull, finishValue= 0ull;

		for(int i=0;i<PUZZLE_SIZE;++i)
		{
			cin >> n;
			putValue(startValue,i,n);
			putValue(finishValue,i,i+1);
		}
		setValue(finishValue,PUZZLE_SIZE-1,BLANK);
		State start(startValue), finish(finishValue);

		int ans =bfs(start,finish);	
		if(ans != -1) cout << ans << '\n';
		else cout << "IMPOSSIBLE\n";
	}

	
}