#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Problem site: https://leetcode.com/problems/partition-labels
class Solution
{
public:
    void combineVector(int from, int to, vector<int> &v)
    {
        int sum{0};
        for (int i = from + 1; i < to + 1; ++i)
        {
            sum += v[i];
            v[i] = 0;
        }
        v[from] += sum;
    }
    vector<int> myPartitionLabels(string s)
    {
        vector<int> partition(s.length(), 1);
        for (int i = s.length() - 1; i > -1; --i)
        {
            char ch = s[i];
            int toCombineIdx{-1};
            for (int j = i + 1; j < s.length(); ++j)
                if (ch == s[j])
                    toCombineIdx = j;
            if (toCombineIdx != -1)
                combineVector(i, toCombineIdx, partition);
        }
        vector<int> ret;
        for (auto &elem : partition)
            if (elem != 0)
                ret.push_back(elem);
        return ret;
    }
    vector<int> partitionLabels(string s)
    {
        vector<int> lastIdx(26, -1), ret{};

        for (int i{0}; i < s.length(); ++i)
            lastIdx[s[i] - 'a'] = i;

        int start{0}, end{0};
        for (int i{0}; i < s.length(); ++i)
        {
            end = end > lastIdx[s[i] - 'a'] ? end : lastIdx[s[i] - 'a'];

            if (i == end)
            {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
};

// e c c b b b d e c

// e c c bbb d e c
// e c cbbbdec

// e ccbbdec

int main()
{
    vector<int> ret = Solution().partitionLabels("abbac");
    for (auto &elem : ret)
        cout << elem << " ";
    cout << "\n";
    return 0;
}
