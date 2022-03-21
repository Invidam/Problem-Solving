#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row
class Solution
{
public:
    // 33 11 11 33
    // 11 66 66 11
    // top ret  : 3
    // bottom ret: 6
    // answer{1} is not catch
    // but rotating, top or bottom is full of answer.
    const int NOT_APPEAR{987654321};
    int isOnlyOneFrom(vector<int> &arr)
    {
        for (auto &elem : arr)
            if (elem * elem != arr.front() * arr.front())
                return false;
        return true;
    }
    int frequentNumOverHalf(vector<int> &arr)
    {
        vector<int> freq{0, 0, 0, 0, 0, 0, 0};
        int freqMaxIdx{0};
        for (auto &elem : arr)
            freq[elem]++;

        for (int i{0}; i < freq.size(); ++i)
            freqMaxIdx = freq[freqMaxIdx] > freq[i] ? freqMaxIdx : i;

        return freq[freqMaxIdx] * 2 >= arr.size() ? freqMaxIdx : -1;
    }
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int cnt{minDominoRotationsCnt(tops, bottoms)}, reverseCnt{minDominoRotationsCnt(bottoms, tops)};
        int ret{cnt < reverseCnt ? cnt : reverseCnt};
        return ret != NOT_APPEAR ? ret : -1;
    }
    void swap(vector<int> &tops, vector<int> &bottoms, int idx)
    {
        int tmp = tops[idx];
        if (tmp > 0)
        {
            tops[idx] = -bottoms[idx];
            bottoms[idx] = tmp;
        }
        else
        {
            tops[idx] = bottoms[idx];
            bottoms[idx] = -tmp;
        }
    }
    int isOnlyNum(vector<int> &tops, vector<int> &bottoms)
    {
        return isOnlyOneFrom(tops) || isOnlyOneFrom(bottoms) ? true : false;
    }
    int swapByFreq(vector<int> &tops, vector<int> &bottoms, int freqNum)
    {
        int ret{0};
        for (int i = 0; i < tops.size(); ++i)
        {
            if (tops[i] != freqNum)
            {
                ret++;
                swap(tops, bottoms, i);
            }
        }
        return ret;
    }
    void returnSwap(vector<int> &tops, vector<int> &bottoms)
    {
        for (int i = 0; i < tops.size(); ++i)
            if (tops[i] * bottoms[i] < 0)
                swap(tops, bottoms, i);
    }
    int minDominoRotationsCnt(vector<int> &tops, vector<int> &bottoms)
    {
        int freqNum = frequentNumOverHalf(tops);
        if (freqNum == -1)
            return NOT_APPEAR;

        int swapCnt = swapByFreq(tops, bottoms, freqNum);

        int isOnly = isOnlyNum(tops, bottoms);

        returnSwap(tops, bottoms);

        return isOnly ? swapCnt : NOT_APPEAR;
    }
};

int main()
{
    //     [1,2,1,1,1,2,2,2]
    // [2,1,2,2,2,2,2,2]
    vector<int> tops{1, 2, 1, 1, 1, 2, 2, 2};
    vector<int> bottoms{2, 1, 2, 2, 2, 2, 2, 2};

    cout << Solution().minDominoRotations(tops, bottoms) << '\n';
    return 0;
}
