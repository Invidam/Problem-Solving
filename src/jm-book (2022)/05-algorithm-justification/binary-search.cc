#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binsearch(vector<int> &arr, int num)
{
    int n = arr.size();
    int lo = 0, hi = n;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] <= num)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return lo - 1;
}
bool check(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        int resultIdx = binsearch(arr, num);
        bool isValid = (arr[resultIdx] == num);
        if (!isValid)
        {
            for (auto elem : arr)
                cout << elem << " ";
            auto itr = find(arr.begin(), arr.end(), num);
            auto valIdx = itr - arr.begin();
            cout << "\nresult idx: " << resultIdx << "\nnum idx: " << valIdx << "\nvalue: " << arr[resultIdx] << "\nis equal? " << (arr[resultIdx] == num) << "\n\n\n";
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> arr1 = {1, 5, 9, 13, 36, 64};
    vector<int> arr;
    for (int i = 0; i < arr1.size(); ++i)
    {
        arr.push_back(arr1[i]);
        check(arr);
    }
    cout << binsearch(arr1, 3);
    return 0;
}

/*

[1]

(1)
0 1  0
1 1  {0}

[1,2]

(1)
0 2 1
0 1 0
1 {0}

(2)
0 2 1
2 2 {1}


[1,2,3]
(1)
0 3 1
0 1 0
1 1 {0}

(2)
0 3 1
2 3 2
2 2 {1}

(3)

0 3 1
2 3 2
3 3 {2}
*/