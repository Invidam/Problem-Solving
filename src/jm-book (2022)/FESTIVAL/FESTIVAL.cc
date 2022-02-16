#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://algospot.com/judge/problem/read/FESTIVAL
double MAX = 1000 * 101;

double calcMinCostFrom(int from, int N, int L, vector<int> &cost, int sum)
{
    int sumToLength = sum;
    double result = MAX, cand = MAX;
    for (int length = N - from; length >= L; --length)
    {
        cand = (double)sumToLength / length;
        result = result < cand ? result : cand;

        int lastElemIdx = from + length - 1;
        sumToLength -= cost[lastElemIdx];
    }
    return result;
}
double calcMinCost(int N, int L, vector<int> &cost, vector<int> &sumFromNth)
{
    double result = MAX, cand;
    for (int idx = 0; idx < N; ++idx)
    {
        cand = calcMinCostFrom(idx, N, L, cost, sumFromNth[idx]);
        result = result < cand ? result : cand;
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(8);
    int TC, N, L;
    cin >> TC;
    while (TC--)
    {
        cin >> N >> L;
        vector<int> cost(N), sumFromNth(N);
        double cand = MAX, result = MAX;
        for (int i = 0; i < N; ++i)
            cin >> cost[i];

        for (int i = N - 1; i >= 0; --i)
            sumFromNth[i] = i == N - 1 ? cost[i] : sumFromNth[i + 1] + cost[i];

        result = calcMinCost(N, L, cost, sumFromNth);
        cout << result << '\n';
    }
    return 0;
}

// 리팩터링 이전
// #include <iostream>
// #include <vector>
// using namespace std;

// // Problem site: https://algospot.com/judge/problem/read/FESTIVAL
// double MAX = 1000 * 101;
// int main()
// {
//     freopen("input.txt", "r", stdin);
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout << fixed;
//     cout.precision(8);
//     int TC, N, L;
//     cin >> TC;
//     while (TC--)
//     {
//         cin >> N >> L;
//         vector<int> cost(N);
//         double cand = MAX;
//         for (int i = 0; i < N; ++i)
//             cin >> cost[i];

//         for (int i = 0; i < N; ++i)
//         {

//             if (i + L > N)
//                 break;
//             double sum = 0, before;
//             for (int length = 1; i + length - 1 < N; ++length)
//             {
//                 int idx = i + length - 1;
//                 sum += cost[idx];

//                 if (length < L)
//                     continue;
//                 double candInItr = sum / length;
//                 cand = cand < candInItr ? cand : candInItr;
//             }
//         }
//         cout << cand << '\n';
//     }
//     return 0;
// }

// double calcMinCost(int idx,int N, int L, vector<int>& cost) {

// }