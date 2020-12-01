#include <cassert>
#include <functional>
#include <stack>
#include <algorithm>

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

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    struct Info {
        explicit Info(TreeNode *node, int depth) : node(node), depth(depth) {
        }
        TreeNode *node;
        int depth;
    };

    int ret = 0;
    std::stack<Info> s;
    s.emplace(root, 1);
    while (!s.empty()) {
        auto info = s.top();
        s.pop();

        ret = std::max(ret, info.depth);

        if (info.node->left != nullptr) {
            s.emplace(info.node->left, info.depth + 1);
        }
        if (info.node->right != nullptr) {
            s.emplace(info.node->right, info.depth + 1);
        }
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
        assert(maxDepth(r) == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        assert(maxDepth(r) == 2);
        delete r;
    }
    { assert(maxDepth(nullptr) == 0); }
    {
        TreeNode *r = new TreeNode(0);
        assert(maxDepth(r) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->right = new TreeNode(9);
        r->right->right = new TreeNode(20);
        r->right->right->right = new TreeNode(15);
        r->right->right->right->right = new TreeNode(7);
        assert(maxDepth(r) == 5);
        delete r;
    }
    return 0;
}
