#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/counting-bits
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i < n + 1; ++i)
        {
            if (i % 2 == 0)
                ans[i] = ans[i / 2];
            else
                ans[i] = ans[i - 1] + 1;
        }
        return ans;
        // ans[i] = ans[i/2] + i%2;
        // ans[i] = ans[i & (i-1)] + 1;
    }
};
int main()
{
    vector<int> ans = Solution().countBits(5);
    for (auto elem : ans)
        cout << elem << " ";
    return 0;
}