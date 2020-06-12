#include <cassert>
#include <vector>
#include <functional>
#include <climits>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    Node() {
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }

    ~Node() {
        for (auto *child : children) {
            delete child;
        }
    }
};

int maxDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(Node *, int)> f;
    f = [&f](Node *node, int depth) -> int {
        if (node->children.empty()) {
            return depth;
        }

        int maxDepth = INT_MIN;
        for (auto *child : node->children) {
            int d = f(child, depth + 1);
            if (d > maxDepth) {
                maxDepth = d;
            }
        }

        return maxDepth;
    };

    return f(root, 1);
}

int main() {
    {
        Node *node = new Node(1);
        node->children.push_back(new Node(3));
        node->children.push_back(new Node(2));
        node->children.push_back(new Node(4));

        node->children[0]->children.push_back(new Node(5));
        node->children[0]->children.push_back(new Node(6));

        assert(maxDepth(node) == 3);
        delete node;
    }
    {
        Node *node = new Node(1);
        node->children.push_back(new Node(2));
        node->children.push_back(new Node(3));
        node->children.push_back(new Node(4));
        node->children.push_back(new Node(5));

        node->children[1]->children.push_back(new Node(6));
        node->children[1]->children.push_back(new Node(7));
        node->children[1]->children[1]->children.push_back(new Node(11));
        node->children[1]->children[1]->children[0]->children.push_back(new Node(14));

        node->children[2]->children.push_back(new Node(8));
        node->children[2]->children[0]->children.push_back(new Node(12));

        node->children[3]->children.push_back(new Node(9));
        node->children[3]->children.push_back(new Node(10));
        node->children[3]->children[0]->children.push_back(new Node(13));

        assert(maxDepth(node) == 5);
        delete node;
    }
    return 0;
}
