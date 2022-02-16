#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/single-number

class Solution {
public:
    int answrSingleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<nums.size();++i) {
            result ^= nums[i];
        }
        return result;
    }
    int mySingleNumber(vector<int>& nums) {
        int MAX  = 3*1e4;
        int RANGE = 2*MAX + 1;
        vector<int> cnt(RANGE,0);
        vector<int> circuit(0);

        for(int i=0;i<nums.size();++i) {
            int value = nums[i];
            int cntIdx = value + MAX;

            if(cnt[cntIdx] == 0) circuit.push_back(value);

            cnt[cntIdx]++;
        }
        for(int i=0;i<circuit.size();++i) {
            int value = circuit[i];
            int cntIdx = value + MAX;

            if(cnt[cntIdx] == 1) return value;
        }
        
    }
};
int main() {
    // freopen("input.txt", "r", stdin);
    vector<int> arr = {1};
    cout << Solution().mySingleNumber(arr);
    return 0;
}