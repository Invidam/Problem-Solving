#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/arithmetic-slices
int cache[5001][5001];

int init()
{
    for (int i = 0; i < 5001; ++i)
        for (int j = 0; j < 5001; ++j)
            cache[i][j] = -1;
}
int combination(int n, int r)
{
    if (n == 0 || r == 0 || n == r)
        return 1;
    int &ret = cache[n][r];
    if (ret != -1)
        return ret;

    return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        init();
        if (nums.size() <= 2)
            return 0;
        int ret = 0;
        vector<int> diff(nums.size() - 1), sameCnt;
        for (int i = 0; i < nums.size() - 1; ++i)
            diff[i] = nums[i + 1] - nums[i];

        for (int i = 0; i < diff.size() - 1; ++i)
        {
            int startIdx{i};
            while (i + 1 < diff.size() && diff[i + 1] == diff[i])
                i++;
            int lastIdx{i};

            int len = lastIdx - startIdx + 2;

            if (len > 2)
                ret += ((len - 1) * (len - 2)) / 2;
        }
        return ret;
    }
};
int main()
{
    init();
    vector<int> arr = {6, 3, 5, 7, 9};
    cout << Solution().numberOfArithmeticSlices(arr);
    return 0;
}
