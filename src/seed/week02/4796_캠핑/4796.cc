#include <iostream>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/4796
int getMaxDays(int L, int P, int V)
{
    int sum{0};
    sum += V / P * L;
    V %= P;
    sum += V > L ? L : V;

    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int idx{1};
    int L, P, V;
    while (1)
    {
        cin >> L >> P >> V;
        if (L == P && P == V && V == 0)
            break;
        cout << "Case " << idx++ << ": " << getMaxDays(L, P, V) << '\n';
    }
    return 0;
}
