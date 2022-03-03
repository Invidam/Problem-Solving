#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Problem site: https://leetcode.com/problems/longest-substring-without-repeating-characters
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> charCache;
        int cand = 0, ret = 0;
        queue<int> q;
        for (int i = 0; i < s.length(); ++i)
        {
            cout << (charCache[s[i]] >= q.front()) << charCache[s[i]] << q.front() << "\n";
            if (charCache[s[i]] >= q.front())
            {
                while (!q.empty())
                    q.pop();
            }
            charCache[s[i]] = i;
            q.push(i);
            ret = ret > q.size() ? ret : q.size();
        }

        return ret;
    }
};
int main()
{
    cout << Solution().lengthOfLongestSubstring("dvdvf");
    return 0;
}
