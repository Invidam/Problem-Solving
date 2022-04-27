#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/13904

void solve(vector<pair<int, int>> &vec)
{
    sort(vec.begin(), vec.end());
    int pointSum{0};
    vector<bool> allocated(1001, false);

    for (auto &elem : vec)
    {
        int day = {-elem.second};
        int point = {-elem.first};

        while (day > 0 && allocated[day])
            day--;
        if (day == 0)
            continue;
        allocated[day] = true;
        pointSum += point;
    }
    cout << pointSum << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for (int i{0}; i < N; ++i)
    {
        int day, point;
        cin >> day >> point;
        vec[i] = make_pair(-point, -day);
    }
    solve(vec);
    return 0;
}

// 정렬
// 구상
