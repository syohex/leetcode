#include <cassert>
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

bool findTarget(TreeNode *root, int k) {
    std::map<int, int> m;
    std::function<void(TreeNode * node)> f;
    f = [&f, &m](TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        ++m[node->val];
        f(node->left);
        f(node->right);
    };

    f(root);

    for (const auto &it : m) {
        const auto &it2 = m.find(k - it.first);
        if (it2 != m.end()) {
            if (it.first == it2->first) {
                if (it2->second >= 2) {
                    return true;
                }
            } else {
                return true;
            }
        }
    }

    return false;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->right = new TreeNode(6);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right->right = new TreeNode(7);

        assert(findTarget(r, 9));
        assert(!findTarget(r, 28));

        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);

        assert(findTarget(r, 4));
        assert(!findTarget(r, 1));
        assert(findTarget(r, 3));

        delete r;
    }
    return 0;
}
