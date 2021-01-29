#include <cassert>
#include <vector>
#include <functional>
#include <climits>
#include <algorithm>
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

std::vector<std::vector<int>> verticalTraversal(TreeNode *root) {
    struct Node {
        int val;
        int depth;
        int pos;
    };

    std::vector<Node> nodes;
    int min_pos = INT_MAX;
    int max_pos = 0;
    std::function<void(TreeNode * node, int depth, int pos)> f;
    f = [&f, &nodes, &min_pos, &max_pos](TreeNode *node, int depth, int pos) {
        if (node == nullptr) {
            return;
        }

        nodes.emplace_back(Node{node->val, depth, pos});
        min_pos = std::min(min_pos, pos);
        max_pos = std::max(max_pos, pos);

        f(node->left, depth + 1, pos - 1);
        f(node->right, depth + 1, pos + 1);
    };

    f(root, 0, 0);

    std::sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b) {
        if (a.pos != b.pos) {
            return a.pos < b.pos;
        }

        if (a.depth != b.depth) {
            return a.depth < b.depth;
        }

        return a.val < b.val;
    });

    std::vector<std::vector<int>> ret(max_pos - min_pos + 1);
    for (const auto &node : nodes) {
        int index = node.pos - min_pos;
        ret[index].push_back(node.val);
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        auto ret = verticalTraversal(r);
        assert(ret.size() == 4);
        assert((ret[0] == std::vector<int>{9}));
        assert((ret[1] == std::vector<int>{3, 15}));
        assert((ret[2] == std::vector<int>{20}));
        assert((ret[3] == std::vector<int>{7}));

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(7);

        auto ret = verticalTraversal(r);
        assert(ret.size() == 5);
        assert((ret[0] == std::vector<int>{4}));
        assert((ret[1] == std::vector<int>{2}));
        assert((ret[2] == std::vector<int>{1, 5, 6}));
        assert((ret[3] == std::vector<int>{3}));
        assert((ret[4] == std::vector<int>{7}));

        delete r;
    }
    return 0;
}
