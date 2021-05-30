#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
string digitList;

int append(int here, int edge)
{
	int there = 10*here + edge;
	if(there >= N) return N + there%N;
	return there % N;
}

string getMinGift()
{
	int here;
	string ret;
	queue<int> q;
	vector<int> parents(2*N,-1);
	vector<char> choices(2*N);
	
	parents[0] = 0;
	
	q.push(0);
	
	while(!q.empty())
	{
		here = q.front();
		q.pop();
		
		for(int i=0;i<digitList.length();++i)
		{
			int there = append(here,digitList[i] - '0');
			if(parents[there] != -1) continue;
			
			q.push(there);
			parents[there] = here;
			choices[there] = digitList[i];
		}
	}
	
	here = N + M;
	if(parents[here] == -1) return "IMPOSSIBLE\n";
	
	while(parents[here] != here)
	{
		ret.push_back(choices[here]);
		here = parents[here];
	}
	
	reverse(ret.begin(),ret.end());
	ret.push_back('\n');
	return ret;
	
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
		
		cin >> digitList;
		sort(digitList.begin(),digitList.end());
		
		cin  >> N >> M;
		
		cout << getMinGift();
	}
}
