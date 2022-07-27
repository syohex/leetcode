#include <cassert>
#include <functional>
#include <vector>

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

void flatten(TreeNode *root) {
    std::function<void(TreeNode * node, std::vector<TreeNode *> & nodes)> f;
    f = [&](TreeNode *node, std::vector<TreeNode *> &nodes) {
        if (node == nullptr) {
            return;
        }

        nodes.push_back(node);
        f(node->left, nodes);
        f(node->right, nodes);
    };

    std::vector<TreeNode *> nodes;
    f(root, nodes);

    nodes.push_back(nullptr);

    for (size_t i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->left = nullptr;
        nodes[i]->right = nodes[i + 1];
    }
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(5);
        r->right->right = new TreeNode(6);

        flatten(r);

        assert(r->val == 1);
        assert(r->right->val == 2);
        assert(r->right->right->val == 3);
        assert(r->right->right->right->val == 4);
        assert(r->right->right->right->right->val == 5);
        assert(r->right->right->right->right->right->val == 6);
        assert(r->right->right->right->right->right->left == nullptr);
        assert(r->right->right->right->right->right->right == nullptr);

        delete r;
    }
    { flatten(nullptr); }
    {
        TreeNode *r = new TreeNode(0);
        flatten(r);
        assert(r->val == 0);
        delete r;
    }
    return 0;
}
