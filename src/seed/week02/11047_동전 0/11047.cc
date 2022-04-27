#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/11047

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K, coinIdx{0};
    cin >> N >> K;
    vector<int> coins(N);
    while (coinIdx < N)
    {
        cin >> coins[coinIdx];

        if (coins[coinIdx] > K)
            break;
        coinIdx++;
    }
    int ret{0};
    coinIdx--;
    while (coinIdx > -1 || K > 0)
    {
        ret += K / coins[coinIdx];
        K %= coins[coinIdx];
        coinIdx--;
    }
    cout << ret << '\n';
}
