#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

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

TreeNode *reverseOddLevels(TreeNode *root) {
    vector<TreeNode *> parent;
    vector<TreeNode *> current;

    current.push_back(root);
    int level = 0;
    while (!current.empty()) {
        vector<TreeNode *> tmp;
        vector<int> vals;
        for (auto *node : current) {
            if (node->left != nullptr) {
                tmp.push_back(node->left);
                tmp.push_back(node->right);
                if (level % 2 == 0) {
                    vals.push_back(node->left->val);
                    vals.push_back(node->right->val);
                }
            }
        }

        parent = current;
        if (!vals.empty()) {
            for (size_t i = 0; i < parent.size(); ++i) {
                size_t base = (parent.size() - i) * 2 - 1;
                parent[i]->left->val = vals[base];
                parent[i]->right->val = vals[base - 1];
            }
        }

        current = tmp;
        ++level;
    }

    return root;
}

int main() {
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(8);
        r->left->right = new TreeNode(13);
        r->right = new TreeNode(5);
        r->right->left = new TreeNode(21);
        r->right->right = new TreeNode(34);

        auto *ret = reverseOddLevels(r);
        assert(ret->val == 2);
        assert(ret->left->val == 5);
        assert(ret->left->left->val == 8);
        assert(ret->left->right->val == 13);
        assert(ret->right->val == 3);
        assert(ret->right->left->val == 21);
        assert(ret->right->right->val == 34);

        delete ret;
    }
    {
        TreeNode *r = new TreeNode(7);
        r->left = new TreeNode(13);
        r->right = new TreeNode(11);

        auto *ret = reverseOddLevels(r);
        assert(ret->val == 7);
        assert(ret->left->val == 11);
        assert(ret->right->val == 13);

        delete ret;
    }
    return 0;
}
