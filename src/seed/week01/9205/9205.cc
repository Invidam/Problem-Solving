#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> p;
// Problem site: https://www.acmicpc.net/problem/9205
/*
맥주 한박스 20개
50미텁당 한병
빈병버리고 한 박스 20병

TC
n(편의점)
상근 집
편의점
락페 위치


맨허튼거리 x+y 가 거리
*/
const int MAX_BEER{20};
const int MAX_MOVE{50};
int getRange(p coord1, p coord2)
{
    int xDiff = coord1.first - coord2.first;
    xDiff = xDiff > 0 ? xDiff : -xDiff;
    int yDiff = coord1.second - coord2.second;
    yDiff = yDiff > 0 ? yDiff : -yDiff;

    return xDiff + yDiff;
}
bool canVisit(p coord1, p coord2)
{
    return getRange(coord1, coord2) <= MAX_BEER * MAX_MOVE;
}
/*
-16 ~ 0 ~ 15

0 ~ 16 ~ 31

*/
bool canVisitTarget(vector<p> &markets, p homeCoord, p targetCoord)
{
    int N = markets.size();
    queue<p> q;
    if (canVisit(homeCoord, targetCoord))
        return true;
    q.push(homeCoord);
    vector<bool> visited(N, false);
    while (!q.empty())
    {
        p curr = q.front();
        q.pop();

        for (int i{0}; i < N; ++i)
        {
            p next = markets[i];
            if (!canVisit(curr, next) || visited[i])
                continue;
            if (canVisit(next, targetCoord))
                return true;
            cout << next.first << "  " << next.second << '\n';
            visited[i] = true;
            q.push(next);
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    while (TC--)
    {
        int N;
        cin >> N;
        vector<p> markets(N);
        p homeCoord;
        p targetCoord;
        cin >> homeCoord.first >> homeCoord.second;
        for (int i{0}; i < N; ++i)
        {
            int a, b;
            cin >> a >> b;
            markets[i] = p(a, b);
        }
        cin >> targetCoord.first >> targetCoord.second;

        cout << (canVisitTarget(markets, homeCoord, targetCoord) ? "happy" : "sad");
        cout << '\n';
    }
    return 0;
}

// 단순 크기 문제로 코드가 실행안될 수 있다.