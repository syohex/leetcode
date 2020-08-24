#include <cassert>
#include <vector>
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

std::vector<std::vector<int>> findLeaves(TreeNode *root) {
    if (root == nullptr) {
        return std::vector<std::vector<int>>{};
    }

    std::function<bool(TreeNode * node, std::vector<int> & v)> f;
    f = [&f](TreeNode *node, std::vector<int> &v) {
        if (node->left == nullptr && node->right == nullptr) {
            v.push_back(node->val);
            return true;
        }

        if (node->left != nullptr) {
            bool isLeaf = f(node->left, v);
            if (isLeaf) {
                node->left = nullptr;
            }
        }
        if (node->right != nullptr) {
            bool isLeaf = f(node->right, v);
            if (isLeaf) {
                node->right = nullptr;
            }
        }

        return false;
    };

    std::vector<std::vector<int>> ret;
    while (true) {
        ret.push_back(std::vector<int>{});
        if (f(root, ret.back())) {
            break;
        }
    }
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->right = new TreeNode(3);
        tree->left->left = new TreeNode(4);
        tree->left->right = new TreeNode(5);
        auto ret = findLeaves(tree);
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{4, 5, 3}));
        assert((ret[1] == std::vector<int>{2}));
        assert((ret[2] == std::vector<int>{1}));
        delete tree;
    }
    return 0;
}
