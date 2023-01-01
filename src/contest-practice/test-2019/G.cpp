#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>


using namespace std;
bool canExpand(int K, unordered_map<int, int> &m, int elem) { return !(m.find(elem) == m.end() && m.size() == K); }

int solve(int N, int K, vector<int>& arr) {
    unordered_map<int, int > m;
    int startIdx = 0, idx = 0;
    int ret = 0;
    while (idx < N) {
        int elem = arr[idx];
        if(!canExpand(K, m, elem)) break;
        ++idx;
        ++m[elem];
        if(m.size() ==  K) ++ret;
    }
    if (m.size() < K) return 0;
    while (1) {
        if(idx < N && canExpand(K, m, arr[idx])) {
            if(idx >= N) break;
            int elem = arr[idx++];
            ++m[elem];
        }
        else {
            if(startIdx >= idx) break;
            int elem = arr[startIdx++];
            --m[elem];
            if (m[elem] == 0) m.erase(elem);
        }
        if(m.size() == K) ++ret;
    }
//    while (idx < N) {
//        int elem = arr[idx++];
//        if (m.find(elem) != m.end()) ++ret;
//    }
/*
1
6
1 1 2 3 3 2
2
 1 1 2
 1 2
 2 3
 2 3 3
 2 3 3 2
 3 3 2
 3 2

*/
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }
        int K;
        cin >> K;
        cout << solve(N,K,arr) << '\n';
    }
}



/*
3
6
1 1 2 2 1 1
3
0 5 4
0 3 3
2 3 2
5
1 1 2 1 1
2
0 5 4
1 3 2
5
1 2 3 4 5
1
0 5 4



 1
7
1 2 1 2 1 2 2
1
0 6 4
 * */