#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool cmp(vector<string>& a, vector<string>& b) {
    int n1 = stoi(a[1]), n2 = stoi(b[1]);
    if(n1 == n2)
        return true;
    return n1 > n2;
}
vector<vector<string>> solution(vector<string> lists) {
    //해당 파일이 나온 횟수를 기록
    unordered_map<string,int> cnt;
    //파일 나온 횟수  를 저장
    vector<vector<string>> answer;
    //list를 돌며 파일명.확장자 형태로 저장
    for(auto& elem: lists) {
        //~~/~~/~~/a.x -> x.a/~~/~~/~~로 변환
        reverse(elem.begin(),elem.end());
        //x.1v_a 형태일 경우
        if(elem[3] == 'v') {
            //1v_를 지운다.
            elem.erase(elem.begin()+2,elem.begin()+5);
            cout << "eraseed " << elem << '\n';
        }
        //x.a만 남기고 다시 reverse 한다.
        elem = elem.substr(0,3);
        reverse(elem.begin(),elem.end());
        cout << "elem: " << elem << '\n';
        //cnt에 빈도수를 저장
        cnt[elem]++;
    }
    //answer에 파일명 빈도수 형태로 저장
    for(auto& elem : cnt) {
        answer.push_back(vector<string>{elem.first,to_string(elem.second)});
    }
    //빈도수가 높은 순 그리고 파일명이 사전순으로 정렬
    sort(answer.begin(),answer.end(),cmp);
    return answer;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> lists = {
         "/a/b/c/a.x" , "c.b" , "a/c.b" , "a/b/c.b" , "/z/a.x" , "a.a" , "k/x.a, /a/b/c/a/a_v1.x",
         "c/b_v1.o", "a/b/c/b_v2.o"
         };
    vector<vector<string>> answer = solution(lists);
    for(auto& elem: answer) {
        cout << elem[0] << " " << elem[1] << '\n';
    }
                         
}