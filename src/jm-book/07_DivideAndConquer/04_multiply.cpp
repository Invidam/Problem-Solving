#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<int> int_to_vector(int n)
{
	vector<int> ret;
	while(n > 0)
	{
		ret.push_back(n%10);
		n /= 10;
	}
	return ret;
}void print_vector_reverse(vector<int>& arr)
{
	cout <<"[";
	for(vector<int>::reverse_iterator itr = arr.rbegin(); itr != arr.rend();++itr)
		cout << *itr << ' ';
	cout << "]\n";
}
void print_vector(vector<int>& arr)
{
	cout <<".[";
	for(auto& elem: arr)
		cout << elem << " ";
	cout << "]<--\n";
}
void nomalize(vector<int>& num)
{
	num.push_back(0);
	
	for(int i=0;i+1<num.size();++i)
	{
		if(num[i] < 0)
		{
			int borrow = abs(num[i]) + 9;
			borrow /= 10;
			num[i+1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			num[i+1] += num[i]/ 10;
			num[i] %= 10;
		}
	}
	
	while(num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(vector<int>& a, vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1,0);
	
	for(int i=0;i<a.size();++i)
		for(int j=0;j<b.size();++j)
			c[i+j] += a[i]*b[j];
	
	nomalize(c);
	
	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num1, num2;
	cin >> num1 >> num2;
	vector<int> a,b;
	
	a = int_to_vector(num1);
	b = int_to_vector(num2);
	
	vector<int> c = multiply(a,b);
	print_vector_reverse(c);
}