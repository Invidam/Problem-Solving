#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> s;
        if (num.length() <= k)
            return "0";

        s.push(num[0]);
        for (int i = 1; i < num.length(); ++i)
        {
            while (!s.empty() && k > 0 && s.top() > num[i])
            {
                s.pop();
                k--;
            }

            s.push(num[i]);
        }
        while (k--)
            s.pop();
        string ret = "";
        while (!s.empty())
        {
            if (s.top() != "0")
                ret.push_back(s.top());
            s.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret.length() == 0 ? "0" : ret;
    }
};
int main()
{
    cout << Solution().removeKdigits("1234567890", 9) << "\n";
    return 0;
}
