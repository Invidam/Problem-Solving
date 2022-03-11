#include <iostream>
using namespace std;

// Problem site: https://leetcode.com/problems/rotate-list
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

// class SubList {
// public: 
//     ListNode* head;
//     ListNode* tail;
    
//     ListNode* nthNode(ListNode* mainHead,int n) {
//         ListNode* itr = mainHead;
        
//         while(n--) {
//             if(!itr) break;
//             itr = itr->next;
//         }
//         return itr;
        
//     }
//     SubList(ListNode* mainHead, int from, int len) {
//         ListNode* itr = nthNode(mainHead,from);
//         ListNode* answerPrev = new ListNode();
//         ListNode* answerItr = answerPrev;
        
//         while(len--) {
//             answerItr->next = itr;
//             if(!itr) break;
//             itr = itr->next;
//             answerItr = answerItr->next;
//         }
        
//         head = answerPrev->next;
//         tail = answerItr;
//     }
// };
// class Solution {
// public:
//     int lengthOfListNode(ListNode* head) {
//         ListNode* itr = head;
//         int ret = 0;
        
//         while(itr != nullptr) {
//             ret++;
//             itr = itr->next;
//         }
//         return ret;
//     }

//     ListNode* rotateRight(ListNode* head, int k) {
//         if(head == nullptr) return head;
//         int len = lengthOfListNode(head);
//         if( k / len) return rotateRight(head, k % len);
//         else if(k == 0) return head;
        
//         SubList befRotate(head,0,len - k);
//         SubList aftRotate(head,len-k,k);
        
//         if(befRotate.tail) befRotate.tail->next = nullptr;
//         if(aftRotate.tail) aftRotate.tail->next = befRotate.head;
        
//         ListNode* answerPrev = new ListNode();
//         answerPrev->next = aftRotate.head;
        
//         return answerPrev->next;
//     }
// };


class Solution
{
public:
    int lengthOfListNode(ListNode *head)
    {
        ListNode *itr = head;
        int ret = 0;

        while (itr != nullptr)
        {
            ret++;
            itr = itr->next;
        }
        return ret;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        int len = lengthOfListNode(head);
        if (k / len)
            return rotateRight(head, k % len);
        int befRotateLen = len - k;
        ListNode *itr = head;
        ListNode *befRotatePrev = new ListNode();
        ListNode *befRotateItr = befRotatePrev;
        ListNode *aftRotatePrev = new ListNode();
        ListNode *aftRotateItr = aftRotatePrev;

        while (befRotateLen--)
        {
            befRotateItr->next = itr;
            itr = itr->next;
            befRotateItr = befRotateItr->next;
            befRotateItr->next = nullptr;
        }
        while (itr != nullptr)
        {
            aftRotateItr->next = itr;
            itr = itr->next;
            aftRotateItr = aftRotateItr->next;
            aftRotateItr->next = nullptr;
        }
        aftRotateItr->next = befRotatePrev->next;
        return aftRotatePrev->next;
    }
};
int main()
{

    return 0;
}
