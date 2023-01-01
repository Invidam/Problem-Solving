
//// 10분
//#include <iostream>
//#include <vector>
//using namespace std;
//
//bool fillBoard(vector<string>& strList) {
//    vector<int> charFreq(26,0);
//    for(auto str: strList)
//        for(auto ch : str) charFreq[ch - 'a']++;
//
//    for (int i = 0; i < 26; ++i)
//        if(charFreq[i] % strList.size() != 0) return false;
//
//    return true;
//}
//
//
//int main() {
//    int N;
//    cin >> N;
//
//    vector<string> strList(N);
//    for (int i = 0; i < N; ++i)
//        cin >> strList[i];
//
//    cout << (fillBoard(strList) ? "true\n" : "false\n");
//
//
//    return 0;
//}
