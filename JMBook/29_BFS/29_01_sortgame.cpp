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