#include <iostream>
#include <stack>
using namespace std;

// Problem site: https://leetcode.com/problems/score-of-parentheses
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        const int OPEN = -1;
        const int CLOSE = -2;
        stack<int> st;
        for (auto &elem : s)
        {
            if (elem != '(' && elem != ')')
                st.push(elem - '0');
            else if (elem == '(')
                st.push(OPEN);
            else
            {
                int num = 1;
                int sum = 0;
                while (st.top() != OPEN)
                {
                    sum += 2 * st.top();
                    st.pop();
                }
                st.pop();
                st.push(sum == 0 ? num : sum);
            }
        }

        int ret = 0;
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }
        return ret;
    }
};
int main()
{
    cout << Solution().scoreOfParentheses("(((811)))") << '\n';
    return 0;
}
