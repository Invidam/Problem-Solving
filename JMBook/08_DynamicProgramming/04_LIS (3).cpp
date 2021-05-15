#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[502],cache[502][502],N;
//cache[n][n] = 45ms / cache[n] + for(n) : 12ms
//last까지 선택하였을 때, from에서부터의 길이를 리턴
int LIS(int last, int from)
{
	if(last >= N || from >= N) return 0;
	
	int& ret = cache[last+1][from];
	if(ret != -1) return ret;
	
	if(last == -1 || arr[from] > arr[last])
		ret = LIS(from,from+1)+1;
	
	return ret = max(ret,LIS(last,from+1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	cin >> TC;
	while(TC--)
	{
		cin >> N;
		memset(cache,-1,sizeof(cache));
		
		for(int i=0;i<N;++i)
				cin >> arr[i];
		
		cout << LIS(-1,0) << '\n';
		
	}
}

/*
종만북 소스코드(실제 수열을 계산하는 코드가 날라감..)
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lis(const vector<int>& A) {
	// 기저 사례: A 가 텅 비어 있을 때
	if(A.empty()) return 0;
	int ret = 0;
	for(int i = 0; i < A.size(); ++i) {
		vector<int> B;
		for(int j = i+1; j < A.size(); ++j)
			if(A[i] < A[j])
				B.push_back(A[j]);
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

int n;
int cache[101], S[100], choices[101];

// S[start] 에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다
int lis2(int start) {
	int& ret = cache[start];
	if(ret != -1) return ret;
	// 항상 S[start] 는 있기 때문에 길이는 최하 1
	ret = 1;
	for(int next = start+1; next < n; ++next)
		if(S[start] < S[next])
			ret = max(ret, lis2(next) + 1);
	return ret;
}

// S[start] 에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다
int lis3(int start) {
	int& ret = cache[start+1];
	if(ret != -1) return ret;
	// 항상 S[start] 는 있기 때문에 길이는 최하 1
	ret = 1;
	for(int next = start+1; next < n; ++next)
		if(start == -1 || S[start] < S[next])
			ret = max(ret, lis3(next) + 1);
	return ret;
}

// S[start] 에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다
int lis4(int start) {
	int& ret = cache[start+1];
	if(ret != -1) return ret;
	// 항상 S[start] 는 있기 때문에 길이는 최하 1
	ret = 1;
	int bestNext = -1;
	for(int next = start+1; next < n; ++next)
		if(start == -1 || S[start] < S[next]) {
			int cand = lis4(next) + 1;
			if(cand > ret) {
				ret = cand;
				bestNext = next;
			}
		}
	choices[start+1] = bestNext;
	return ret;
}

// S[start] 에서 시작하는 LIS 를 seq 에 저장한다
void reconstruct(int start, vector<int>& seq) {
	if(start != -1) seq.push_back(S[start]);
	int next = choices[start+1];
	if(next != -1) reconstruct(next, seq);
}

int main() {
    int cases;
    cin >> cases;
    for(int cc = 0; cc < cases; ++cc) {
    	cin >> n;
    	vector<int> A(n);
    	for(int i = 0; i < n; i++) {
    		cin >> A[i];
    		S[i] = A[i];
    	}
    	memset(cache, -1, sizeof(cache));
    	cout << lis4(-1)-1 << endl;
    	vector<int> seq;
    	reconstruct(-1, seq);
    	for(int i = 0; i < seq.size(); ++i)
    		cout << seq[i] << " ";
    	cout << endl;

    }
}


*/