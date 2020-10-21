#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

class Node {
  public:
    int val;
    std::vector<Node *> neighbors;

    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }
};

std::map<int, Node *> m;

Node *cloneGraph(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (m.find(node->val) != m.end()) {
        return m[node->val];
    }

    Node *new_node = new Node(node->val);

    m[node->val] = new_node;
    for (auto *n : node->neighbors) {
        new_node->neighbors.push_back(cloneGraph(n));
    }

    return new_node;
}

int main() {
    {
        m.clear();
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);
        n1->neighbors.push_back(n2);
        n1->neighbors.push_back(n4);
        n2->neighbors.push_back(n1);
        n2->neighbors.push_back(n3);
        n3->neighbors.push_back(n2);
        n3->neighbors.push_back(n4);
        n4->neighbors.push_back(n1);
        n4->neighbors.push_back(n3);

        auto *ret = cloneGraph(n1);
        assert(ret->val == n1->val);
        assert(ret->neighbors.size() == 2);
        auto *ret2 = ret->neighbors[0];
        auto *ret4 = ret->neighbors[1];
        assert(ret2->val == n2->val);
        assert(ret4->val == n4->val);

        assert(ret2->neighbors.size() == 2);
        assert(ret4->neighbors.size() == 2);
        auto *ret1 = ret2->neighbors[0];
        auto *ret3 = ret2->neighbors[1];
        assert(ret1 == ret);
        assert(ret3->val == n3->val);
        assert(ret3->neighbors[0] == ret2);
        assert(ret3->neighbors[1] == ret4);
        assert(ret4->neighbors[0] == ret1);
        assert(ret4->neighbors[1] == ret3);
    }
    {
        m.clear();
        Node *n1 = new Node(1);
        auto *ret = cloneGraph(n1);
        assert(ret->val == n1->val);
        assert(ret->neighbors.empty());
    }
    {
        m.clear();
        auto *ret = cloneGraph(nullptr);
        assert(ret == nullptr);
    }
    {
        m.clear();
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        n1->neighbors.push_back(n2);
        n2->neighbors.push_back(n1);
        auto *ret = cloneGraph(n1);
        auto *ret2 = ret->neighbors[0];
        assert(ret2->neighbors.size() == 1);
        assert(ret == ret2->neighbors[0]);
    }
    return 0;
}
