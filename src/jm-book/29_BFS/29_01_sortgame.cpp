
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
using namespace std;

const int MAX_N = 8;
map<vector<int>, int> dist;

vector<int> make_order(vector<pair<int,int>>& inp)
{
	int n = inp.size();
	vector<int> inputOrder(n);
	sort(inp.begin(),inp.end());
	
	for(int i=0;i<n;++i)
	{
		int idx = inp[i].second;
		inputOrder[idx] = i;
	}
	

	return inputOrder;
}

void precalc(int n)
{
	vector<int> sorted(n);
	for(int i=0;i<n;++i)
		sorted[i] = i;
	
	queue<vector<int>> q;
	dist[sorted] = 0;
	q.push(sorted);
	while(!q.empty())
	{
		vector<int> here = q.front();
		q.pop();	
		int cost = dist[here];
		
		for(int i=0;i<n;++i)
		{
			for(int j=i+2;j<=n;++j)
			{
				//[i,j)를 뒤집는다.
				//reverse(0,2) =  {3,4,1,2} -> {4,3,1,2}가 된다.
				reverse(here.begin() + i ,here.begin() + j);
				
				if(dist.count(here) == 0)
				{
					dist[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i ,here.begin() + j);
			}
		}
	}
}

void extend_vector(vector<int>& inputOrder)
{
	int n = inputOrder.size();
	while(inputOrder.size() != MAX_N)
	{
		inputOrder.push_back(n);
		++n;
	}
}

int findDistance(vector<int>& inputOrder)
{
	extend_vector(inputOrder);
	
	return dist[inputOrder];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	precalc(MAX_N);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		int N;
		cin >> N;
		
		vector<pair<int, int>> inp(N);
		for(int i=0;i<N;++i)
		{
			int num;
			cin >> num;
			inp[i] = make_pair(num,i);
		}

		vector<int> inputOrder = make_order(inp);
		
		cout << findDistance(inputOrder) << '\n';		
	}
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
using namespace std;

vector<int> make_order(vector<pair<int,int>>& inp)
{
	
	int n = inp.size();
	vector<int> inputOrder(n);
	sort(inp.begin(),inp.end());
	
	for(int i=0;i<n;++i)
	{
		int idx = inp[i].second;
		inputOrder[idx] = i;
	}
	
	return inputOrder;
}

int bfs(const vector<int>& inputOrder)
{
	int n = inputOrder.size();
	
	vector<int> sorted(n);
	for(int i=0;i<n;++i)
		sorted[i] = i;
	
	queue<vector<int>> q;
	map<vector<int>, int> distance;
	distance[inputOrder] = 0;
	q.push(inputOrder);
	
	while(!q.empty())
	{
		vector<int> here = q.front();
		q.pop();
		
		if(here == sorted)
			return distance[here];
		
		int cost = distance[here];
		
		for(int i=0;i<n;++i)
		{
			for(int j=i+2;j<=n;++j)
			{
				//[i,j)를 뒤집는다.
				//reverse(0,2) =  {3,4,1,2} -> {4,3,1,2}가 된다.
				reverse(here.begin() + i , here.begin() + j);
				if(distance.count(here) == 0)
				{
					distance[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i , here.begin() + j);
				
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
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		int N;
		cin >> N;
		vector<pair<int, int>> inp(N);
		for(int i=0;i<N;++i)
		{
			int num;
			cin >> num;
			inp[i] = make_pair(num,i);
		}

		vector<int> inputOrder = make_order(inp);

		cout << bfs(inputOrder) << '\n';
	}

}


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
using namespace std;
const int MAX_N = 8;
map<int, int> distanceArr[MAX_N+1];
vector<int> int_to_vec(int n)
{
	vector<int> ret;
	while(n != 0)
	{
		int elem = n % 10;
		ret.push_back(elem);
		n /= 10;
	}
	if(ret.size() != n) ret.push_back(0);
	reverse(ret.begin(),ret.end());
	
	return ret;
}
int vec_to_int(vector<int>& v)
{
	int n = v.size();
	reverse(v.begin(),v.end());
	int p = 1,ret = 0;
	for(int i=0;i<n;++i)
	{
		ret += p* v[i];
		p *= 10;
	}
	
	return ret;
}

int myReverse(int here, int i, int j)
{
	vector<int> ret = int_to_vec(here);
	reverse(ret.begin() + i ,ret.begin() + j);
	
	return vec_to_int(ret);
}
int make_order(vector<pair<int,int>>& inp)
{
	int n = inp.size();
	vector<int> inputOrder(n);
	sort(inp.begin(),inp.end());
	
	for(int i=0;i<n;++i)
	{
		int idx = inp[i].second;
		inputOrder[idx] = i;
	}
	int ret = vec_to_int(inputOrder);

	return ret;
}

void makeMap(int n)
{
	vector<int> _sorted(n);
	for(int i=0;i<n;++i)
		_sorted[i] = i;
	int sorted = vec_to_int(_sorted);
	
	queue<int> q;
	map<int, int>& distance = distanceArr[n];
	distance[sorted] = 0;
	q.push(sorted);
	while(!q.empty())
	{
		int here = q.front();
		q.pop();
		
		
		int cost = distance[here];
		for(int i=0;i<n;++i)
		{
			for(int j=i+2;j<=n;++j)
			{
				//[i,j)를 뒤집는다.
				//reverse(0,2) =  {3,4,1,2} -> {4,3,1,2}가 된다.
				int there = myReverse(here,i,j);
				if(distance.count(there) == 0)
				{
					distance[there] = cost + 1;
					q.push(there);
				}
			}
		}
	}
}

void precalc()
{
	for(int i=1;i<MAX_N+1;++i)
	{
		makeMap(i);	
	}
}

int findDistance(int inputOrder,int n)
{
	return distanceArr[n][inputOrder];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//precalc();
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		int N;
		cin >> N;
		
		makeMap(N);
		
		vector<pair<int, int>> inp(N);
		for(int i=0;i<N;++i)
		{
			int num;
			cin >> num;
			inp[i] = make_pair(num,i);
		}

		int inputOrder = make_order(inp);
		cout << inputOrder << '\n';
		return 0;
		cout << findDistance(inputOrder,N) << '\n';		
	}
}


*/