#include <iostream>
#include <vector>
using namespace std;


//n : 손가락 수
//vector<int>& picked : 이미 선택된

int N;

int recursivefinger(int n,vector<int>& picked)
{
	if(n == 1)
	{
		int tmp = N*(N+1)/2;
		
		for(auto& elem : picked)
		{
			cout << elem << ", ";
			tmp -= elem;
		}
		cout << tmp << '\n';
	}
	
	for(int i=1;i<N+1;i++)
	{
		bool esc_flag = false;
		for(auto& elem : picked)
		{
			if(i == elem)
				esc_flag = true;
		}
		
		if(esc_flag)
			continue;
		
		picked.push_back(i);
		recursivefinger(n-1,picked);
		picked.pop_back();
	}
		
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> v;
	cin >> N;
	recursivefinger(N,v);
}