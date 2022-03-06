#include <iostream>
using namespace std;
typedef long long ll;
// Problem site: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

ll factorial(int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}
const int MOD = 1e9 + 7;
class Solution
{
public:
    int countOrders(int n)
    {
        if (n == 1)
            return 1;
        return ((long long)countOrders(n - 1) * (2 * n - 1) * n) % MOD;
    }
};

int main()
{
    cout << Solution().countOrders(500);
    return 0;
}

/*
This problem is permutation problem.

If there isn't condition, It solved nPn = n!

But, We should consider "delivery(i) is always after of pickup(i)."
So, It solved n! / 2^n.  (2 : d(i) and p(i)'s order is fixed / 2^n : i appears  n times )

f(n) =  (2n)!  / (2^n)
f(n-1) =   (2(n-1))!  / (2^(n-1))
f(n) = f(n-1) * 2n * (2n-1) / 2  =  f (n-1) * n * (2n - 1)

+ consider INT_MAX and MODULA
f(n) <= MOD .
but, MOD * n * (2n - 1) >=  INT_MAX . (X)
So I convert int  to long long.
MOD * n * (2n - 1) <  LONG_LONG_MAX.  (O)

*/