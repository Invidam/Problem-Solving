#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    //     ListNode* deleteDuplicates(ListNode* head) {
    //        if(!head) return nullptr;
    //         else if(!head->next) return head;

    //         int val{head->val};
    //         ListNode* next{head->next};
    //         if(val != next->val) {
    //             head->next = deleteDuplicates(next);
    //         }
    //         else {
    //             while(next && next->val == val) next = next->next;
    //             head = deleteDuplicates(next);
    //         }
    //         return head;

    //     }
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *answerPrev = new ListNode(-111, head);
        ListNode *itr = head;
        ListNode *answerItr = answerPrev;
        // itr->next->val != itr->next
        while (itr != nullptr)
        {
            while (itr->next != nullptr && itr->val == itr->next->val)
            {
                ListNode *duplicate = itr;
                itr = itr->next;
                delete (duplicate);
            }
            if (answerItr->next == itr)
            {
                answerItr->next = itr;
                answerItr = answerItr->next;
            }
            itr = itr->next;
            answerItr->next = itr;
        }
        return answerPrev->next;
    }
};
int main()
{

    return 0;
}
