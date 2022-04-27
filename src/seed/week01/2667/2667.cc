#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
// Problem site: https://www.acmicpc.net/problem/2573
/*
빙산

줄어든다
바닷물과 가까운 칸만큼

두덩이로 분리되는 최초시간을 구하여라!
*/
const int OFFSET_SIZE{4};
const int OFFSET[4][2]{
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void visit(int i, int j, vector<string> &arr)
{
    arr[i][j] = '0';
}
void visit(p coord, vector<string> &arr)
{
    arr[coord.first][coord.second] = '0';
}
bool isRange(int i, int j, vector<string> &arr)
{
    int N = arr.size();
    int M = arr[0].size();
    return !(i < 0 || j < 0 || i >= N || j >= M);
}
bool canVisit(int i, int j, vector<string> &arr)
{
    return (isRange(i, j, arr) && arr[i][j] == '1');
}
bool canVisit(p coord, vector<string> &arr)
{
    return canVisit(coord.first, coord.second, arr);
}
int getLinkedComplexSizeByBfs(int i, int j, vector<string> &arr)
{
    int complexSize{1};
    visit(i, j, arr);
    queue<p> q;
    q.push(p(i, j));

    while (!q.empty())
    {
        p front = q.front();
        q.pop();

        for (int k{0}; k < OFFSET_SIZE; ++k)
        {
            p next{front.first + OFFSET[k][0], front.second + OFFSET[k][1]};
            if (!canVisit(next, arr))
                continue;
            visit(next, arr);
            q.push(next);
            complexSize++;
        }
    }
    return complexSize;
}
void solve(int N, vector<string> &arr)
{
    vector<int> listOfComplexSize;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < N; ++j)
        {
            if (canVisit(i, j, arr))
            {
                listOfComplexSize.push_back(getLinkedComplexSizeByBfs(i, j, arr));
            }
        }
    }
    sort(listOfComplexSize.begin(), listOfComplexSize.end());
    cout << listOfComplexSize.size() << '\n';
    for (auto &elem : listOfComplexSize)
        cout << elem << ' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<string> arr(N);
    for (int i{0}; i < N; ++i)
        cin >> arr[i];
    solve(N, arr);
    return 0;
}

//필요없어보이는 조건문은 한번 빼보기