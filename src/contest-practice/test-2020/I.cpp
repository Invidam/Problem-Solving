//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//string solve(string& str) {
//    queue<int> q;
//    string ret = str;
//    for(int i=0;i<str.length();++i)
//        if(str[i] != '.') q.push(i);
//    while(!q.empty()) {
//        int qSize = q.size();
//        for (int i = 0; i < qSize; ++i) {
//
//            int frontIdx = q.front();
//            char& frontCh = str[frontIdx];
//            q.pop();
//
//            if(frontCh == 'L') {
//                if(0 <= frontIdx -1 && str[frontIdx-1] == '.') {
//                    if(0 <= (frontIdx -2)  && str[frontIdx-2] == 'R') continue;
//                    --frontIdx;
//                    ret[frontIdx] = 'L';
//                    q.push(frontIdx);
//                }
//            }
//            else {
//                if(frontIdx +1 < str.length() && str[frontIdx+1] == '.') {
//                    if((frontIdx +2) < str.length()  && str[frontIdx + 2] == 'L') continue;
//                    ++frontIdx;
//                    ret[frontIdx] = 'R';
//                    q.push(frontIdx);
//                }
//            }
//        }
//        str = ret;
//    }
//    return ret;
//}
//int main() {
//    int TC;
//    cin >> TC;
//    for (int i = 0; i < TC; ++i) {
//        string str;
//        cin >> str;
//
//        cout << solve(str) << '\n';
//    }
//
//}