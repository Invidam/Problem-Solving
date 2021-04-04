#include <iostream>
#include <list>

using namespace std;
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
		list<int> members;
		for(int i=0;i<N;i++)
			members.push_back(i+1);
		
		list<int>::iterator itr = members.begin();
		
		while(N > 2)
		{
			members.erase(itr++);
			N--;
			
			if(itr == members.end())
				itr = members.begin();
			
			for(int i=0;i<K-1;++i)
			{
				itr++;
				if(itr == members.end())
					itr = members.begin();
			}
		}
		cout << members.front()<< " " << members.back()<< '\n';
		
	}
}