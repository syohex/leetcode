#include <cassert>
#include <vector>
#include <queue>

class Node {
  public:
    int val;
    std::vector<Node *> children;

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children) {
        val = _val;
        children = _children;
    }

    ~Node() {
        for (Node *n : children) {
            delete n;
        }
    }
};

std::vector<std::vector<int>> levelOrder(Node *root) {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }

    std::deque<Node *> q;
    q.push_back(root);

    while (!q.empty()) {
        size_t len = q.size();

        std::vector<int> tmp;
        for (size_t i = 0; i < len; ++i) {
            Node *node = q.front();
            q.pop_front();

            tmp.push_back(node->val);

            for (Node *child : node->children) {
                q.push_back(child);
            }
        }

        ret.push_back(std::move(tmp));
    }

    return ret;
}

int main() {
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(3);
        Node *n3 = new Node(2);
        Node *n4 = new Node(4);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);

        n1->children.push_back(n2);
        n1->children.push_back(n3);
        n1->children.push_back(n4);

        n2->children.push_back(n5);
        n2->children.push_back(n6);

        std::vector<std::vector<int>> expected{{1}, {3, 2, 4}, {5, 6}};
        auto ret = levelOrder(n1);
        assert(ret == expected);

        delete n1;
    }
    {
        Node *n1 = new Node(1);
        Node *n2 = new Node(2);
        Node *n3 = new Node(3);
        Node *n4 = new Node(4);
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        Node *n7 = new Node(7);
        Node *n8 = new Node(8);
        Node *n9 = new Node(9);
        Node *n10 = new Node(10);
        Node *n11 = new Node(11);
        Node *n12 = new Node(12);
        Node *n13 = new Node(13);
        Node *n14 = new Node(14);

        n1->children.push_back(n2);
        n1->children.push_back(n3);
        n1->children.push_back(n4);
        n1->children.push_back(n5);

        n3->children.push_back(n6);
        n3->children.push_back(n7);
        n4->children.push_back(n8);
        n5->children.push_back(n9);
        n5->children.push_back(n10);

        n7->children.push_back(n11);
        n8->children.push_back(n12);
        n9->children.push_back(n13);

        n11->children.push_back(n14);

        std::vector<std::vector<int>> expected{{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}};
        auto ret = levelOrder(n1);
        assert(ret == expected);

        delete n1;
    }
    return 0;
}