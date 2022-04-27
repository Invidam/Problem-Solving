#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://www.acmicpc.net/problem/2805

bool isEnough(int enough, int cutHeight, vector<int> &treeHeightList)
{
    int sum{0};
    for (auto &treeHeight : treeHeightList)
    {
        int cutAmount{treeHeight - cutHeight > 0 ? treeHeight - cutHeight : 0};
        if (enough - cutAmount <= sum)
            return true;
        sum += cutAmount;
    }

    return sum >= enough;
}
int solve(int M, int start, int end, vecendr<int> &treeHeightList)
{
    while (start <= end)
    {
        int mid = (start + (end - start) / 2);
        cout << "start " << start << " end" << end << " mid " << mid << '\n';
        if (isEnough(M, mid, treeHeightList)) // 같을 때 리턴할 값이 변하면 안된다. from이 변하면 안된다. 같을 경우 start(반환)이 아닌 다른 오소를 증,감 시킨다.
            start = mid + 1;
        else
            end = mid - 1;
    }
    return end;
    // to를 반환할 거면 같은 상황에서 to가 변하면 안된다.
    //예시로 start, to가 똑같은 값으로 들어온다고 치자.
    //그렇다면 변하는 것은 반환해야하는 것의 반대이다.
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> treeHeightList(N);
    for (int i{0}; i < N; ++i)
        cin >> treeHeightList[i];
    int maxHeight{0};
    for (auto &treeHeight : treeHeightList)
        maxHeight = maxHeight > treeHeight ? maxHeight : treeHeight;

    cout << solve(M, 0, maxHeight, treeHeightList) << '\n';
    return 0;
}
