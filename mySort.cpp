#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> p;
template <typename T>
void print_vector(vector<T>& arr) {
    for(auto& elem: arr)
        cout << elem << ' ';
    cout << '\n';
}

template <typename T>
bool cmp(T a, T b) {
    return a < b;
}
template <typename T>
void mySort(vector<T>& arr,int from,int to) {
    int mid = (from + to)/2, N = to-from;
    if(N == 1) return;
    //변경된 값들을 저장할 배열
    vector<T> tmp(N);
    //앞쪽에 대해 실행
    mySort(arr,from,mid);
    //뒤쪽에 대해 실행
    mySort(arr,mid,to);
    int idx1= from, idx2= mid;
    //변경된 값들을 저장
    for(int i = from;i<to;++i) {
        if(idx2 >= to || (idx1 < mid && cmp(arr[idx1],arr[idx2])))
            tmp[i - from] = arr[idx1++];
        else
            tmp[i - from] = arr[idx2++];
    }
    //변경된 값들을 집어넣는다.
    for(int i=from;i<to;++i)
        arr[i] = tmp[i-from];
}

//인자로 주어진 arr를 reverse해 리턴.
template <typename T>
void myReverse(vector<T>& arr,int from,int to) {
    int N = to - from;
    vector<T> tmp(N);
    for(int i=0;i<N;++i)
        tmp[N-1-i] = arr[i];
    arr =tmp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {4,47,34,12,99,3,51};
    mySort(arr,0,arr.size());
    print_vector(arr);

    vector<string> arr2 = {"abcdef","abc","qwer","gggggg"};
    mySort(arr2,0,arr2.size());
    print_vector(arr2);

    // vector<p> arr3 = {p(1,2),p(6,2),p(3,3),p(3,1),p(8,8)};
    // mySort(arr3,0,arr3.size());
    // // print_vector(arr3);
    // for(auto& elem: arr3)
    //     cout << elem.first << elem.second << '\n';

    myReverse(arr2,0,arr2.size());
    print_vector(arr2);

}