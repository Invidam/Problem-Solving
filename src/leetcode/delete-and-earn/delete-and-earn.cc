#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int PICK = 1, PASS = 0;
// Problem site: https://leetcode.com/problems/delete-and-earn
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<vector<int>> cache = vector<vector<int>>(2, vector<int>(1e4 + 1, 0));
        map<int, int> cnt;
        int ret = 0;
        for (auto num : nums)
            cnt[num]++;

        for (int num = 1; num < 1001; ++num)
        {
            int &elem = cnt[num];
            int &pickCase = cache[PICK][num];
            int &passCase = cache[PASS][num];

            pickCase = cache[PASS][num - 1] + num * elem;
            passCase = cache[PASS][num - 1] > cache[PICK][num - 1] ? cache[PASS][num - 1] : cache[PICK][num - 1];
            int maxCase = pickCase > passCase ? pickCase : passCase;
            ret = ret > maxCase ? ret : maxCase;
        }
        return ret;
    }
};
int main()
{

    // vector<int> nums = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 1, 1, 2, 3, 3, 3};
    // vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4};
    vector<int> nums = {1, 3, 3};
    cout << Solution().deleteAndEarn(nums);
    return 0;
}
