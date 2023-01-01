//#include <iostream>
//#include <vector>
//using namespace std;
//typedef long long ll;
//vector<ll> arr;
//
//int N,M,K;
//ll SIZE;
//void setSize() {
//    SIZE = 1;
//    while(SIZE < N) SIZE = SIZE << 1;
//}
//void construct(vector<ll>& inputs) {
//    setSize(); // 입력 k에 대해, 이보다 큰 제곱 수들 중 최소인 n을 설정
//    arr = vector<ll>(2*SIZE, 0); // 그 n의 2배만큼 배열을 설정
//
//    for (int i = 0; i < inputs.size(); ++i) {
//        arr[i + SIZE] = inputs[i]; // 배열의 [n,2n-1] 까지 초기값 지정
//    }
//    for(int i= SIZE-1; i > 0;--i) { //거꾸로 순회함.
//        arr[i] = arr[2*i] + arr[2*i+1]; // 부분 합을 적용한 로직
//    }
//}
//void update(int idx, ll val) {
//    arr[SIZE + idx] = val; // 해당 위치의 값 변경
//
//    for(int i= SIZE + idx >> 1; i > 0;i/=2)
//        arr[i] = arr[2*i] + arr[2*i+1]; // 해당 부분을 포함한 모든 값들을 갱신
//}
//// L, R 찾아야 하는 범위
//// nldeL, nodeR : 현재 검색중인 범위
//// nodeVal : 검색 범위가 찾아야 하는 범위 안에 있을 때 반환하기 위한 인덱스 (트리로썬 깊이, 배열로썬 인덱스)
//// ㄴ [0,3]을 찾는다고 하면, [0,1]과 [3,3]을 반환해야 한다. [0,1]은 1*2에 속하고, [3,3]은 1*(2+1)*2에 속한다.
//// [0, 3]       1
//// [0,1][2,3]   2, 3
//// [0][1][2][3] 4 , 5 , 6 , 7
//// 호출 예시 sum(FROM,TO,1{DEFAULT},0,arr.size()-1)
//ll sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
//    if(R < nodeL || nodeR < L ) return 0;
//    else if  (L <= nodeL && nodeR <= R) return arr[nodeNum];
//    int mid = nodeL + nodeR >> 1;
//    return sum(L, R, nodeNum * 2, nodeL, mid) + sum(L, R, 2 * nodeNum + 1, mid+1, nodeR);
//}
//
//
//
//void solve(vector<ll> &arr, vector<ll> &query) {
//    if(query[0] == 1) {
//        update(query[1] - 1, query[2]);
//    }
//    else {
//        cout << sum(query[1]-1, query[2]-1, 1, 0, SIZE - 1) << '\n';
//    }
//}
//
//int main() {
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> N >> M >> K;
//    vector<ll> inputs(N);
//    for (int i = 0; i < N; ++i) {
//        cin >> inputs[i];
//    }
//    construct(inputs);
//    for (int i = 0; i < M+K; ++i) {
//        ll a,b,c;
//        cin >> a >> b >> c;
//        vector<ll> query = vector<ll>{a, b, c};
//        solve(arr,query);
//    }
//
//    return 0;
//}
