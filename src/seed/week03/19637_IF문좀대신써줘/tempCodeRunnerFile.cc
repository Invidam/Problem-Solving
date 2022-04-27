#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/19637

string rangeTitle(int num, vector<pair<int, string>> &title)
{
    int start{0}, end{title.size() - 1};
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (num <= title[mid].first)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return title[mid].second;
}

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int num;
    cin >> N >> M;
    vector<pair<int, string>> title(N);
    for (int i{0}; i < N; ++i)
    {
        cin >> title[i].second;
        cin >> title[i].first;
    }
    sort(title.begin(), title.end(), cmp);
    // title.insert(title.begin(), make_pair(-1, "F"));
    for (int i{0}; i < M; ++i)
    {
        cin >> num;
        cout << rangeTitle(num, title) << '\n';
    }
    return 0;
}
