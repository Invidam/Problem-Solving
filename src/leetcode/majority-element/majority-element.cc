#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <deque>
using namespace std;
// Solution
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int maj = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            maj == nums[i] ? ++cnt : --cnt;

            if (!cnt)
            {
                maj = nums[i];
                cnt = 1;
            }
        }
        return maj;
    }
};
// mine
//  class Solution
//  {
//  public:
//      int majorityElement(vector<int> &nums)
//      {
//          deque<int> deq;
//          int answer = -1;
//          for (auto num : nums)
//              deq.push_back(num);
//          while (!deq.empty())
//          {
//              if (deq.size() % 2 == 1)
//              {
//                  answer = deq.back();
//                  deq.pop_back();
//              }

//             if (deq.empty())
//                 break;
//             if (deq.size() % 2 == 1 || deq.size() == 1)
//                 return -1;
//             int n = deq.size();
//             for (int i = 0; i < n / 2; ++i)
//             {
//                 if (deq[0] == deq[1])
//                 {
//                     deq.push_back(deq.front());
//                 }
//                 deq.pop_front();
//                 deq.pop_front();
//             }
//         }
//         return answer;
//     }
// };

// Problem site: https://leetcode.com/problems/majority-element
void test()
{
    int cnt = 100;
    while (cnt)
    {
        int size = rand() % 100 + 1;
        int answer = rand() % size + 1;
        vector<int> nums(1, answer);
        for (int i = 0; i < size / 2; ++i)
        {
            int num = rand() % size + 1;
            nums.push_back(num);
        }
        for (int i = 0; i < size / 2; ++i)
        {
            int idx = rand() % nums.size();
            nums.insert(nums.begin() + idx, answer);
        }
        vector<int> nums_copy = nums;
        int testValue = Solution().majorityElement(nums);
        if (answer != testValue)
        {
            printf("\nANSWER: %d, TESTVALUE : %d\n", answer, testValue);
            for (auto elem : nums_copy)
                cout << elem << " ";
            cout << "\n\n";
            break;
        }
    }
    cout << "END\n\n";
}
int main()
{
    srand(time(NULL));
    test();
    vector<int> testArr = {9, 9, 9, 9, 13, 13, 13, 13, 9, 9, 9, 2, 9, 16, 9, 13, 9};
    cout << Solution().majorityElement(testArr);
    return 0;
}

// 6 8 6 6 4 6 10 6 4 6 1 8 6 12 0 0 6 0 0 0 00 0 0 0 0 0

//     6 12 6
// 6 8 8 3 3 8 8 1 8 11 0 0 0 0 0 0 0 0

// 1000 개의 23 그리고 499개의 233
// 499개의 233 그리고 500개의 23
//

// 1개의 233 500개의 23 249개의 233
// 499개의 23 249개의 233
// 1개의 23 249개의 233 249개의 23
// 248개의 233 249개의 23
// 23(1) 233(124) 23 (124)
//

// 0 0 0 0 1 1 1 | 0 - 0 - 1 - / 1 0 0 0 1 1 1 0 | 0 - 0 - 1 - / 0

//                                                                 1001 1이 나오네용
// 0 0  : 0
// 0 1  : 1
// 1 0  : 1
// 1 1  : 0
//
// 홀수면 하나 뺀다.
// 싸이클 돌린다.
// 1개 있으면 반환
// 0개 있으면 뺀 홀수 반환
// 2개 이상이면 다시 처음부터

// 37 37 37 37 14 37 40 37 37 37 23 21 16 37 35 37 12 37 37 37 37 37 37 37 47 28 37 11 65 23 37 37 43 37 37 70 37 61 37 37 37 37 2 27 69 67 44 37 29 47 37 3 37 37 7 36 58 37 37 11 37 51 37 15 37 19 14 29 42 36 33 37 / 57 37 --37 -- -- -- -- --37 -- -- -- -- -- -- -- -- --37 --37 --37 -- -- -- -- -- -- --37 -- -- -- -- -- -- --37 --37 -- - -- -- -- -- -- -- -- -- -37 -- - -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --37 37 37 37 37

// 4 4 4 / 83
// 9 9 9 8 9 2 9 12 9 3 9 11 12 9 - - - - - - -- - - - -- / 12
// 2 2 3 3 6 2 2 2 8 10 2 2 2 9 2 2 - 3 - - -2 - - --2 - - - / 2
