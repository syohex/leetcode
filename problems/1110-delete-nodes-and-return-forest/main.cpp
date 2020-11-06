#include <cassert>
#include <cstdio>
#include <functional>
#include <set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

std::vector<TreeNode *> delNodes(TreeNode *root, const std::vector<int> &to_delete) {
    std::set<int> s;
    for (const auto i : to_delete) {
        s.insert(i);
    }

    std::vector<TreeNode *> ret;
    std::function<bool(TreeNode * node)> f;
    f = [&f, &ret, &s](TreeNode *node) -> bool {
        if (node->left == nullptr && node->right == nullptr) {
            return s.find(node->val) != s.end();
        }

        if (node->left != nullptr) {
            if (f(node->left)) {
                node->left = nullptr;
            }
        }

        if (node->right != nullptr) {
            if (f(node->right)) {
                node->right = nullptr;
            }
        }

        if (s.find(node->val) == s.end()) {
            return false;
        }

        if (node->left != nullptr) {
            ret.push_back(node->left);
        }
        if (node->right != nullptr) {
            ret.push_back(node->right);
        }
        return true;
    };

    if (!f(root)) {
        ret.push_back(root);
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(7);
        std::vector<int> to_delete{3, 5};
        auto ret = delNodes(r, to_delete);
        assert(ret.size() == 3);
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(7);
        std::vector<int> to_delete{1, 2, 3, 4, 5, 6, 7};
        auto ret = delNodes(r, to_delete);
        assert(ret.empty());
    }
    return 0;
}
