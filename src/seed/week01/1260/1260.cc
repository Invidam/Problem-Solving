#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/1260
bool isVisit(int num, vector<bool> &visited)
{
    return visited[num];
}
void visit(int num, vector<bool> &visited)
{
    visited[num] = true;
}
void funcDfs(int curr, vector<vector<bool>> &adj, vector<bool> &visited)
{
    visit(curr, visited);
    cout << curr << ' ';

    for (int next{1}; next < adj[curr].size(); ++next)
    {
        if (adj[curr][next] && !isVisit(next, visited))
        {
            funcDfs(next, adj, visited);
        }
    }
}
void stackDfs(int curr, vector<vector<bool>>& adj, vector<bool> &visited)
{
    int N{static_cast<int>(adj.size())};
    stack<int> s;
    s.push(curr);
    while (!s.empty())
    {
        curr = s.top();
        s.pop();
        if (isVisit(curr, visited))
            continue;
        visit(curr, visited);
        cout << curr << ' ';
        for (int next{N - 1}; next > 0; --next)
        {
            // cout << "NEXT: " << next << " " << adj[curr][next] << "  " << !isVisit(next, visited) << '\n';
            if (adj[curr][next] && !isVisit(next, visited))
                s.push(next);
        }
    }
}

// *1  4  3  *2  *4
// *3 4 1 2
void callFuncDfs(int initValue, vector<vector<bool>> &adj, vector<bool> &visited)
{
    funcDfs(initValue, adj, visited);
    cout << '\n';
}

void callStackDfs(int initValue, vector<vector<bool>> &adj, vector<bool> &visited)
{
    stackDfs(initValue, adj, visited);
    cout << '\n';
}

void bfs(int initValue, vector<vector<bool>> &adj, vector<bool> &visited)
{

    queue<int> q;
    visit(initValue, visited);
    q.push(initValue);

    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << ' ';
        q.pop();
        for (int next{1}; next < adj[curr].size(); ++next)
        {
            if (adj[curr][next] && !isVisit(next, visited))
            {
                q.push(next);
                visit(next, visited);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, V;
    cin >> N >> M >> V;
    vector<vector<bool>> adj(N + 1, vector<bool>(N + 1, false));
    vector<bool> visited(N + 1, false);
    for (int i{0}; i < M; ++i)
    {
        int num1, num2;
        cin >> num1 >> num2;
        adj[num1][num2] = true;
        adj[num2][num1] = true;
    }
    for (int i{0}; i < N + 1; ++i)
        adj[i][i] = true;
    callFuncDfs(V, adj, visited);
    // visited = vector<bool>(N + 1, false);
    // callStackDfs(V, adj, visited);
    visited = vector<bool>(N + 1, false);
    bfs(V, adj, visited);
    return 0;
}
//bfs: 최단거리
//우직함 안전함.
//dfs: 나머지
// 재귀 좋아함.
// 계속 파서 정답 찾음 도박임;