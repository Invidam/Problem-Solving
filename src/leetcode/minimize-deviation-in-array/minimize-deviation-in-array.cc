#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Problem site: https://leetcode.com/problems/minimize-deviation-in-array

bool isOdd(int num) { return num & 1; }
int applyPerform(int num)
{
    return isOdd(num) ? num * 2 : num / 2;
}
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        set<int> s;

        for (auto num : nums)
        {
            num = isOdd(num) ? num * 2 : num;

            s.insert(num);
        }
        int ret = *s.rbegin() - *s.begin();
        while (!isOdd(*s.rbegin()))
        {
            int num = *s.rbegin();
            s.erase(num);
            s.insert(num / 2);
            ret = ret < *s.rbegin() - *s.begin() ? ret : *s.rbegin() - *s.begin();
        }
        return ret;
    }
};
int main()
{
    vector<int> nums = {4, 1, 5, 20, 3};
    // 2 2 5 10 6
    //  0 3  5 4
    cout << Solution().minimumDeviation(nums) << "\n";
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <queue>
// #include <algorithm>
// using namespace std;

// // Problem site: https://leetcode.com/problems/minimize-deviation-in-array

// bool isOdd(int num) { return num & 1; }
// int applyPerform(int num)
// {
//     return isOdd(num) ? num * 2 : num / 2;
// }
// class Solution
// {
// public:
//     int minimumDeviation(vector<int> &nums)
//     {
//         int ret = INT32_MAX, minNum = INT32_MAX;
//         priority_queue<int> pq;

//         for (auto num : nums)
//         {
//             num = isOdd(num) ? num * 2 : num;
//             minNum = minNum < num ? minNum : num;

//             pq.push(num);
//         }
//         while (!pq.empty())
//         {
//             int num = pq.top();
//             pq.pop();

//             ret = ret < num - minNum ? ret : num - minNum;

//             if (isOdd(num))
//                 break;

//             pq.push(applyPerform(num));
//             minNum = minNum < applyPerform(num) ? minNum : applyPerform(num);
//         }

//         return ret;
//     }
// };
// int main()
// {
//     vector<int> nums = {4, 1, 5, 20, 3};
//     // 2 2 5 10 6
//     //  0 3  5 4
//     cout << Solution().minimumDeviation(nums) << "\n";
//     return 0;
// }
