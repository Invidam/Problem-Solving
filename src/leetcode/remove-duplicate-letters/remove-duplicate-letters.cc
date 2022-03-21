#include <iostream>
#include <map>
#include <unordered_map>
#include <deque>
using namespace std;

// Problem site: https://leetcode.com/problems/remove-duplicate-letters
class Solution
{

    unordered_map<char, deque<int>> left;
    unordered_map<char, int> used;
    string ret;
    string str;

public:
    void init(string s)
    {
        str = s;
        ret = "";
        used.clear();
        left.clear();
        for (int i = 0; i < s.length(); ++i)
            left[s[i]].push_back(i);
    }
    void pushItem(int itemIdx, int retIdx)
    {
        if (retIdx == ret.length())
            ret.push_back(str[itemIdx]);
        else
            ret.insert(ret.begin() + retIdx, str[itemIdx]);
        used[str[itemIdx]] = itemIdx;
        left[str[itemIdx]].pop_front();
    }
    void removeItem(int retIdx)
    {
        used.erase(used.find(ret[retIdx]));
        ret.erase(ret.begin() + retIdx);
        // used[str[retIdx]] = 제거;
    }
    bool isUsing(int idx)
    {
        return used.find(str[idx]) != used.end();
    }
    bool isLeftFrom(int idx, char ch)
    {
        return idx < left[ch].back();
    }
    bool canPush(int charIdx, int toPushIdx)
    {
        char toPushChar = str[charIdx];
        char existChar = ret[toPushIdx];
        return (toPushChar < existChar && isLeftFrom(charIdx, existChar));
    }
    string removeDuplicateLetters(string s)
    {
        init(s);
        for (int i = 0; i < s.length(); ++i)
        {
            // cout << "RET: " << ret << " IDX: " << i << '\n';
            const char &ch = s[i];
            if (ret.empty())
                pushItem(i, 0);
            else if (isUsing(i))
                left[str[i]].pop_front();
            else // 처음 등장
            {
                int toPushIdx = ret.length();
                while (toPushIdx != 0)
                {
                    if (canPush(i, toPushIdx - 1))
                    {
                        removeItem(toPushIdx - 1);
                        toPushIdx--;
                    }
                    else
                        break;
                    /*
                    여기서 아예 기존 문자를 없애고 나중에 넣을수도 있지만,
                    toPushIdx 직후의 인덱스에 넣어도 되지않나?
                    그렇게 된다면, bcacb 같은 경우
                    bca가 들어왔을 때 bca -> abc가 되어버림.
                    시간복ㅈㅂ도가 ㅇ떻게 되지?
                    */
                }
                pushItem(i, toPushIdx);
            }
        }
        return ret;
    }
};

int main()
{
    // cout << Solution().removeDuplicateLetters("ab") << '\n';
    cout << Solution().removeDuplicateLetters("bcabc") << '\n';
    cout << Solution().removeDuplicateLetters("bcacb") << '\n';
    cout << Solution().removeDuplicateLetters("bczbc") << '\n';
    return 0;
}
