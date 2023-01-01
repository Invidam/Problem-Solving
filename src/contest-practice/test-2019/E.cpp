#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_SIZE = 1e5 + 1;

vector<bool> isVisited;
vector<bool> isMember;
vector<vector<int>> owner;
vector<vector<int>> subNum;

int solve(int startNum) {
    if (isVisited[startNum]) return false;
    isVisited[startNum] = true;
    int ret = isMember[startNum];

    for (auto &nextNum: owner[startNum])
        ret += solve(nextNum);
    for (auto &nextNum: subNum[startNum])
        ret += solve(nextNum);

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        int N;
        cin >> N;
        vector<int> members;
        owner = vector<vector<int>>(MAX_SIZE,vector<int>());
        subNum = vector<vector<int>>(MAX_SIZE,vector<int>());
        isVisited = vector<bool>(MAX_SIZE,false);
        isMember = vector<bool>(MAX_SIZE,false);
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            members.push_back(num);
            isMember[num] = true;
            for (int k = 2; k * k <= num; ++k) {
                if (num % k != 0) continue;
                subNum[num].push_back(k);
                owner[k].push_back(num);
                subNum[num].push_back(num/k);
                owner[num/k].push_back(num);
            }

        }
        int ret = 1;
        for (auto num: members) {
            ret = max(ret, solve(num));
        }
        cout << ret << '\n';
    }
}
/*
1
4 20 50 9 63
6
4 4 6 15 35
4 20 50 9 63
8 2 3 6 7 4 12 21 39
4 4 6 15 35
4 20 50 9 63
8 2 3 6 7 4 12 21 39


 2
8 2 3 6 7 4 12 21 39
8 2 3 6 7 4 12 21 39
1
8 2 3 6 7 4 12 21 39
 */

