#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int integerReplacement(int n)
    {
        int MAX = 0;
        const unsigned int RESULT{1};
        int cnt{0};
        std::queue<unsigned int> q;
        q.push(static_cast<int>(n));
        while (!q.empty())
        {
            int n = q.size();
            MAX = MAX > n ? MAX : n;
            for (int i = 0; i < n; ++i)
            {
                unsigned int top = q.front();
                q.pop();

                if (top == RESULT)
                {
                    cout << "MAX : " << MAX << '\n';
                    return cnt;
                }

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
    int n = 2147483647;
    cout << Solution().integerReplacement(n) << '\n';
}