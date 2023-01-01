#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int isCriticalNum(int left, int right, int critical, const vector<int> &arr, int repeatIdx) {
    int repeatCnt = 0;
    for (int i = left; i < right+1; ++i) {
        if (arr[i] == arr[repeatIdx]) ++repeatCnt;
        if (repeatCnt >= critical) return arr[repeatIdx];
    }
    return -1;
}

int solve(int left, int right, int critical, vector<int> &arr) {
    int repeatCnt = 1;
    int repeatIdx = left;
    for (int i = left + 1; i < right+1; ++i) {
        if (arr[i] == arr[repeatIdx]) ++repeatCnt;
        else if (repeatCnt > 1) {
            --repeatCnt;
        } else {
            repeatCnt = 1;
            repeatIdx = i;
        }

        if (repeatCnt >= critical) return arr[repeatIdx];
    }
    return isCriticalNum(left, right, critical, arr, repeatIdx);
}

//int solve(int left, int right, int critical, vector<int>& lists) {
//    vector<int> sortedList = vector<int>(lists.begin() + left, lists.begin() + right +1);
//    sort(sortedList.begin(), sortedList.end());
//    int repeatCnt = 1;
//    int idx = 0;
//    int ret = 0;
//    while(idx < sortedList.size()) {
//        while(idx + 1 < sortedList.size() && sortedList[idx+1] == sortedList[idx]) {
//            ++idx;
//            ++repeatCnt;
//        }
//        if(repeatCnt >= critical) return sortedList[idx];
//
//        ++idx;
//        repeatCnt = 1;
//    }
//
//    return -1;
//}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        int N;
        cin >> N;
        vector<int> lists(N);
        for (int j = 0; j < N; ++j) {
            cin >> lists[j];
        }
        int C, left, right, critical;
        cin >> C;
        for (int j = 0; j < C; ++j) {
            cin >> left >> right >> critical;
            cout << solve(left, right, critical, lists) << '\n';
        }
    }
}


/*
3
6
1 1 2 2 1 1
3
0 5 4
0 3 3
2 3 2
5
1 1 2 1 1
2
0 5 4
1 3 2
5
1 2 3 4 5
1
0 5 4



 1
7
1 2 1 2 1 2 2
1
0 6 4
 * */