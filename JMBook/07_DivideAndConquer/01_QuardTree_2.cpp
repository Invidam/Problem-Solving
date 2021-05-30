#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
Bad
1. 문자열의 앞부분은 활용가능성이 없고,
2. 함수를 재실행해야 하므로,
-> 재귀호출을 실행해가며 앞부분을 지워 함수 내부를 간결히 구성하자.
*/

string reverseTree(string::iterator& itr)
{
	char head = *itr;
	++itr;
	if(head != 'x')
		return string(1,head);
	
	string quard[4];
	
	for(int i=0;i<4;++i)
		quard[i] = reverseTree(itr);
	
	return "x" + quard[2] + quard[3] + quard[0] + quard[1];
}

/*
string makeQtree(string& tree)
{
	string ret;
	ret  = tree.substr(0,1);
	tree = tree.substr(1);
	if(ret[0] != 'x')
		return ret;
	
	string quardTree[4];
	
	for(int i=0;i<4;++i)
		quardTree[i] = makeQtree(tree);
	ret += quardTree[2] + quardTree[3] + quardTree[0]+ quardTree[1];
	
	return ret;
}

	
string reverseTree(string str)
{
	if(str[0] != 'x') return str;
	
	vector<string> quard(4,"");
	int idx = 1;
	for(int i=0;i<4;++i)
	{
		if(str[idx] != 'x')
			quard[i].push_back(str[idx++]);
		else
		{
			quard[i].push_back(str[idx++]);
			int cnt = 4;
			for(int j=0;j<cnt;++j)
			{
				if(str[idx] == 'x')
				{
					cnt +=4;
					
				}
				quard[i].push_back(str[idx++]);
			}
		}
		quard[i] = reverseTree(quard[i]);
	}
	return "x" + quard[2] + quard[3] + quard[0] + quard[1];
	
}
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		string str;
		cin >> str;
		string::iterator itr = str.begin();
		cout << reverseTree(itr) << '\n';
	}
}