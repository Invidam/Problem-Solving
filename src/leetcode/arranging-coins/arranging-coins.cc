#include <iostream>
#include <limits>

// Problem site: https://leetcode.com/problems/arranging-coins
// https://leetcode.com/problems/arranging-coins/
class StairCase
{

    int val;
    const int FIRST_ELEMENT{2};
    int stairSum;
    int rows;

public:
    StairCase(int value) : val(value)
    {
        rows = 1;
    }
    void makeStairSum2()
    {

        stairSum = (1 + sqrt(8 * val + 1)) / 2 - 1;
        stairSum = (stairSum < 0 ? (std::numeric_limits<int>::max()) : stairSum);
    }
    //계단 수의 합이 val보다 작은지 비교
    // 입력된 val을 채울만큼의(sum[k-1] < val <= sum[k]) 계단을 생성하였을 때의 합을 구한다.
    void makeStairSum()
    {
        // FIRST_ELEMENT  = 2
        //계단이 1을 제외하고 2부터 시작하므로 계단 수의 합도 2부터 계산한다.
        stairSum = FIRST_ELEMENT;
        int num{FIRST_ELEMENT + 1};
        //마지막 계단의 합이 아직 val보다 작으면 반복
        while (stairSum < val)
        {
            //계단의 합이 INT_MAX을 넘어갈 것 같으면, 넘어가는 수 대신 INT_MAX로 치환한다.
            //조건에 의해 val이 아무리 크더라도 INT_MAX보다 크진 않으므로 문제되지 않는다.
            if (stairSum >= (std::numeric_limits<int>::max() - num))
            {
                stairSum = std::numeric_limits<int>::max();
                rows++;
                break;
            }
            //다음 계단까지 더한 합을 저장한다.
            stairSum += num;
            rows++;
            num++;
        }
    }
    int completedRows()
    {
        makeStairSum2();
        return rows;
    }
};

class Solution
{
public:
    int arrangeCoins(int n)
    {
        return StairCase(n).completedRows();
    }
};
int main()
{
    std::cout << Solution().arrangeCoins(5) << "\n";
    std::cout << Solution().arrangeCoins(2147483647) << "\n";
}

// https://leetcode.com/submissions/detail/659796649/