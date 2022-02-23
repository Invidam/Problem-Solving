#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

// Problem site: https://leetcode.com/problems/clone-graph
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Problem site: https://leetcode.com/problems/clone-graph
// Definition for a Node.

bool visited[101][101];
Node *nodes[101];

Node *cloneNode(Node *node)
{
    if (node == NULL)
        return NULL;
    else if (nodes[node->val] == NULL)
        nodes[node->val] = new Node(node->val);

    return nodes[node->val];
}

void makeLink(Node *node, Node *neighbor)
{
    node->neighbors.push_back(neighbor);
    neighbor->neighbors.push_back(node);
}
bool isVisited(Node *node, Node *neighbor)
{
    if (node->val < neighbor->val)
        return visited[node->val][neighbor->val];
    else
        return visited[neighbor->val][node->val];
}
void updateVisit(Node *node, Node *neighbor)
{
    if (node->val < neighbor->val)
        visited[node->val][neighbor->val] = true;
    else
        visited[neighbor->val][node->val] = true;
}
void init()
{
    for (int i = 0; i < 101; ++i)
        nodes[i] = NULL;
    memset(visited, false, sizeof(visited));
}
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        else if (node->neighbors.empty())
            return new Node(node->val);
        init();
        Node *ret = cloneNode(node);
        queue<Node *> q;
        q.push(node);
        int n = 0;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            n = curr->neighbors.size();
            for (int i = 0; i < n; ++i)
            {
                Node *next = curr->neighbors[i];
                nodes[next->val] = cloneNode(next);
                if (isVisited(curr, next))
                    continue;
                updateVisit(curr, next);
                makeLink(cloneNode(curr), cloneNode(next));
                q.push(next);
            }
        }
        return ret;
    }
};
void print_nodes(Node *head)
{

    init();
    queue<Node *> q;
    q.push(head);
    int n = 0;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->val;
        cout << "(";
        for (auto elem : curr->neighbors)
        {
            cout << elem->val << ", ";
        }
        cout << ") -> ";
        n = curr->neighbors.size();
        for (int i = 0; i < n; ++i)
        {
            Node *next = curr->neighbors[i];
            if (isVisited(curr, next))
                continue;
            updateVisit(curr, next);
            q.push(next);
        }
    }
}
int main()
{
    Node *nu = new Node();
    cout << nu->val << "\n";
    cout << cloneNode(nu)->val << "\n";
    Node n1 = Node(1);
    Node n2 = Node(2);
    Node n3 = Node(3);
    Node n4 = Node(4);
    makeLink(&n1, &n2);
    makeLink(&n1, &n4);
    makeLink(&n3, &n2);
    makeLink(&n3, &n4);
    // n1.printNodes();
    auto ret = Solution().cloneGraph(nu);
    print_nodes(ret);
    return 0;
}
