#include <cassert>
#include <functional>
#include <map>
#include <vector>
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

int pseudoPalindromicPaths(TreeNode *root) {
    const auto isPalindrom = [](const std::vector<int> &v, int len) -> bool {
        int odd = 0;
        for (int n : v) {
            if (n % 2 == 1) {
                ++odd;
            }
        }

        if (len % 2 == 0) {
            return odd == 0;
        }

        return odd == 1;
    };

    std::function<int(TreeNode * node, std::vector<int> & v, int len)> f;
    f = [&](TreeNode *node, std::vector<int> &v, int len) {
        if (node == nullptr) {
            return 0;
        }

        ++v[node->val];
        int ret = 0;
        if (node->left == nullptr && node->right == nullptr) {
            if (isPalindrom(v, len)) {
                ret = 1;
            }
        } else {
            ret += f(node->left, v, len + 1);
            ret += f(node->right, v, len + 1);
        }

        --v[node->val];
        return ret;
    };

    std::vector<int> v(10, 0);
    return f(root, v, 1);
}

int main() {
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(1);
        r->right->right = new TreeNode(1);
        int ret = pseudoPalindromicPaths(r);
        assert(ret == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(1);
        r->left->right->right = new TreeNode(1);
        r->right = new TreeNode(1);
        int ret = pseudoPalindromicPaths(r);
        assert(ret == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(9);
        int ret = pseudoPalindromicPaths(r);
        assert(ret == 1);
        delete r;
    }
    return 0;
}
