#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Problem site: https://leetcode.com/problems/is-subsequence
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int idx{0};
        for (int i = 0; i < t.length(); ++i)
        {
            if (idx >= s.length())
                return true;
            const char &target = s[idx];
            const char &toFind = t[i];
            if (target == toFind)
                idx++;
        }
        return idx >= s.length();
    }
};
int main()
{
    cout << Solution().isSubsequence("abab", "bbbbbbabab") << '\n';
    return 0;
}
