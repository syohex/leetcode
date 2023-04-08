#include <cassert>
#include <vector>
#include <functional>
#include <map>

class Node {
  public:
    int val;
    std::vector<Node *> neighbors;
    Node() : val(0) {
    }

    Node(int _val) : val(_val) {
    }
};

Node *cloneGraph(Node *node) {
    std::map<int, Node *> visited;
    std::function<Node *(Node * node)> f;
    f = [&](Node *node) -> Node * {
        if (node == nullptr) {
            return nullptr;
        }

        if (visited.find(node->val) != visited.end()) {
            return visited[node->val];
        }

        Node *n = new Node(node->val);
        visited[node->val] = n;

        for (Node *p : node->neighbors) {
            n->neighbors.push_back(f(p));
        }

        return n;
    };

    return f(node);
}

int main() {
    {
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

        auto ret = cloneGraph(n1);
        auto p1 = ret;
        auto p2 = ret->neighbors[0];
        auto p3 = ret->neighbors[0]->neighbors[1];
        auto p4 = ret->neighbors[1];

        assert(p1->val == 1);
        assert(p2->val == 2);
        assert(p3->val == 3);
        assert(p4->val == 4);

        assert(p1->neighbors[0] == p2);
        assert(p1->neighbors[1] == p4);
        assert(p2->neighbors[0] == p1);
        assert(p2->neighbors[1] == p3);
        assert(p3->neighbors[0] == p2);
        assert(p3->neighbors[1] == p4);
        assert(p4->neighbors[0] == p1);
        assert(p4->neighbors[1] == p3);

        assert(p1 != n1);
        assert(p2 != n2);
        assert(p3 != n3);
        assert(p4 != n4);

        delete n1;
        delete n2;
        delete n3;
        delete n4;
        delete p1;
        delete p2;
        delete p3;
        delete p4;
    }
    return 0;
}
