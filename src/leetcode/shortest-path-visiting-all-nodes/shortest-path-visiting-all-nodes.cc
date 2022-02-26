#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
map<p, int> cache;
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
        if (isVisited(idx))
        {
            // cout << "ALREADY VISIT : " << idx << "!\n";
            return;
        }
        int bit = 1 << idx;
        visitedData += bit;
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

int shortestPathLengthFor(int idx, Data &data, vector<vector<int>> &graph)
{
    if (data.isMax())
        return 0;
    int depth = 1;
    int ret = MAX;
    queue<p> q;
    q.push(p(idx, data.get()));
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            int topIdx = q.front().first;
            int topDataVal = q.front().second;

            q.pop();
            Data topData = Data(topDataVal, graph.size());
            for (auto nextIdx : graph[topIdx])
            {
                Data nextData = Data(topDataVal, graph.size());
                nextData.visit(nextIdx);
                p nextPairData = p(nextIdx, nextData.get());
                if (nextData.isMax())
                {
                    ret = depth;
                    cache[nextPairData] = ret;
                    return ret;
                }
                if (cache.find(nextPairData) != cache.end())
                {
                    if (cache[nextPairData] < depth)
                        continue;
                    // ret = depth + cache[nextPairData];
                    // return ret;
                }
                q.push(nextPairData);
                cache[nextPairData] = depth;
            }
        }
        depth++;
    }
    return ret;
}
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        cache.clear();
        int ret = MAX;
        for (int i = 0; i < graph.size(); ++i)
        {
            Data data = Data(i, 0, graph.size());
            int cand = shortestPathLengthFor(i, data, graph);
            ret = ret < cand ? ret : cand;
        }
        return ret;
    }
};

int main()
{
    // vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    // vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
    vector<vector<int>> graph = {{1}, {0, 2, 4}, {1, 3}, {2}, {1, 5}, {4}};
    cout << Solution().shortestPathLength(graph);
    return 0;
}
