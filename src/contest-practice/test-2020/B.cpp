//#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <algorithm>
//
//using namespace std;
//
//void getInput(string& input) {
//    cin >> input;
//    if(input[0] == 'H') {
//        char ch1,ch2,ch3;
//        cin >> ch1 >> ch2 >> ch3;
//        input.push_back(ch1);
//        input.push_back(ch2);
//        input.push_back(ch3);
//        sort(input.begin() + 1, input.end());
//    }
//}
//
//bool solve(int cnt, string& input, vector<string>& cards, vector<int>& points,  unordered_set<string>& combo) {
//    //input:  H123 or T or G
//    int& point = points[cnt % 2];
//    switch (input[0]) {
//        case 'T': break;
//        case 'G': {
//            if(combo.empty()) {
//                point += 3;
//                return true;
//            }
//            else
//                point += ((point == 0) ? 0 : -1);
//            break;
//        }
//        case 'H': {
//            string cand = input.substr(1);
//            if(combo.find(cand) != combo.end()) {
//                combo.erase(cand);
//                point += 1;
//            }
//            else point +=(( point == 0 )? 0 : -1);
//            break;
//        }
//        default: break;
//    }
//    return false;
//}
//bool isValid(vector<string>& cards,  vector<int>& selected ) {
//    string cand[3] = {cards[selected[0]],cards[selected[1]],cards[selected[2]]};
//    for (int i = 0; i < 3; ++i) {
//        if(!(cand[0][i] == cand[1][i] && cand[1][i] == cand[2][i]) && !((cand[0][i] != cand[1][i] && cand[1][i]  != cand[2][i] && cand[2][i]  != cand[0][i]))) return false;
//    }
//    return true;
//}
//void selectCombo(int idx,vector<string>& cards,  vector<int>& selected, unordered_set<string>& combo) {
//    if(selected.size() == 3) {
//        if(!isValid(cards,selected)) return;
//        string ret = "";
//        ret.push_back('1' + selected[0]);
//        ret.push_back('1' + selected[1]);
//        ret.push_back('1' + selected[2]);
//        combo.insert(ret);
//        return;
//    }
//    if(idx >= cards.size()) return;
//
//    selected.push_back(idx);
//    selectCombo(idx+1,cards, selected,combo);
//    selected.pop_back();
//
//    selectCombo(idx+1,cards, selected,combo);
//
//}
//void fillCombo(vector<string>& cards, unordered_set<string>& combo) {
//    vector<int> selected;
//    selectCombo(0,cards, selected,combo);
//}
//int main() {
//    int TC;
//    cin >> TC;
//    for (int i = 0; i < TC; ++i) {
//        vector<string> cards(9,"AAA");
//        unordered_set<string> combo;
//        vector<int> points(2,0);
//        for (int j = 0; j < 9; ++j) {
//            cin >> cards[j][0] >> cards[j][1] >> cards[j][2];
//        }
//        fillCombo(cards, combo);
//        int cnt = 0;
//        while(1) {
//            string input = "";
//            getInput(input);
//            if(solve(cnt, input,cards,points,combo)) {
//                cout << points[0] << ' ' << points[1] << '\n';
//                break;
//            }
//            cnt++;
//        }
//    }
//
//}