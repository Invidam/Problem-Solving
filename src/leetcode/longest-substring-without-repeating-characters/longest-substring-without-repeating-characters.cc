#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/longest-substring-without-repeating-characters
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> charCache;
        int cand = 0, ret = 0;
        vector<int> arr;
        for (int i = 0; i < s.length(); ++i)
        {
            while (!arr.empty() && charCache.find(s[i]) != charCache.end() && charCache[s[i]] >= arr.front())
                arr.erase(arr.begin(), arr.begin() + 1);
            charCache[s[i]] = i;
            arr.push_back(i);
            ret = ret > arr.size() ? ret : arr.size();
        }

        return ret;
    }
};
int main()
{
    cout << Solution().lengthOfLongestSubstring("ab");
    return 0;
}
