#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;
typedef pair<int, int> p;
string intToBinStr(int num)
{

    string retReverse = "";
    while (num > 0)
    {
        retReverse += ('0' + num % 2);
        num /= 2;
    }
    if (!retReverse.length())
        retReverse = "0";
    string ret = "";
    for (int i = 0; i < retReverse.length(); ++i)
    {
        ret += retReverse[retReverse.length() - 1 - i];
    }
    return ret;
}
// Problem site: https://leetcode.com/problems/shortest-path-visiting-all-nodes
const int MAX = 1 << 12;
class Data
{
public:
    Data(int visitIdx, int visitedData, int size) : visitedData(visitedData)
    {
        if (!isVisited(visitIdx))
            visit(visitIdx);
        MAX_DATA = (1 << size) - 1;
    }
    Data(int data, int size)
    {
        visitedData = data % MAX;
        MAX_DATA = (1 << size) - 1;
    }
    bool isVisited(int idx)
    {
        int bit = 1 << idx;
        return visitedData & bit;
    }
    void visit(int idx)
    {
        int bit = 1 << idx;
        visitedData = visitedData | bit;
    }
    int get()
    {
        return visitedData;
    }
    bool isMax()
    {
        return visitedData == MAX_DATA;
    }
    string visitedDataStr()
    {
        return intToBinStr(visitedData);
    }

private:
    int visitedData;
    int MAX_DATA;
};

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> cache = vector<vector<bool>>(MAX, vector<bool>(MAX, false));
        int ret = MAX;
        for (int i = 0; i < graph.size(); ++i)
        {
            Data data = Data(0, graph.size());
            data.visit(i);
            cache[i][data.get()] = true;
            q.push(tuple<int, int, int>(i, data.get(), 0));
        }
        while (!q.empty())
        {
            auto [topIdx, topDataVal, depth] = q.front();
            q.pop();
            if (Data(topDataVal, graph.size()).isMax())
                return ret = depth;
            for (auto nextIdx : graph[topIdx])
            {
                Data nextData = Data(topDataVal, graph.size());
                nextData.visit(nextIdx);
                if (cache[nextIdx][nextData.get()])
                {
                    continue;
                }
                cache[nextIdx][nextData.get()] = true;
                q.push(tuple<int, int, int>(nextIdx, nextData.get(), depth + 1));
            }
        }
        return ret;
    }
};
int main()
{
    // vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    // vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
    vector<vector<int>> graph = {{2, 3}, {7}, {0, 6}, {0, 4, 7}, {3, 8}, {7}, {2}, {5, 3, 1}, {4}};
    // vector<vector<int>> graph = {{1}, {0}};
    // vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3}, {2}, {1, 5}, {4}};
    cout << Solution().shortestPathLength(graph);
    return 0;
}

// 얘만 7이 나옴 예시 확인해봐야 할듯 그려가면서