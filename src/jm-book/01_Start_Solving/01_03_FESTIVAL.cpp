#include <iostream>
#include <cstring>
using namespace std;

int N,L,arr[1001];
double avgMin;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(8);
	int TC;
	cin >> TC;
	while(TC--)
	{
		int sum = 0;
		cin >> N >> L;
		
		for(int i=0;i<N;++i)
		{
			cin >> arr[i];
			if(i < L) sum += arr[i];
		}
		
		int sumOfLth,sumOfBefore;
		double avg;
		for(int i=0;i<N;++i)
		{
			for(int j=L;i+j<=N;++j)
			{
				//cache[j] = i번째 부터 L+j번을 더한 값 즉 [i][0] ~ [i][L+j-1] 까지의 합
				if(j == L && i == 0)
				{
					sumOfLth = sum;
					avgMin = (double)sum / j;
				}
				else if(j == L)
				{
					sum = sumOfLth - arr[i-1] + arr[i+j-1];
					sumOfLth = sum;
				}
				else
				{
					sum = sumOfBefore + arr[i+j-1];
				}
				
				sumOfBefore = sum;
				avg  = (double)sum / j;
				avgMin = avgMin < avg ? avgMin : avg;
			}
		}
		cout << avgMin << '\n';
		
	}
}