#include <iostream>
#include <vector>
using namespace std;


//n : 전체 원소수
//vector<int>& picked : 이미 선택된
//topick : 선택할 수있는 원소의 수

void printPicked(vector<int>& picked)
{
	for(auto& elem : picked)
	{
		cout << elem;
		
		if(elem != picked.back())
			cout << ", ";
	}
	cout << '\n';
	return;
}

void pick(int n,vector<int>& picked, int topick)
{
	if(topick == 0)
	{
		printPicked(picked);
		return;
	}
	
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	
	
	for(int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		pick(n,picked,topick -1);
		picked.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M;
	cin >> N >> M;
	vector<int> v;
	pick(N,v,M);
}