#include <iostream>
#include <algorithm>
using namespace std;

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
		int arr[N];
		int child[3] = {0,0,0};
		for(int i=0;i<N;++i)
			cin >> arr[i];
		
		sort(arr,arr+N,greater<int>());
		
		for(int i=0;i<N;++i)
		{
			sort(child,child+3);
			child[0] += arr[i];
		}
		
		sort(child,child+3);
		cout << child[0] << ' ' << child[1] << ' ' << child[2] << '\n';
		
	}
}