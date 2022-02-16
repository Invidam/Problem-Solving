#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*
기존 코드 2번은 오류가 있음.
fileName[f]가 빈공간을 가르키고 있어 치명적이라는 오류.
*/
int cache[101][101];
vector<string> wordList;
string fileName,wordName;

bool isMatch(int fileIdx,int wordIdx)
{
	if(fileIdx == fileName.length()) return wordIdx == wordName.length();
	else if(wordIdx >= wordName.length())
	{
		while(fileIdx != fileName.length())
			if(fileName[fileIdx++] != '*') return false;
		
		return true;
	}
	
	int& ret = cache[fileIdx][wordIdx];
	if(ret != -1) return ret;
	
	char fileChar = fileName[fileIdx], wordChar = wordName[wordIdx];
	
	if(fileChar == wordChar || fileChar == '?' ) return ret = isMatch(fileIdx +1, wordIdx +1);
	else if(fileChar == '*') return ret = isMatch(fileIdx +1, wordIdx) || isMatch(fileIdx,wordIdx +1);
	else return ret = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		cin >> fileName;
		int N;
		cin >> N;
		
		wordList.resize(N);
		
		for(int i=0;i<N;++i) cin >> wordList[i];
		sort(wordList.begin(),wordList.end());
		
		for(int i=0;i<N;++i)
		{
			memset(cache,-1,sizeof(cache));
			wordName = wordList[i];
			
			if(isMatch(0,0)) cout << wordName << '\n';
		}
	}
}