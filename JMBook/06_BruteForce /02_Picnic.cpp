#include <iostream>
using namespace std;
bool areFriends[10][10];
int n,m;
int countParing(bool picked[10])
{
	int firstFree = -1;
	for(int i=0;i<n;i++)
	{
		if(picked[i] == false)
		{
			firstFree = i;
			break;
		}
	}
	if(firstFree == -1)
		return 1;
	
	int ret = 0;
	for(int next = firstFree +1; next<n;next++)
	{
		if(picked[next] == true || areFriends[firstFree][next] == false)
			continue;
		picked[next] = picked[firstFree] = true;
		ret += countParing(picked);
		picked[next] = picked[firstFree] = false;
	}
	return ret;
}
int main(int argc, char *argv[])
{
	int TC,a,b;
	cin >> TC;
	while(TC--)
	{
		cin >> n >> m;
		fill(&areFriends[0][0],&areFriends[9][9],false);
		for(int i =0; i <m;i++)
		{
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		bool picked[10] = {false,};
		cout << countParing(picked) << '\n';
	}
}