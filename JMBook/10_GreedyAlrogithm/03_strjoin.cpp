#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef priority_queue<int,vector<int>,greater<int>> PQ;
int TC,N,tmp;
PQ pq;
int strJoin()
{
	int ret = 0,a,b,sum;
	while(!pq.empty())
	{
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum = a + b;
		ret += sum;
		if(pq.empty())
			return ret;
		pq.push(sum);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin  >> TC;
	while(TC--)
	{
		cin >> N;
		for(int i=0;i<N;i++)
		{
			cin >> tmp;
			pq.push(tmp);
		}
		cout << strJoin() << '\n';
	}
}