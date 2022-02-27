#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Problem site: https://leetcode.com/problems/maximum-width-of-binary-tree

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        int ret = 1;

        while (!q.empty())
        {
            int qSize = q.size();
            int start = q.front().second;
            int end = q.back().second;
            int cand = end - start + 1;
            ret = ret > cand ? ret : cand;
            for (int i = 0; i < qSize; ++i)
            {
                pair<TreeNode *, int> p = q.front();

                int idx = p.second - start;

                q.pop();

                if (p.first->left != NULL)
                {
                    q.push({p.first->left, (long long)2 * idx + 1});
                }
                if (p.first->right != NULL)
                {
                    q.push({p.first->right, (long long)2 * idx + 2});
                }
            }
        }
        return ret;
    }
};
int main()
{

    return 0;
}
