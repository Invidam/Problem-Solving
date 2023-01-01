#include <iostream>
#include <vector>

using namespace std;

vector<int> getParticularMatch(const string &N) {
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            ++matched;

            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0) ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}
vector<int> kmpSearch(const string &H, const string &N) {
    vector<int> ret;
    vector<int> pi = getParticularMatch(N);
    int n = H.length(), m = N.length(), begin = 0, matched = 0;

    while (begin + m <= n) {
        if (matched < m && H[begin + matched] == N[matched]) {
            ++matched;

            if (matched == m) ret.push_back(begin);
        } else {
            if (matched == 0) ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

vector<int> getPrefixSuffix(const string &S) {
    vector<int> ret;
    vector<int> pi = getParticularMatch(S);
    int k = S.length();
    while(k > 0) {
        ret.push_back(k);

        k = pi[k-1];
    }
    return ret;
}
void solve(const string &S) {
    vector<int> ret = getPrefixSuffix(S);
    for (int i=0;i<ret.size();++i) {
        cout << ret[ret.size()-i-1] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string father, mother;
    cin >> father;
    cin >> mother;
    string S = father + mother;
    solve(S);
    return 0;
}