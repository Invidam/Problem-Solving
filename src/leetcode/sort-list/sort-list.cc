#include <iostream>
#include <vector>

using namespace std;

// Problem site: https://leetcode.com/problems/sort-list
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getNodeLength(ListNode *head)
{
    if (head == nullptr)
        return 0;
    int ret = 1;
    ListNode *itr = head;
    while (itr->next != nullptr)
    {
        itr = itr->next;
        ret++;
    }
    return ret;
}
ListNode *increaseIterator(ListNode *itr, int value)
{
    while (value--)
    {
        if (itr == nullptr)
        {
            cout << "\n\n\n\nERR\n\n\n\n\n\n";
        }
        itr = itr->next;
    }
    return itr;
}
ListNode *mySort(ListNode *head, int len)
{
    if (len <= 1)
        return head;
    ListNode *beforeOfReturn = new ListNode();
    ListNode *itr = beforeOfReturn;
    ListNode *mid = increaseIterator(head, len / 2);
    int leftCnt = 0, leftMaxCnt = len / 2;
    int rightCnt = 0, rightMaxCnt = len - len / 2;
    ListNode *left = mySort(head, len / 2);
    ListNode *right = mySort(mid, len - len / 2);
    while (leftCnt < leftMaxCnt || rightCnt < rightMaxCnt)
    {
        if (leftCnt < leftMaxCnt && (!(rightCnt < rightMaxCnt) || left->val < right->val))
        {
            itr->next = left;
            left = increaseIterator(left, 1);
            leftCnt++;
        }

        else
        {
            itr->next = right;
            right = increaseIterator(right, 1);
            rightCnt++;
        }
        itr = increaseIterator(itr, 1);
    }
    itr->next = nullptr;
    return beforeOfReturn->next;
}

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return mySort(head, getNodeLength(head));
    }
};

void print_node(ListNode *head)
{
    ListNode *itr = head;
    while (itr != nullptr)
    {
        cout << itr->val << " ";
        itr = itr->next;
    }
    cout << "\n";
}
void print_vector(vector<int> &v)
{
    for (auto elem : v)
        cout << elem << " ";
    cout << "\n";
}
vector<int> mySort(const vector<int> &arr, int idx, int len)
{
    if (len <= 1)
        return vector<int>(1, arr[idx]);
    int mid = idx + len / 2;
    vector<int> ret;
    vector<int> left = mySort(arr, idx, len / 2);
    vector<int> right = mySort(arr, mid, len - len / 2);
    int leftIdx = 0, rightIdx = 0;
    while (leftIdx < left.size() || rightIdx < right.size())
    {
        if (leftIdx < left.size() && (rightIdx >= right.size() || left[leftIdx] < right[rightIdx]))
            ret.push_back(left[leftIdx++]);

        else
            ret.push_back(right[rightIdx++]);
    }
    return ret;
}
ListNode *vectorToNode(vector<int> &arr)
{
    ListNode *beforeOfReturn = new ListNode();
    ListNode *itr = beforeOfReturn;
    for (auto elem : arr)
    {
        itr->next = new ListNode(elem);
        itr = increaseIterator(itr, 1);
    }
    return beforeOfReturn->next;
}
int main()
{
    vector<int> arr = {53, 12, 49, 51, 3, 11, 99, 5, 1, 66};
    print_vector(arr);
    vector<int> ret = mySort(arr, 0, arr.size());
    print_vector(ret);

    ListNode *head = vectorToNode(arr);
    print_node(head);
    ListNode *_ret = Solution().sortList(head);
    print_node(_ret);
    return 0;
}

/*
0 7
0 3  [0 1 2]
0 1
1 2
1 1
2 1
3 4 [3 4 5 6]

*/