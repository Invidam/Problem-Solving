//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int solve(vector<int>& expected, vector<int>& order) {
//    if(order[0] == 1) {
//        toChange[order[1]] = order[2];
//        return -1;
//    }
//    else {
//        return expected[order[2]] ^ (order[1] == 0 ? 0 : expected[order[1]-1]);
//    }
//}
//int main() {
//    int TC;
//    cin >> TC;
//    for (int i = 0; i < TC; ++i) {
//        int N,M;
//        cin >> N;
//        vector<int> expected(N);
//        vector<int> toChange(N,0);
//        for (int j = 0; j < N; ++j) {
//            int n;
//            cin >> n;
//            if(j == 0 ) expected[j] = n;
//            else expected[j] = expected[j-1] ^ n;
//        }
//        for (int j = 0; j < N; ++j) {
//            if(j == 0 ) expected[j] = 0;
//            else expected[j] = expected[j-1] ^ 0;
//        }
//        cin >> M;
//        for (int j = 0; j < M; ++j) {
//            vector<int> order(3);
//            cin >> order[0] >> order[1] >> order[2];
//            int ret = solve(expected, order);
//            if (order[0] != 1) cout << ret << '\n';
//        }
//    }
//
//}