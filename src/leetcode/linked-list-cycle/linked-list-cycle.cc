#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/linked-list-cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *itr = head;
        const int VISITED = 98765321;
        while (itr != NULL)
        {
            if (itr->val == VISITED)
                return true;
            itr->val = VISITED;
            itr = itr->next;
        }
        return false;
    }
};
int main()
{

    return 0;
}
