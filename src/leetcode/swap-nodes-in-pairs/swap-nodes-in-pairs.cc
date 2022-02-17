
#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *tmp = head->next;
        head->next = swapPairs(head->next->next);
        tmp->next = head;
    }
};
int main()
{
    // freopen("input.txt", "r", stdin);
    // ListNode n6 = ListNode(6, nullptr);
    // ListNode n5 = ListNode(5, nullptr);
    ListNode n4 = ListNode(4, nullptr);
    ListNode n3 = ListNode(3, &n4);
    ListNode n2 = ListNode(2, &n3);
    ListNode n1 = ListNode(1, &n2);
    // ListNode *head = &ListNode(1, &ListNode(2, ));
    printListNode(Solution().swapPairs(&n1));
    return 0;
}

/*
1 2 3 4

1 -> 2
2 -> 3
3 -> 4
4- > n

1 -> 2
2 -> 3
3 -> 4
4- > n

1 -> 2
2 -> 3
3 -> n
4- > 3

1 ->
2 ->
3 ->
4- >

1 ->
2 ->
3 ->
4- >

1 ->
2 ->
3 ->
4- >

1 ->
2 ->
3 ->
4- >

1 ->
2 ->
3 -> n
4- > 3

1 ->
2 ->
3 ->
4- >
2 1 4 3

1 2 3
2 1 3

1 2
2 1

odd
this ->
pair
this -> before
1

1

[]
[]

*/

// my solution
//  #include <iostream>
//  using namespace std;

// // Problem site: https://leetcode.com/problems/swap-nodes-in-pairs

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// void printListNode(ListNode *head)
// {
//     ListNode *itr = head;
//     while (itr->next != nullptr)
//     {
//         cout << itr->val << "-> ";
//         itr = itr->next;
//     }
//     cout << itr->val << "\n";
// }
// void swap(ListNode *itr)
// {
//     ListNode *prev = itr, *curr1 = itr->next, *curr2 = itr->next->next, *next = itr->next->next->next;
//     curr1->next = next;
//     prev->next = curr2;
//     curr2->next = curr1;
// }
// class Solution
// {
// public:
//     ListNode *swapPairs(ListNode *head)
//     {
//         ListNode resultBefore(0, head);
//         ListNode *prev = &resultBefore;
//         ListNode *itr = &resultBefore;
//         printListNode(itr);
//         while (1)
//         {
//             if (itr != nullptr && itr->next != nullptr && itr->next->next != nullptr)
//                 swap(itr);
//             else
//                 break;
//             itr = itr->next->next;
//         }
//         return prev->next;
//     }
// };
// int main()
// {
//     // freopen("input.txt", "r", stdin);
//     // ListNode n6 = ListNode(6, nullptr);
//     // ListNode n5 = ListNode(5, nullptr);
//     // ListNode n4 = ListNode(4, &n5);
//     // ListNode n3 = ListNode(3, nullptr);
//     // ListNode n2 = ListNode(2, &n3);
//     ListNode n1 = ListNode(1, nullptr);
//     // ListNode *head = &ListNode(1, &ListNode(2, ));
//     printListNode(Solution().swapPairs(&n1));
//     return 0;
// }

// /*
// 1 2 3 4

// 1 -> 2
// 2 -> 3
// 3 -> 4
// 4- > n

// 1 -> 2
// 2 -> 3
// 3 -> 4
// 4- > n

// 1 -> 2
// 2 -> 3
// 3 -> n
// 4- > 3

// 1 ->
// 2 ->
// 3 ->
// 4- >

// 1 ->
// 2 ->
// 3 ->
// 4- >

// 1 ->
// 2 ->
// 3 ->
// 4- >

// 1 ->
// 2 ->
// 3 ->
// 4- >

// 1 ->
// 2 ->
// 3 -> n
// 4- > 3

// 1 ->
// 2 ->
// 3 ->
// 4- >
// 2 1 4 3

// 1 2 3
// 2 1 3

// 1 2
// 2 1

// odd
// this ->
// pair
// this -> before
// 1

// 1

// []
// []

// */