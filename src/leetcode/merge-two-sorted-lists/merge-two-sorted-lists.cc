#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/merge-two-sorted-lists

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode *head)
{
    ListNode *itr = head;
    while (itr->next != nullptr)
    {
        cout << itr->val << "-> ";
        itr = itr->next;
    }
    cout << itr->val << "\n";
}
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *resultBefore = new ListNode();
        ListNode *itr = resultBefore;
        ListNode *itr1 = list1;
        ListNode *itr2 = list2;

        while (itr1 != nullptr || itr2 != nullptr)
        {
            if (itr1 != nullptr && (itr2 == nullptr || itr1->val < itr2->val))
            {
                itr->next = itr1;
                itr1 = itr1->next;
                itr = itr->next;
            }
            else
            {
                itr->next = itr2;
                itr2 = itr2->next;
                itr = itr->next;
            }
        }

        return resultBefore->next;
    }
};

int main()
{

    ListNode n4 = ListNode(4, nullptr);
    ListNode n3 = ListNode(3, &n4);
    ListNode n2 = ListNode(2, &n3);
    ListNode n1 = ListNode(1, &n2);
    ListNode nn4 = ListNode(7, nullptr);
    ListNode nn3 = ListNode(4, &nn4);
    ListNode nn2 = ListNode(1, &nn3);
    ListNode nn1 = ListNode(1, &nn2);

    printListNode(Solution().mergeTwoLists(&n1, &nn1));
    return 0;
}
