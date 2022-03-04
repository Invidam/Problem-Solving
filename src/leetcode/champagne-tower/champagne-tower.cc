#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/champagne-tower
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> cache(101, vector<double>(101, 0));

        cache[0][0] = poured;

        for (int row = 0; row < 100; ++row)
        {
            for (int glass = 0; glass < row + 1; ++glass)
            {
                double &quantity = cache[row][glass];
                if (quantity >= 1)
                {
                    cache[row + 1][glass] += (quantity - 1) / 2;
                    cache[row + 1][glass + 1] += (quantity - 1) / 2;
                    quantity = 1;
                }
            }
        }
        return cache[query_row][query_glass];
    }
};
int main()
{
    cout << Solution().champagneTower(1e9, 22, 16);
    return 0;
}

// 1. 전에껄 비교해서 정네껄로