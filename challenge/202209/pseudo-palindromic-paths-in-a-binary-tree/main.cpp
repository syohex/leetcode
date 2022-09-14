#include <cassert>
#include <functional>
#include <map>
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
    const auto isPalindrome = [](const std::map<int, int> &m) -> bool {
        int odds = 0;
        for (const auto &it : m) {
            if (it.second % 2 == 1) {
                ++odds;
            }
        }

        return odds <= 1;
    };

    std::function<int(TreeNode * node, std::map<int, int> & freqs)> f;
    f = [&](TreeNode *node, std::map<int, int> &m) -> int {
        ++m[node->val];

        int ret = 0;
        if (node->left == nullptr && node->right == nullptr) {
            ret = isPalindrome(m) ? 1 : 0;
        } else {
            int left = 0;
            if (node->left != nullptr) {
                left = f(node->left, m);
            }

            int right = 0;
            if (node->right != nullptr) {
                right = f(node->right, m);
            }

            ret = left + right;
        }

        --m[node->val];
        return ret;
    };

    std::map<int, int> m;
    return f(root, m);
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
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->left->right->right = new TreeNode(1);
        r->right = new TreeNode(1);

        int ret = pseudoPalindromicPaths(r);
        assert(ret == 1);
        delete r;
    }
    return 0;
}