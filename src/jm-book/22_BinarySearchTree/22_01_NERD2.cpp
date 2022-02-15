#include <iostream>
#include <map>
using namespace std;


bool isNerd(const pair<int, int>& cand,map<int,int>& m)
{
	map<int,int>::iterator itr = m.lower_bound(cand.first); // p가 큰 것들 중의 최소의 itr
	
	if(itr == m.end()) return 1;
	
	return (cand.second > itr->second);
}

void removeNonNerd(const pair<int, int>& newNerd, map<int,int>& m)
{
	map<int,int>::iterator itr = m.lower_bound(newNerd.first); // p가 큰 것들 중의 최소의 itr
	
	if(itr == m.begin()) return;
	
	--itr; 
	
	while(1)
	{
		if(itr->second > newNerd.second)
			return;
		
		if(itr == m.begin())
		{
			m.erase(itr);
			return;
		}
		
		map<int,int>::iterator newItr = itr;
		--newItr;
		m.erase(itr);
		itr = newItr;
	}
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
		map<int, int> nerdList;
		cin >> N;
		int a,b,cnt = 0;
		for(int i=0;i<N;++i)
		{
			cin >> a >> b;
			
			pair<int, int> p = make_pair(a,b);
			
			if(isNerd(p,nerdList))
			{
				removeNonNerd(p,nerdList);
				nerdList[a] = b;
			}
			
			cnt += nerdList.size();
		}
		cout << cnt << '\n';
	}
	
}