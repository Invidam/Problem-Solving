#include <iostream>
#include <vector>
#include <stack>

// Problem site: https://leetcode.com/problems/validate-stack-sequences
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int pushIdx = 0, popIdx = 0;
        stack<int> st;
        while (pushIdx < pushed.size() && popIdx < popped.size())
        {
            st.push(pushed[pushIdx]);
            while (popIdx < popped.size() && !st.empty() && st.top() == popped[popIdx])
            {
                popIdx++;
                st.pop();
            }

            pushIdx++;
        }
        return st.empty();
    }
};

int main()
{

    return 0;
}
