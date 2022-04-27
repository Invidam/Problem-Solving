#include <iostream>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/2839

int solve(int N)
{
    int cnt{N / 5};
    N %= 5;
    while (N > 0 && cnt > -1)
    {
        if (N % 3 == 0)
        {
            cnt += N / 3;
            return cnt;
        }
        else
        {
            N += 5;
            cnt--;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cout << solve(N) << '\n';
    return 0;
}
