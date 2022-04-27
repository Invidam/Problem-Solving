#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int offset[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int OFFSET_SIZE = 4;
// Problem site: https://www.acmicpc.net/problem/2178
int solve(int N, int M, vector<string> &arr)
{
    int ret{1};
    queue<p> q;
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    q.push(p(0, 0));
    visited[0][0] = true;

    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            int x = q.front().first;
            int y = q.front().second;
            if (x == N && y == M)
                return ret;
            q.pop();

            for (int i{0}; i < OFFSET_SIZE; ++i)
            {
                int xoff = x + offset[i][0];
                int yoff = y + offset[i][1];
                if ((xoff < 0 || xoff > N) || (yoff < 0 || yoff > M) || visited[xoff][yoff] || arr[xoff][yoff] == '0')
                    continue;
                q.push(p(xoff, yoff));
                visited[xoff][yoff] = true;
            }
        }
        ret++;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<string> arr(N);
    for (int i{0}; i < N; ++i)
        cin >> arr[i];

    cout << solve(N - 1, M - 1, arr) << '\n';
    return 0;
}

// char로 받으면 '\n'은 무시한다.