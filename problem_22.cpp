#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//str에 해당하는 byte를 리턴
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

//str에 해당하는 출력값을 리턴
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
        return "################";

}
string solution(vector<string> lists) {
    //답변 저장
    string answer;
    //하나의 타입을  elem으로 받는다.
    for(auto& elem: lists) {
        int typeByte = getTypeSize(elem);
        int sizingByte = typeByte == 16 ? 8 : typeByte;
        /*
        1~8 byte까지는 idx% byte 가 0이어야 할당함
        16일 때는 idx % 8 == 0이면 할당함.
        할당하지 않으면 할당할때 까지 .을 채움
        */
        while(answer.size() % sizingByte != 0)
            answer+= ".";
        answer += getString(elem);
    }
    /*
    모든 list를 처리했음에도, 8바이트로 마무리가 안되었다면 .을 붙여 마무리
    */
    while(answer.size() % 8 != 0)
        answer+= ".";
    // 크기 넘으면 예외
    if(answer.size() > 128) return "HALT";
    //8바이트마다 ,을 붙인 string을 선언
    string answerPlusDot;
    for(int i=0;i<answer.size();++i) {
        answerPlusDot.push_back(answer[i]);
        if(i% 8 == 7) answerPlusDot.push_back(',');
    }
    //맨 마지막에 붙었을 경우 떼내고 리턴.
    if(answerPlusDot.back() == ',') answerPlusDot.pop_back();
    return answerPlusDot;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string answer;
    vector<vector<string>> lists = {{"INT", "INT", "BOOL", "SHORT", "LONG"},
                                   {"INT", "SHORT", "FLOAT", "INT", "BOOL"},
                                   {"FLOAT", "SHORT", "BOOL", "BOOL", "BOOL", "INT"},
                                   {"BOOL", "LONG", "SHORT", "LONG", "BOOL", "LONG", "BOOL", "LONG", "SHORT", "LONG", "LONG"},
                                    };
    for(int i=0;i<lists.size();++i) {           
        answer = solution(lists[i]);
        cout <<answer << '\n';
    }
                         
}