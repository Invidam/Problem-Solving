#include <iostream>
#include <stack>
using namespace std;

// Problem site: https://leetcode.com/problems/valid-parentheses
class Solution
{
public:
    bool isClosingBracket(char ch)
    {
        string close = "])}";
        for (auto bracket : close)
            if (ch == bracket)
                return true;

        return false;
    }
    char reverseBracket(char ch)
    {
        string close = "])}";
        string open = "[({";
        for (int i = 0; i < 3; ++i)
        {
            if (close[i] == ch)
                return open[i];
            if (open[i] == ch)
                return close[i];
        }
        return 'Z';
    }
    bool isValid(string s)
    {
        stack<char> st;
        for (auto ch : s)
        {
            if (!isClosingBracket(ch))
                st.push(ch);
            else
            {
                if (st.empty() || st.top() != reverseBracket(ch))
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};
int main()
{

    return 0;
}
