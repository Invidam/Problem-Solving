#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vector(vector<int>& arr)
{
	cout <<"[";
	for(auto& elem: arr)
		cout << elem << " ";
	cout << "]\n";
}

void myMergeSort(vector<int>& arr)
{
	if(arr.size() == 1) return;
	int n = arr.size();
	int half = n/2;
	vector<int> left(arr.begin(), arr.begin() + half);
	myMergeSort(left);
	vector<int> right(arr.begin() + half,arr.end());
	myMergeSort(right);
	arr.clear();
	
	while(!left.empty() || !right.empty())
	{
		if(!left.empty() &&(right.empty() ||left.front() < right.front()))
		{
			arr.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			arr.push_back(right.front());
			right.erase(right.begin());
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> arr(N);
	
	for(int i=0;i<N;++i)
		cin >> arr[i];
	
	cout << "BEFORE: ";
	print_vector(arr);
	
	myMergeSort(arr);
	
	cout << "AFTER: ";
	print_vector(arr);
}