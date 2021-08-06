#include <cassert>
#include <vector>
#include <functional>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    Node(int _val) {
        val = _val;
    }

    Node(int _val, const std::vector<Node *> &_children) {
        val = _val;
        children = _children;
    }

    ~Node() {
        for (auto *node : children) {
            delete node;
        }
    }
};

std::vector<std::vector<int>> levelOrder(Node *root) {
    std::vector<std::vector<int>> ret;
    std::function<void(Node * node, size_t depth)> f;
    f = [&f, &ret](Node *node, size_t depth) {
        if (node == nullptr) {
            return;
        }

        if (depth + 1 > ret.size()) {
            ret.resize(depth + 1);
        }

        ret[depth].push_back(node->val);
        for (auto *n : node->children) {
            f(n, depth + 1);
        }
    };

    f(root, 0);
    return ret;
}

int main() {
    {
        Node *r = new Node(1);
        r->children = {new Node(3), new Node(2), new Node(4)};
        r->children[0]->children = {new Node(5), new Node(6)};

        std::vector<std::vector<int>> expected{
            {1},
            {3, 2, 4},
            {5, 6},
        };
        auto ret = levelOrder(r);
        assert(ret == expected);
    }
    {
        Node *r = new Node(1);
        r->children = {new Node(2), new Node(3), new Node(4), new Node(5)};
        r->children[1]->children = {new Node(6), new Node(7)};
        r->children[2]->children = {new Node(8)};
        r->children[3]->children = {new Node(9), new Node(10)};
        r->children[1]->children[1]->children = {new Node(11)};
        r->children[2]->children[0]->children = {new Node(12)};
        r->children[3]->children[0]->children = {new Node(13)};
        r->children[1]->children[1]->children[0]->children = {new Node(14)};

        std::vector<std::vector<int>> expected{
            {1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14},
        };
        auto ret = levelOrder(r);
        assert(ret == expected);
    }
    return 0;
}
