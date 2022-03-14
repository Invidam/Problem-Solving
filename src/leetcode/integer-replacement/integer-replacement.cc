#include <iostream>
#include <limits>
#include <queue>

// Problem site: https://leetcode.com/problems/integer-replacement
class Solution
{
public:
    int integerReplacement(int n)
    {
        const unsigned int RESULT{1};
        int cnt{0};
        std::queue<unsigned int> q;
        q.push(static_cast<int>(n));
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                unsigned int top = q.front();
                q.pop();

                if (top == RESULT)
                    return cnt;

                if (top & 1)
                {
                    q.push(top + 1);
                    q.push(top - 1);
                }
                else
                {
                    q.push(top / 2);
                }
            }
            cnt++;
        }
        return -1;
    }
};
int main()
{
    std::cout << Solution().integerReplacement(2147483647);
    return 0;
}
