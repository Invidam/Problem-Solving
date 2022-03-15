#include <iostream>
#include <stack>
using namespace std;

// Problem site: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        const char OPEN_PARENTHESES = '(';
        const char CLOSE_PARENTHESES = ')';
        stack<int> idxStore;
        for (int i = 0; i < s.size(); ++i)
        {
            char &ch = s[i];
            if (ch == OPEN_PARENTHESES)
            {
                idxStore.push(i);
            }
            else if (ch == CLOSE_PARENTHESES)
            {
                if (idxStore.empty())
                {
                    s.erase(s.begin() + i, s.begin() + i + 1);
                    i--;
                }
                else
                    idxStore.pop();
            }
        }
        while (!idxStore.empty())
        {
            int topIdx = idxStore.top();
            s.erase(s.begin() + topIdx, s.begin() + topIdx + 1);
            idxStore.pop();
        }
        return s;
    }
};
int main()
{
    cout << Solution().minRemoveToMakeValid("))((") << '\n';
    return 0;
}
