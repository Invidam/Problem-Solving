#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/19637

int rangeTitleIdx(int num, vector<int> &title)
{
    int start{0}, end{title.size() - 1}, mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (num <= title[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return title[start];
}
//lo 해당 x hi : 해당
// 두개가 붙을 때까지 반복
// 두개가 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int num;
    string str;
    cin >> N >> M;
    vector<int> title;
    unordered_map<int, string> m;
    for (int i{0}; i < N; ++i)
    {
        cin >> str >> num;
        if (m.find(num) != m.end())
            continue;
        m[num] = str;
        title.push_back(num);
    }
    //중복 제거 안하면 왜틀림?
    for (int i{0}; i < M; ++i)
    {
        cin >> num;
        cout << m[rangeTitleIdx(num, title)] << '\n';
    }
    return 0;
}
