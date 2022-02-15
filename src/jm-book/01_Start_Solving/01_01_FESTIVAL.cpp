#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC,N,L,teams, arr[1001], dp[1001];
	double min_avg,tmp;
	cin >> TC;
	
	while(TC--)
	{
		cin >> N >> L;
		
		fill(dp,dp+1001,0);
		teams = L;
		min_avg = 1000001;
	  
		for(int i=0;i<N;i++)
		{
			cin >> arr[i];
		}
		
		
		while(1)
		{
			for(int i=0;i<=N-teams;i++)
			{
				if(teams == L)
					for(int j=0;j<teams;j++)
						dp[i] += arr[i+j];
				else
					dp[i] += arr[i+teams -1];
			  
				tmp = (double)dp[i]/teams;
			  
				if(min_avg > tmp)
					min_avg = tmp;
			}
		  
			teams++;
			if(teams > N)
				break;
		}
		cout << fixed;
		cout.precision(8);
		
		cout << min_avg << '\n';
	}
}