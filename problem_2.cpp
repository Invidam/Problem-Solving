#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int getTypeSize(string& str) {
    if(str[0] == 'B')
        return 1;
    else if(str[0] == 'S')
        return 2;
    else if(str[0] =='F')
        return 4;
    else if(str[0] == 'I')
        return 8;
    else 
        return 16;
}
string getString(string& str) {
    if(str[0] == 'B')
        return "#";
    else if(str[0] == 'S')
        return "##";
    else if(str[0] =='F')
        return "####";
    else if(str[0] == 'I')
        return "########";
    else 
        return "########,########";

}

string solution(vector<string> lists) {
    string answer;
    //answerIdx : ㅈ
    int answerIdx = 0,listsIdx =0, N = lists.size();
    while(answerIdx < 128) {
        if(listsIdx >= N) break;
        string str = lists[listsIdx++];
        int byteIdx = answerIdx % 8, typeSize = getTypeSize(str);

        while((typeSize == 16 && byteIdx % 8 != 0)||(byteIdx % typeSize != 0)) {
            answerIdx++;
            answer.push_back('.');
            byteIdx = answerIdx % 8;
            if(answerIdx % 8 ==0)
                answer += ',';
        }
        answer += getString(str);
        answerIdx += typeSize;
        if(answerIdx % 8 ==0)
            answer += ',';
    }
    while(answerIdx % 8 != 0) {
        answerIdx++;
        answer.push_back('.');
        if(answerIdx % 8 ==0)
            answer += ',';
    }
    if(answer.back() == ',')
        answer.pop_back();
    if(answerIdx > 128 || listsIdx != N)
        return "ERR";
    return answer;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string answer;
    vector<vector<string>> lists = {{"BOOL","FLOAT"},
                                   {"INT", "SHORT", "FLOAT", "INT", "BOOL"},
                                   {"FLOAT", "SHORT", "BOOL", "BOOL", "BOOL", "INT"},
                                   {"BOOL", "LONG", "SHORT", "LONG", "BOOL", "LONG", "BOOL", "LONG", "SHORT", "LONG", "LONG"},
                                    };
    for(int i=0;i<lists.size();++i) {           
        answer = solution(lists[i]);
        cout <<answer << '\n';
        
    }
                         
}