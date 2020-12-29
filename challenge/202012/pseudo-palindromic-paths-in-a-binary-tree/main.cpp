#include <cassert>
#include <vector>
#include <functional>
#include <map>

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
    if (root == nullptr) {
        return 0;
    }

    int ret = 0;
    std::function<void(TreeNode * node, size_t depth, std::map<int, int> path)> f;
    f = [&f, &ret](TreeNode *node, size_t depth, std::map<int, int> path) {
        ++path[node->val];
        if (node->left == nullptr && node->right == nullptr) {
            int odds = 0, evens = 0;
            for (const auto &it : path) {
                if (it.second % 2 == 0) {
                    ++evens;
                } else {
                    ++odds;
                }
            }

            if ((depth % 2 == 0 && odds == 0) || (odds == 1)) {
                ++ret;
            }
            return;
        }

        if (node->left != nullptr) {
            f(node->left, depth + 1, path);
        }
        if (node->right != nullptr) {
            f(node->right, depth + 1, path);
        }
    };

    f(root, 1, std::map<int, int>{});
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(1);
        r->right->right = new TreeNode(1);
        assert(pseudoPalindromicPaths(r) == 2);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->left->right->right = new TreeNode(1);
        r->right = new TreeNode(1);
        assert(pseudoPalindromicPaths(r) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(9);
        assert(pseudoPalindromicPaths(r) == 1);
        delete r;
    }
    return 0;
}
