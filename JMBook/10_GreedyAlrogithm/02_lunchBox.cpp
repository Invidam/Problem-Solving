#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
p arr[10001];
int N,TC;

bool cmp(const p& a, const p& b)
{
	if(a.first == b.first) return a.second > b.second;
	return a.first >  b.first;
}
int getTime()
{
	int ret =0,usedTime =0;
	for(int i=0;i<N;++i)
	{
		int& eatingTime = arr[i].first, microwavingTime = arr[i].second;
		
		usedTime += microwavingTime;
		ret = max(ret,usedTime + eatingTime);
	}
	
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		for(int i=0;i<N;++i)cin >> arr[i].second;
		for(int i=0;i<N;++i)cin >> arr[i].first;
		sort(arr,arr+N,cmp);
		cout << getTime() << '\n';
	}

}