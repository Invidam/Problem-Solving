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

void myQuickSort(vector<int>& arr)
{
	if(arr.empty()) return;
	if(arr.size() == 1) return;
	
	int pivot = arr.front();
	arr.erase(arr.begin());
	
	vector<int> left;
	vector<int> right;
	
	for(int i=0;i<arr.size();++i)
	{
		if(arr[i] < pivot)
			left.push_back(arr[i]);
		else
			right.push_back(arr[i]);
	}
	
	myQuickSort(left);
	myQuickSort(right);
	
	arr.clear();
	
	arr.insert(arr.end(),left.begin(),left.end());
	arr.push_back(pivot);
	arr.insert(arr.end(),right.begin(),right.end());
	
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
	
	myQuickSort(arr);
	
	cout << "AFTER: ";
	print_vector(arr);
}