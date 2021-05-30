#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXSIZE = 10001, LISTSIZE = 5, DIFFICULTY[5] = {1,2,4,5,10}, INF = 987654321;
int cache[MAXSIZE];
string str;
int getDifficulty(int from, int len)
{
	if(from + len > str.length()) return INF;
	bool flag[LISTSIZE] = {true,true,true,true,true};
	int delta = str[from + 1] - str[from];
	char c1 = str[from],c2 =  str[from + 1];
	
	for(int idx = from; idx < from + len;++idx)
	{
		if(flag[0] && str[idx] != c1) flag[0] = false;
		if(flag[1] && idx != from &&(delta*delta != 1 ||str[idx] - str[idx-1] != delta)) flag[1] = false;
		if(flag[2] && idx != from && !(((c1 == str[idx-1] && c2 == str[idx]))|| (c1 == str[idx] && c2 == str[idx-1])) )flag[2] = false;
		if(flag[3] && idx != from && str[idx] - str[idx-1] != delta) flag[3] = false;
	}
//	cout << from << len << delta << flag[1] << '\n';
	for(int i=0;i<LISTSIZE;++i) if(flag[i]) return DIFFICULTY[i];
	
	return INF;
}
int getPiDifficulty(int idx)
{
	if(idx >=str.length()) return 0;
	
	int& ret = cache[idx];
	if(ret != -1) return ret;
	ret = INF;
	for(int next = 3; next <6; next++)
	{
		int dif = getDifficulty(idx,next);
	//	cout << idx << next << dif << '\n';
		ret = min(ret,getPiDifficulty(idx + next) + dif);
	}
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while(TC--)
	{
		memset(cache,-1,sizeof(cache));
		cin >> str;
		cout << getPiDifficulty(0) << '\n';
	}

}