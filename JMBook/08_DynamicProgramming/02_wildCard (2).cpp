#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string wildCard, fileName;
int N,TC,wn,fn,cache[101][101];

void print_vector(vector<string> &v)
{
	for(auto& elem : v) cout << elem << '\n';
}

bool match(int w, int f)
{
	if(w >= wn || f > fn) return (f == fn);
	int& ret = cache[w][f];
	if(ret != -1) return ret;
	char& wc = wildCard[w], fc = fileName[f];
	
	if(wc == fc || wc == '?') return ret = match(w+1,f+1);
	else if(wc == '*') return ret = (match(w,f+1) || match(w+1,f));
	else return ret = 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> TC;
	while(TC--)
	{
		cin >> wildCard;
		wn = wildCard.length();
		cin >> N;
		vector<string> lists;
		while(N--)
		{
			memset(cache,-1,sizeof(cache));
			cin >> fileName;
			fn = fileName.length();
			if(match(0,0)) lists.push_back(fileName);
		}
		sort(lists.begin(),lists.end());
	//	for(auto& elem : lists) cout << elem << '\n'; 
		print_vector(lists);
	}

}