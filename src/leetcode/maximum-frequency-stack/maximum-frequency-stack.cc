#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> ti;
struct cmp
{
    bool operator()(ti a, ti b)
    {
        // first : freq
        // second : (num, idx)
        if (a.first == b.first)
        {
            return a.second.second < b.second.second;
        }
        return a.first < b.first;
    }
};

class FreqStack
{
    unordered_map<int, int> freq;
    priority_queue<ti, vector<ti>, cmp> pq;
    int idx;

public:
    FreqStack()
    {
        idx = 0;
        freq.clear();
        pq = priority_queue<ti, vector<ti>, cmp>{};
    }
    ti make_tuple(int val)
    {
        return ti(freq[val], p(val, idx++));
    }
    void push(int val)
    {
        int &valFreq = ++freq[val];
        pq.push(make_tuple(val));
    }
    int top()
    {
        return pq.top().second.first;
    }
    int pop()
    {
        int topVal = top();
        pq.pop();
        --freq[topVal];
        return topVal;
    }
    void print()
    {
        priority_queue<ti, vector<ti>, cmp> copy = pq;
        while (!copy.empty())
        {
            ti topElem = copy.top();
            cout << "freq: " << topElem.first << " val: " << topElem.second.first << " idx: " << topElem.second.second << '\n';
            copy.pop();
        }
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
int main()
{
    FreqStack *st = new FreqStack();
    st->push(1);
    st->push(1);
    st->push(2);
    st->push(1);
    cout << st->pop() << "\n";
    cout << st->pop() << "\n";

    st->push(2);
    st->push(2);
    st->push(1);

    cout << st->pop() << "\n";
    cout << st->pop() << "\n";
    cout << st->pop() << "\n";
    // st->push(4);
    // st->push(5);
    // st->print();
    // cout << st->pop() << "\n";
    // cout << st->pop() << "\n";
    // cout << st->pop() << "\n";
    // cout << st->pop() << "\n";
    // 1 1 1 2 pop pop 2 2 1 pop pop pop
    // 1121
    // 121
    // 21
}