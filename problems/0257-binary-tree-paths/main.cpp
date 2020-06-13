#include <cassert>
#include <string>
#include <vector>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node, const std::string &s)> f;
    f = [&f, &ret](TreeNode *node, const std::string &s) {
        std::string path(s + std::to_string(node->val));
        if (node->left == nullptr && node->right == nullptr) {
            ret.push_back(path);
            return;
        }

        if (node->left != nullptr) {
            f(node->left, path + "->");
        }
        if (node->right != nullptr) {
            f(node->right, path + "->");
        }
    };

    f(root, "");
    return ret;
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->right = new TreeNode(5);
        tree->right = new TreeNode(3);

        std::vector<std::string> expected{
            "1->2->5",
            "1->3",
        };

        auto ret = binaryTreePaths(tree);
        assert(ret == expected);
        delete tree;
    }
    return 0;
}
