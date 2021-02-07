#include <iostream>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M,P,cnt = 0;
	
	int hate[100'001];// idx채널을 싫어하는 막내의 번째가 value
	int like[100'001];		  // idx번째가 좋아하는 채널이 value
	fill(hate,hate+100'000,-1);
	cin >> N >> M >> P;
	int channel = P;
	
	for(int i=0;i<N;i++)
	{
		int tmp;
		cin >> like[i];
		cin >> tmp;
		if(hate[tmp] == -1)
			hate[tmp] = i;
	}
	
	while(cnt != -1)
	{
		if(hate[channel] == -1)
			break;
		channel = like[hate[channel]];
		cnt++;
		if(channel == P)
			cnt = -1;
	}
	cout << cnt;
	
}
