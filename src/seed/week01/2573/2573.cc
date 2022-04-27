#include <iostream>
#include <vector>
#include <utility>
#include <queue>
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
void visit(int i, int j, vector<vector<bool>> &visited)
{
    visited[i][j] = true;
}
void visit(p coord, vector<vector<bool>> &visited)
{
    visit(coord.first, coord.second, visited);
}
bool isRange(int i, int j, vector<vector<int>> &arr)
{
    int N = arr.size();
    int M = arr[0].size();
    return !(i < 0 || j < 0 || i >= N || j >= M);
}
bool canVisit(int i, int j, vector<vector<int>> &arr, vector<vector<bool>> &visited)
{
    return (isRange(i, j, arr) && arr[i][j] && !visited[i][j]);
}
bool canVisit(p coord, vector<vector<int>> &arr, vector<vector<bool>> &visited)
{
    return canVisit(coord.first, coord.second, arr, visited);
}
void bfs(int i, int j, vector<vector<int>> &arr, vector<vector<bool>> &visited)
{
    visit(i, j, visited);
    queue<p> q;
    q.push(p(i, j));

    while (!q.empty())
    {
        p front = q.front();
        q.pop();

        for (int k{0}; k < OFFSET_SIZE; ++k)
        {
            p next{front.first + OFFSET[k][0], front.second + OFFSET[k][1]};
            if (!canVisit(next, arr, visited))
                continue;
            visit(next, visited);
            q.push(next);
        }
    }
}
int getDivideSize(int N, int M, vector<vector<int>> &arr)
{
    int divideSize{0};
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            if (arr[i][j] && !visited[i][j])
            {
                bfs(i, j, arr, visited);
                divideSize++;
            }
        }
    }
    return divideSize;
}
void updateArr(int N, int M, vector<vector<int>> &arr)
{
    vector<vector<int>> temp = arr;
    for (int i{0}; i < N; ++i)
    {
        for (int j{0}; j < M; ++j)
        {
            if (!arr[i][j])
                continue;
            int value{0};
            for (int k{0}; k < OFFSET_SIZE; ++k)
            {
                int xoff{i + OFFSET[k][0]};
                int yoff{j + OFFSET[k][1]};

                if (!isRange(xoff, yoff, arr) || temp[xoff][yoff] != 0)
                    continue;
                value++;
            }
            arr[i][j] = arr[i][j] - value > 0 ? arr[i][j] - value : 0;
        }
    }
}
int solve(int N, int M, vector<vector<int>> &arr)
{
    int year = 0;
    int dividedSize{getDivideSize(N, M, arr)};

    while (dividedSize == 1)
    {
        updateArr(N, M, arr);
        year++;
        dividedSize = getDivideSize(N, M, arr);
    }
    return dividedSize == 0 ? 0 : year;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M));
    for (int i{0}; i < N; ++i)
        for (int j{0}; j < M; ++j)
            cin >> arr[i][j];
    cout << solve(N, M, arr) << '\n';
    return 0;
}
// temp 배열이 아닌 melt map 이용