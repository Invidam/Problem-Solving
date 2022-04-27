#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/11399

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N{0};
    cin >> N;
    vector<int> vec(N);
    for (int i{0}; i < N; ++i)
        cin >> vec[i];
    sort(vec.begin(), vec.end(), greater<int>());
    int sum{0};
    for (int i{0}; i < N; ++i)
        sum += vec[i] * (i + 1);
    cout << sum << '\n';
}
