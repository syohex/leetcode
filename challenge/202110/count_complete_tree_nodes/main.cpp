#include <cassert>
#include <functional>

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

int countNodes(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::function<int(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        int nodes = 0;
        if (node->left != nullptr) {
            nodes += f(node->left);
        }
        if (node->right != nullptr) {
            nodes += f(node->right);
        }

        return nodes + 1;
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        assert(countNodes(r) == 6);
        delete r;
    }
    assert(countNodes(nullptr) == 0);
    {
        TreeNode *r = new TreeNode(1);
        assert(countNodes(r) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        assert(countNodes(r) == 2);
        delete r;
    }
    return 0;
}