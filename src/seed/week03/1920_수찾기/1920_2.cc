#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/1920
bool isExist(int num, vector<int> &vec)
{
    int start{0}, end{vec.size() - 1};
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (num <= vec[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start < vec.size() && num == vec[start];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N;
    vector<int> vec(N);
    int num;
    for (int i{0}; i < N; ++i)
    {
        cin >> num;
        vec[i] = num;
    }
    sort(vec.begin(), vec.end());
    cin >> M;
    for (int i{0}; i < M; ++i)
    {
        cin >> num;
        cout << isExist(num, vec) << '\n';
    }
    return 0;
}

/*
시복: nlogn + mlogn
공복: N

*/