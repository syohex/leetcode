#include <cassert>
#include <vector>
#include <string>
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

std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::string> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node, const std::string &path)> f;
    f = [&f, &ret](TreeNode *node, const std::string &path) {
        auto tmp = path;
        if (!tmp.empty()) {
            tmp += "->";
        }

        tmp += std::to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            ret.push_back(tmp);
            return;
        }

        if (node->left != nullptr) {
            f(node->left, tmp);
        }
        if (node->right != nullptr) {
            f(node->right, tmp);
        }
    };

    f(root, "");
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->right = new TreeNode(5);

        auto ret = binaryTreePaths(r);
        std::vector<std::string> expected{
            "1->2->5",
            "1->3",
        };
        assert(ret == expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        auto ret = binaryTreePaths(r);
        std::vector<std::string> expected{
            "1",
        };
        assert(ret == expected);
        delete r;
    }
    return 0;
}
