#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> p;

int solve(int N, int V, vector<vector<int>> &adj)
{
    int ret{0};
    vector<bool> visited(N + 1, false);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto &next : adj[front])
        {
            if (visited[next])
                continue;
            ret++;
            q.push(next);
            visited[next] = true;
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, V;
    cin >> N >> V;
    vector<vector<int>> adj(N + 1, vector<int>());
    for (int i{0}; i < V; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << solve(N, V, adj);
    return 0;
}
