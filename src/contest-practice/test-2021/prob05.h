//#include <iostream>
//#include <vector>
//#include <utility>
//using namespace std;
//typedef pair<int, int> p;
//
////char board[10][10];
//vector<vector<char>> board(9,vector<char>(9,'.'));
//char START_CHAR = 'A';
//char EMPTY_CHAR = '.';
//void printBoard() {
//    for (int i = 0; i < 9; ++i) {
//        for (int j = 0; j < 9; ++j) {
//            cout << board[i][j];
//            if(j != 8) cout << ' ';
//        }
//        if(i != 8) cout << '\n';
//    }
//}
//
//bool isValid(int r, int c) {
//    char ch = board[r][c];
//    for(int i=0;i<9;++i) {
//        if(i == c) continue;
//        if(board[r][i] == ch) return false;
//    }
//    for(int i=0;i<9;++i) {
//        if(i == r) continue;
//        if(board[i][c] == ch) return false;
//    }
//    for(int i=(r - r%3);i<(r - r%3) + 3;++i) {
//        for (int j = (c - c%3); j < (c - c%3) + 3; ++j) {
//            if(i == r && j == c) continue;
//            if(board[i][j] == ch) return false;
//        }
//    }
//    return true;
//}
//
//bool fillBoard(int idx, vector<p>& emptyList) {
//    if(idx == emptyList.size()) {
//        printBoard();
//        return true;
//    }
//    int r =emptyList[idx].first;
//    int c = emptyList[idx].second;
//
//    for (int i = 0; i < 9; ++i) {
//        board[r][c] =  START_CHAR + i;
//        if(isValid(r,c)) {
//            if(fillBoard(idx+1, emptyList)) return true;
//        }
//        board[r][c] = EMPTY_CHAR;
//    }
//    board[r][c] = EMPTY_CHAR;
//    return false;
//}
//
//int main() {
//    vector<p> emptyList;
//    for (int i = 0; i < 9; ++i) {
//        for (int j = 0; j < 9; ++j) {
//            cin >> board[i][j];
//            if(board[i][j] == EMPTY_CHAR) emptyList.push_back(p(i,j));
//        }
//    }
//    fillBoard(0, emptyList);
//}
///*
//G C B I E F D H .
//I E F D H A G C .
//D H A G C B I E .
//C G I B F E H A .
//B F E H A D C G .
//H A D C G I B F .
//E B G F I C A D .
//F I C A D H E B .
//A D H E B G F I .
//
//. C B I E F D H A
//I E F D H A G C B
//D H A G C B I E F
//C G I B F E H A D
//B F E H A D C G I
//H A D C G I B F E
//E B G F I C A D H
//F I C A D H E B G
//A D H E B G F I .
//
//
// *
// */