#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/two-sum
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < nums.size(); ++j)
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
    }
};
int main()
{
    vector<int> nums = {1, 4, 7, 8, 13};
    int target = 14;
    cout << Solution().twoSum(nums, 14)[0] << " " << Solution().twoSum(nums, 14)[1];
    return 0;
}
