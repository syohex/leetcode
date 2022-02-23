#include <cassert>
#include <vector>
#include <functional>
#include <map>

class Node {
  public:
    int val;
    std::vector<Node *> neighbors;

    Node(int _val) : val(_val) {
    }
};

Node *cloneGraph(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    std::map<int, Node *> checked;
    std::function<Node *(Node * node)> f;
    f = [&f, &checked](Node *node) -> Node * {
        if (checked.find(node->val) != checked.end()) {
            return checked[node->val];
        }

        Node *ret = new Node(node->val);
        checked[node->val] = ret;

        for (auto *n : node->neighbors) {
            ret->neighbors.push_back(f(n));
        }

        return ret;
    };

    return f(node);
}

int main() {
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);

        n1->neighbors = {n2, n4};
        n2->neighbors = {n1, n3};
        n3->neighbors = {n2, n4};
        n4->neighbors = {n1, n3};

        auto ret = cloneGraph(n1);
        assert(ret->val == 1);
        assert(ret->neighbors[0]->val == 2);
        assert(ret->neighbors[1]->val == 4);

        auto ret2 = ret->neighbors[0];
        assert(ret2->neighbors[0]->val == 1);
        assert(ret2->neighbors[1]->val == 3);

        auto ret3 = ret2->neighbors[1];
        assert(ret3->neighbors[0]->val == 2);
        assert(ret3->neighbors[1]->val == 4);

        auto ret4 = ret->neighbors[1];
        assert(ret4->neighbors[0]->val == 1);
        assert(ret4->neighbors[1]->val == 3);

        delete n1;
        delete n2;
        delete n3;
        delete n4;

        delete ret;
        delete ret2;
        delete ret3;
        delete ret4;
    }
    return 0;
}
