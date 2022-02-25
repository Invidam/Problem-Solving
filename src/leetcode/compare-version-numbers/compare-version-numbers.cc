#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/compare-version-numbers

// vector<bool> ignoreList(const string &str)
// {
//     vector<bool> ret(false, str.length());
//     int idx = 0;
//     while (idx < str.length())
//     {
//         if (str[idx] == '.')
//             continue;
//         if (idx == 0)
//         {
//             // except
//             // ((str.length() > 1 && str[1] == '.')): n.~
//             // (str[idx] == '0'): 0 or 0n~

//             if (!(str.length() > 1 && str[1] == '.') && (str[idx] == '0'))
//                 ret[idx] = true;
//             continue;
//         }
//         else if (str.length() == idx + 1) // last char
//             continue;
//         else if (ret[idx - 1] && str[idx] == '0') // case: 00
//     }
// }
// class Solution
// {
// public:
//     int compareVersion(string version1, string version2)
//     {
//         vector<bool> leftIgnoreList = ignoreList(version1);
//         vector<bool> rightIgnoreList = ignoreList(version2);
//         int leftIdx = 0, rightIdx = 0;
//         while (leftIdx < version1.size() || rightIdx < version2.size())
//         {
//             char leftCh = version1[leftIdx], rightCh = version2[rightIdx];
//             if (leftIdx >= version1.size())
//             {
//                 if (rightCh == '.' || rightIgnoreList[rightIdx])
//                 {
//                     rightIdx++;
//                     continue;
//                 }
//             }
//             if (rightIdx >= version2.size())
//             {
//                 if (leftCh == '.' || leftIgnoreList[leftIdx])
//                 {
//                     leftIdx++;
//                     continue;
//                 }
//             }
//             if (leftIgnoreList[leftIdx] || rightIgnoreList[rightIdx])
//             {
//                 if (leftIgnoreList[leftIdx])
//                     leftIdx++;
//                 if (rightIgnoreList[rightIdx])
//                     rightIdx++;
//                 continue;
//             }
//             if (leftCh != rightCh)
//                 return leftCh < rightCh ? -1 : 1;
//         }
//         return 0;
//     }
// };
const int LEFT_IS_LESS = -1, RIGHT_IS_LESS = 1, EQUAL_EACH = 0;
unsigned int strToUnsignedInt(string str)
{
    while (str.front() == '0')
        str.erase(str.begin());
    unsigned int ret = stol(str.length() >= 1 ? str : "0");
    return ret;
}
vector<unsigned int> diviedByDot(const string &version)
{
    vector<unsigned int> ret;
    string dividedStr = "";
    for (auto ch : version)
    {
        if (ch == '.')
        {
            ret.push_back(strToUnsignedInt(dividedStr));
            dividedStr = "";
        }
        else
            dividedStr.push_back(ch);
    }
    ret.push_back(strToUnsignedInt(dividedStr));
    return ret;
}

bool isControlLess(const vector<unsigned int> &control, const vector<unsigned int> &compare, int &controlIdx, int &compareIdx)
{
    if (controlIdx >= control.size())
    {
        if (compare[compareIdx] == 0)
            return false;
        else
            return true;
    }
    if (compareIdx >= compare.size())
        return false;
    return control[controlIdx] < compare[compareIdx];
}
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<unsigned int> versionList1 = diviedByDot(version1);
        vector<unsigned int> versionList2 = diviedByDot(version2);
        int leftIdx = 0, rightIdx = 0;
        while (leftIdx < versionList1.size() || rightIdx < versionList2.size())
        {
            if (isControlLess(versionList1, versionList2, leftIdx, rightIdx))
                return LEFT_IS_LESS;
            else if (isControlLess(versionList2, versionList1, rightIdx, leftIdx))
                return RIGHT_IS_LESS;
            leftIdx++;
            rightIdx++;
        }
        return EQUAL_EACH;
    }
};

void test()
{
    int n = 6;
    string versions[2 * n] = {"0.1", "1.1", "1.0",
                              "1.0.0.0.0.0.0.0.01",
                              "0001",
                              "1",
                              "3.14.15",
                              "3.014.015",
                              "010.010.010",
                              "10.10.10", "0", "0.0.0"};
    for (int i = 0; i < n; ++i)
    {
        if (Solution().compareVersion(versions[2 * i], versions[2 * i + 1]))
            cout << "idx: " << (2 * i) << ": " << (versions[2 * i]) << ", " << (versions[2 * i + 1]) << "-> " << Solution().compareVersion(versions[2 * i], versions[2 * i + 1]) << "\n";
    }
}
int main()
{
    // cout << stoi("0001");
    test();
    cout << Solution().compareVersion("1.1", "0.1");
    return 0;
}
