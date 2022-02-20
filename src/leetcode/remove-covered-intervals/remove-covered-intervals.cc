#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Problem site: https://leetcode.com/problems/remove-covered-intervals

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] != b[0] ? a[0] < b[0] : a[1] >= b[1];
}
bool isInner(vector<int> &a, vector<int> &b)
{
    return a[0] <= b[0] && b[1] <= a[1];
}
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        for (auto elem : intervals)
        {
            cout << elem[0] << "," << elem[1] << " ";
        }
        cout << "\n";
        sort(intervals.begin(), intervals.end(), cmp);

        for (auto elem : intervals)
            cout << elem[0] << "," << elem[1] << " ";
        cout << "\n";
        int topIdx = 0, ret = 1;

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (isInner(intervals[topIdx], intervals[i]))
            {
                continue;
            }
            else
            {
                ret++;
                topIdx = i;
            }
        }
        return ret;
    }
};
int main()
{
    vector<vector<int>> arr = {{1, 5}, {5, 8}, {2, 8}, {6, 7}};
    cout << Solution().removeCoveredIntervals(arr) << "\n";
    return 0;
}
