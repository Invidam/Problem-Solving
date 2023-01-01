//// 50 분
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <utility>
//using namespace std;
//typedef pair<int ,int> p;
//bool visited[51][51];
//int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
//
//bool isBacking(int walkCnt) {return walkCnt % 3 == 2;}
//
//bool isValid(int walkCnt,int N, p coord, vector<vector<int>>& arr) {
////    return !(isBacking(walkCnt) ^ visited[coord.first][coord.second]) && (coord.first >= 0 && coord.first < N && coord.second >= 0 && coord.second < N ) && (arr[coord.first][coord.second]);
//    return (coord.first >= 0 && coord.first < N && coord.second >= 0 && coord.second < N ) && (arr[coord.first][coord.second]) && !visited[coord.first][coord.second];
//}
//
////1 : 1
////2 : 2
////3 : 5 / 1 : 3
////4 : 8 / 2 : 6
////5 : 11/ 3 : 9
////6 : 14/ 4 : 12
////7 : 17
////
////
////
////3걸음 가는데 5가 소모
////1111111
//int solve(int N, vector<vector<int>>& arr) {
//    if(N == 1) return arr[0][0] == 1 ? 0 : -1;
//    if(!arr[0][0]) return -1;
//
//    int walkCnt{0};
//
//    visited[0][0] = true;
//    queue<p> q;
//    q.push(p(0,0));
//
//    while(!q.empty()) {
//        int qSize = q.size();
//        for (int i = 0; i < qSize; ++i) {
//            p curr = q.front();
//            q.pop();
//            for (int j = 0; j < 4; ++j) {
//                p next = p(curr.first + offset[j][0], curr.second + offset[j][1]);
//                if(!isValid(walkCnt,N,next, arr)) continue;
//
//                if(next.first == N -1 && next.second == N -1) return 2 + (walkCnt - 1) * 3;
//
//                q.push(next);
//                visited[next.first][next.second] = true;
//            }
//        }
//        walkCnt++;
//    }
//
//    return -1;
//}
//
//
//int main() {
//    int N;
//    cin >> N;
//
//    vector<vector<int>> arr(51,vector<int>(51,0));
//    for (int i = 0; i < N; ++i)
//        for (int j = 0; j < N; ++j)
//            cin >> arr[i][j];
//
//    cout << solve(N,arr);
//
//    return 0;
//}
//
//
///*
// *
// *
//4
// 1 1 1 1
// 0 1 0 1
// 1 1 0 1
// 1 1 1 1
//
//3
// 1 1 1
// 1 1 1
// 1 1 1
//12
// 32걸음
//
//5
// 1 1 1 1 1
// 0 0 1 0 1
// 1 1 1 0 1
// 1 0 0 0 0
// 1 1 1 1 1
//
// * */