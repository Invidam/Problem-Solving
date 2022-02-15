#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int BASE = 50;
vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	if(a.empty() || b.empty()) return vector<int>();
	vector<int> c(a.size()+ b.size() +1,0);
	
	for(int i=0;i<a.size();++i)
		for(int j=0;j<b.size();++j)
			c[i+j] += a[i] * b[j];
	
	//nomalize(c);
	return c;
}
/*
vector<int> str_to_vector(const string& str)
{
	vector<int> ret;
	int tmp;
	for(int i=0;i<str.size();++i)
	{
		if(str[i] == 'M')
			tmp = 1;
		else 
			tmp = 0;
		ret.insert(ret.begin(),tmp);
	}
	return ret;
}

vector<int> str_to_vector2(const string& str)
{
	vector<int> ret;
	int tmp;
	for(int i=0;i<str.size();++i)
	{
		if(str[i] == 'M')
			tmp = 1;
		else 
			tmp = 0;
		ret.push_back(tmp);
	}
	return ret;
}
*/
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int an = a.size();
	if(b.empty()) return;
	for(int i=0;i<b.size();++i)
	{
		if(an <= i + k)
		{
			a.insert(a.end(),b.begin()+i,b.end());
			break;
		}
		a[i+k] += b[i];
	}
	//nomalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b)
{
	for(int i=0; i<b.size();++i)
		a[i] -= b[i];
//	nomalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size(), bn = b.size();
	if(an < bn) return karatsuba(b,a);
	if(an*bn ==0) return vector<int>();
	if(an <= BASE) return multiply(a,b);
	
	int half = an/2;
	int bhalf = min<int>(half,bn);
	vector<int> a1(a.begin()+ half, a.end());
	vector<int> a0(a.begin(), a.begin()+ half);
	vector<int> b1(b.begin()+ bhalf, b.end());
	vector<int> b0(b.begin(), b.begin() + bhalf);
	vector<int> z0 = karatsuba(a0,b0);
	vector<int> z2 = karatsuba(a1,b1);
	addTo(a0,a1,0);
	addTo(b0,b1,0);
	vector<int> z1 = karatsuba(a0,b0);

	subFrom(z1 ,z0);
	subFrom(z1,z2);

	vector<int> ret;
	addTo(ret,z0,0);
	addTo(ret,z1,half);
	addTo(ret,z2,2*half);
	return ret;
}
/*
int hugs(const string& members, const string& fans)
{
	vector<int> as(members.size()), bs(fans.size());
	for(int i=0;i<members.size();i++) as[i] = (members[i] == 'M');
	for(int i=0;i<fans.size();i++) bs[fans.size() - i - 1] = (fans[i] == 'M');
	
	vector<int> ret = karatsuba(as,bs);

	int res = 0;
	for(int i=members.size() - 1; i < fans.size(); i++)
	{
		if(ret[i] == 0) res++;
	}
	return res;
}

int main()
{
	int C;
	scanf("%d ",&C);
	for(;C--;)
	{
		//char a[200001],b[200001];
		//gets(a);
		//gets(b);
		string a,b;
		cin >> a>> b;
		printf("%d\n",hugs(a,b));
	}
}
*/
int main(void)
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	while(TC--)
	{
	string str1, str2;
	cin >> str1 >> str2;
	int n1 = str1.size(), n2 = str2.size();
	
	vector<int> as(str1.size()), bs(str2.size());
	for(int i=0;i<str1.size();i++) as[i] = (str1[i] == 'M');
	for(int i=0;i<str2.size();i++) bs[str2.size() - i - 1] = (str2[i] == 'M');
	
//	vector<int> v1 = str_to_vector2(str1), v2 = str_to_vector(str2);
//	print_vector(v1);
//	print_vector(v2);
	vector<int> ans = karatsuba(as,bs);
//	print_vector(ans);
	int cnt = 0;
	for(int i=n1 -1; i < n2;++i)
	{
		if(i >= ans.size()) break;
		if (ans[i]== 0) cnt++;
	}
	cout << cnt << '\n';
	}

}