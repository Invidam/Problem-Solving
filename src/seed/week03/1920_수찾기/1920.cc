#include <iostream>
#include <unordered_map>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/1920

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<int, bool> m;
    int N, M;
    cin >> N;
    int num;
    for (int i{0}; i < N; ++i)
    {
        cin >> num;
        m[num] = true;
    }
    cin >> M;
    for (int i{0}; i < M; ++i)
    {
        cin >> num;
        cout << m[num] << '\n';
    }
    return 0;
}

/*
시복: m
공복: N

*/