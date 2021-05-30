#include <iostream>
using namespace std;

string makeQtree(string& tree)
{
	string ret;
	ret  = tree.substr(0,1);
	tree = tree.substr(1);
	if(ret[0] != 'x')
		return ret;


	
	string quardTree[4];
	
	for(int i=0;i<4;++i)
	{
		quardTree[i] = makeQtree(tree);
	}
	/*
	for(int i=0;i<4;++i)
	{
		cout << quardTree[i] <<'\n';
	}
	*/
	ret += quardTree[2] + quardTree[3] + quardTree[0]+ quardTree[1];
	
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
		string tree;
		cin >> tree;
		
		cout << makeQtree(tree) << '\n';
	}

}