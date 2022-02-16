#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef unsigned long long uint64;
const int PUZZLE_SIZE = 16;
const uint64 BLANK = 0ull;
int best;

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
	
	int estimate(const State& finish) const
	{
		int i = findPuzzleBlank(puzzle);
		int j = findPuzzleBlank(finish.puzzle);
		
		int xi,yi,xj,yj;
		
		xi = i % 4;
		yi = i / 4;
		xj = j % 4;
		yj = j / 4;
		
		return abs(xi - xj) + abs(yi - yj);
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
bool dfs(State here, const State& finish, int steps,stateMap& c)
{
	//if(c.count(here) != 0) return false;
	//c[here] = steps;
	//cout << findPuzzleBlank(here.puzzle) << '\n';
	if(steps >= best) return false;
	if(here == finish) 
	{
		best = steps;
		return true;
	}
	if(steps + here.estimate(finish) >= best) return false;
	vector<State> adj = here.getAdjacent();
	//cout << adj.size() << '\n';
	for(int i=0;i<adj.size();++i)
	{
		
		State& there = adj[i];
		if(c.count(there) == 0)
		{
			c[there] = steps;
			if(dfs(there,finish,steps + 1,c)) return true;;
		}
	}
	
	return false;
	
}

int ids(State start, State finish, int growStep)
{
	for(int limit = 15;; limit += growStep)
	{
		stateMap c;
		best = limit + 1;
		c[start] = 0;
		dfs(start,finish,0,c);
		//cout << "++\n";
		if(best <= limit) return best;
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
		
		//print_puzzle(startValue);
		int ans = ids(start,finish,1);	
		if(ans != -1) cout << ans << '\n';
		else cout << "IMPOSSIBLE\n";
	}

	
}