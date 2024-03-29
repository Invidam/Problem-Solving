#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/add-two-numbers

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int valueOf(ListNode *node)
{
    if (node == nullptr)
        return 0;
    else
        return node->val;
}

void print_node(ListNode *node)
{
    ListNode *itr = node;
    while (itr != nullptr)
    {
        cout << itr->val << " ";
        itr = itr->next;
    }
    cout << "\n";
    return;
}
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *befAns = new ListNode();
        ListNode *itr = befAns;
        int temp = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = 0;

            if (l1 != nullptr)
                sum += l1->val;
            if (l2 != nullptr)
                sum += l2->val;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
            sum += temp;
            itr->next = new ListNode(sum % 10);
            itr = itr->next;
            temp = sum / 10;
        }
        if (temp)
            itr->next = new ListNode(temp);
        return befAns->next;
    }
};
int main()
{

    // 3947
    // 0666
    // 4613
    ListNode n4 = ListNode(3, nullptr);
    ListNode n3 = ListNode(9, &n4);
    ListNode n2 = ListNode(4, &n3);
    ListNode n1 = ListNode(7, &n2);

    ListNode _n3 = ListNode(6, nullptr);
    ListNode _n2 = ListNode(6, &_n3);
    ListNode _n1 = ListNode(6, &_n2);
    ListNode *ans = Solution().addTwoNumbers(&n1, &_n1);
    print_node(ans);
    return 0;
}
