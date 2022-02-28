#include <iostream>
#include <queue>
using namespace std;

// Problem site: https://leetcode.com/problems/summary-ranges

string makeRange(int a, int b)
{
    if (a == b)
        return to_string(a);
    else
        return to_string(a) + "->" + to_string(b);
}
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        queue<int> q;
        vector<string> ret;
        if (nums.size() == 0)
            return ret;
        q.push(nums.front());
        nums.erase(nums.begin(), nums.begin() + 1);

        while (1)
        {

            while (!nums.empty() && q.back() + 1 == nums.front())
            {
                q.push(nums.front());
                nums.erase(nums.begin(), nums.begin() + 1);
            }

            ret.push_back(makeRange(q.front(), q.back()));
            while (!q.empty())
                q.pop();
            if (nums.empty())
                break;
            q.push(nums.front());
            nums.erase(nums.begin(), nums.begin() + 1);
        }

        return ret;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 4, 6, 7, 11};
    const vector<string> &ret = Solution().summaryRanges(nums);
    for (auto elem : ret)
        cout << elem << " ";
    return 0;
}
