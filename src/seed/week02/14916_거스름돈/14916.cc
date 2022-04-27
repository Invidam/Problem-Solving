#include <iostream>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/14916

int solve(int N)
{
    int ret{0};
    ret += N / 5;
    N %= 5;

    while (ret >= 0 && N > 0)
    {
        if (N % 2 == 0)
        {
            ret += N / 2;
            return ret;
        }
        else
        {
            N += 5;
            ret--;
        }
    }
    return ret;
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

/*

2: 4개 이하로만 쓰여야함
5개 이상이면 5원으로 하면되잖음.

5:
*/