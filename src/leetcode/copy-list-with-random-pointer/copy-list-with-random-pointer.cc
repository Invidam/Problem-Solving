#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        vector<Node *> arr(1001);
        unordered_map<Node *, int> storage;
        int idx = 0;
        Node *answerPrev = new Node(-999999);
        Node *itr = head;
        Node *copiedItr = answerPrev;
        while (itr)
        {
            copiedItr->next = new Node(itr->val);

            arr[idx] = copiedItr->next;
            storage[itr] = idx;
            copiedItr = copiedItr->next;

            copiedItr->next = NULL;
            itr = itr->next;
            idx++;
        }
        itr = head;
        copiedItr = answerPrev;
        while (itr)
        {
            copiedItr->next->random = itr->random ? arr[storage[itr->random]] : NULL;
            copiedItr = copiedItr->next;
            itr = itr->next;
        }

        return answerPrev->next;
    }
};
// Problem site: https://leetcode.com/problems/copy-list-with-random-pointer

int main()
{

    return 0;
}
