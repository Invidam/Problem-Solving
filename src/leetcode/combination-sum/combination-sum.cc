#include <iostream>
#include <vector>
using namespace std;

// Problem site: https://leetcode.com/problems/combination-sum

void print_vector_div2(vector<vector<int>> &vector_div2)
{
    cout << "[";
    for (auto line : vector_div2)
    {
        cout << "[";
        for (auto elem : line)
            cout << elem << " ";
        cout << "]";
    }

    cout << "]";
}
vector<vector<int>> answer;
vector<int> cand;
vector<vector<int>> cacheArr[31][501];
int cache[31][501];

void combineVector(vector<vector<int>> &target, const vector<vector<int>> &toAdd)
{
    target.insert(target.end(), toAdd.begin(), toAdd.end());
}

vector<vector<int>> cacheValue(int i, int j) { return cacheArr[i][j]; }

vector<vector<int>> combineElemToVector(int elem, const vector<vector<int>> &v)
{

    vector<vector<int>> result;
    for (auto arr : v)
    {
        vector<int> temp = arr;
        temp.insert(temp.begin(), 1, elem);
        result.push_back(temp);
    }
    return result;
}
bool isValid(int idx, int target)
{
    return idx >= cand.size() || target < 0 || cache[idx][target] == -1;
}
bool combinationSumFor(int idx, int target)
{
    if (isValid(idx, target))
        return false;
    if (target == 0)
    {
        cache[idx][target] = 1;
        cacheArr[idx][target] = vector<vector<int>>({{}});
        return true;
    }
    else if (cache[idx][target] == 1)
        return true;

    vector<vector<int>> result;
    if (combinationSumFor(idx, target - cand[idx]))
        combineVector(result, combineElemToVector(cand[idx], cacheValue(idx, target - cand[idx])));
    if (combinationSumFor(idx + 1, target))
        combineVector(result, cacheValue(idx + 1, target));

    if (result.size() == 0)
    {
        cache[idx][target] = -1;
        return false;
    }
    else
    {
        cache[idx][target] = 1;
        cacheArr[idx][target] = result;
        return true;
    }
}
void init()
{
    for (int i = 0; i < 31; ++i)
        for (int j = 0; j < 501; ++j)
            cache[i][j] = 0;
}
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        cand = candidates;
        init();
        if (combinationSumFor(0, target))
            return cacheValue(0, target);
        else
            return vector<vector<int>>{};
    }
};
int main()
{
    vector<int> _cand = {1, 2, 3};
    auto result = Solution().combinationSum(_cand, 6);
    cout << "ANSWER: \n";
    print_vector_div2(result);
    return 0;
}
