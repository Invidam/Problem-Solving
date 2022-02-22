#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Problem site: https://leetcode.com/problems/excel-sheet-column-number
const int EXCEL_DIGIT = 'Z' - 'A' + 1;
int charToNumberOfExcelDigit(char ch)
{
    return ch - 'A' + 1;
}
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ret = 0;
        for (auto ch : columnTitle)
        {
            ret *= EXCEL_DIGIT;
            ret += charToNumberOfExcelDigit(ch);
        }

        return ret;
    }
};
void test()
{
    // srand(time(NULL));

    cout << (Solution().titleToNumber("ZY") == 701) << "\n";
    cout << (Solution().titleToNumber("AB") == 28) << "\n";
    cout << (Solution().titleToNumber("AAA")) << "\n";
}
int main()
{
    test();
    // cout << charToNumberOfExcelDigit('A');
    return 0;
}

//