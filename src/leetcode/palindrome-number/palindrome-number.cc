#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/palindrome-number
class Solution
{
public:
    bool isPalindrome(int x)
    {
        auto str = std::to_string(x);
        std::string rev = str;
        std::reverse(rev.begin(), rev.end());
        return str.compare(rev) == 0;
    }
};
int main()
{

    return 0;
}
