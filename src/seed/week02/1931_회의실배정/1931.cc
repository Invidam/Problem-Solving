#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/1931
void solve(vector<pair<int, int>> &vec)
{
    int cnt{0};
    int endTime{0};
    for (auto &elem : vec)
    {
        int start = elem.second;
        int end = elem.first;

        if (endTime > start)
            continue;
        endTime = end;
        cnt++;
    }

    cout << cnt << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    int start, end;
    for (int i{0}; i < N; ++i)
    {
        cin >> start >> end;
        vec[i] = make_pair(end, start);
    }
    sort(vec.begin(), vec.end());
    solve(vec);
    return 0;
}

/*
그리디: 정렬 많음 (p 정렬시 경우 4개밖에 없음)
여러 전략 세운 후
맞는지 확인 후 맞으면 그대로 풀기
*/