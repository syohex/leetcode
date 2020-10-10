#include <cassert>
#include <vector>
#include <functional>
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

bool isEvenOddTree(TreeNode *root) {
    std::vector<std::vector<int>> values;

    std::function<bool(TreeNode * node, size_t depth)> f;
    f = [&f, &values](TreeNode *node, size_t depth) -> bool {
        if (depth % 2 == 0) {
            if (node->val % 2 != 1) {
                return false;
            }
        } else {
            if (node->val % 2 == 1) {
                return false;
            }
        }

        if (values.size() < depth + 1) {
            values.resize(depth + 1);
        }
        values[depth].push_back(node->val);

        if (node->left != nullptr) {
            if (!f(node->left, depth + 1)) {
                return false;
            }
        }
        if (node->right != nullptr) {
            if (!f(node->right, depth + 1)) {
                return false;
            }
        }

        return true;
    };

    if (!f(root, 0)) {
        return false;
    }

    printf("[\n");
    for (const auto &v : values) {
        printf("  [");
        for (const auto i : v) {
            printf(" %d ", i);
        }
        printf("]\n");
    }
    printf("]\n");

    for (size_t i = 1; i < values.size(); ++i) {
        for (size_t j = 0; j < values[i].size(); ++j) {
            if (i % 2 == 0) {
                for (size_t k = 1; k <= values[i].size() - 1; ++k) {
                    if (values[i][k - 1] >= values[i][k]) {
                        return false;
                    }
                }
            } else {
                for (size_t k = 1; k <= values[i].size() - 1; ++k) {
                    if (values[i][k - 1] <= values[i][k]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    {
        TreeNode *t = new TreeNode(1);
        t->left = new TreeNode(10);
        t->left->left = new TreeNode(3);
        t->left->left->left = new TreeNode(12);
        t->left->left->right = new TreeNode(8);
        t->right = new TreeNode(4);
        t->right->left = new TreeNode(7);
        t->right->left->left = new TreeNode(6);
        t->right->right = new TreeNode(9);
        t->right->right->right = new TreeNode(2);
        assert(isEvenOddTree(t));
        delete t;
    }
    {
        TreeNode *t = new TreeNode(5);
        t->left = new TreeNode(4);
        t->left->left = new TreeNode(3);
        t->left->right = new TreeNode(3);
        t->right = new TreeNode(2);
        t->right->left = new TreeNode(7);
        assert(!isEvenOddTree(t));
        delete t;
    }
    {
        TreeNode *t = new TreeNode(5);
        t->left = new TreeNode(9);
        t->left->left = new TreeNode(3);
        t->left->right = new TreeNode(5);
        t->right = new TreeNode(1);
        t->right->left = new TreeNode(7);
        assert(!isEvenOddTree(t));
        delete t;
    }
    {
        // [7,34,46,5,null,7,null,null,null,38,34,null,null,25,29,28,24,null,null,13,17]
        TreeNode *t = new TreeNode(7);
        t->left = new TreeNode(34);
        t->right = new TreeNode(46);
        t->left->left = new TreeNode(5);
        t->right->left = new TreeNode(7);
        // null, null, null
        t->right->left->left = new TreeNode(38);
        t->right->left->right = new TreeNode(34);
        // null, null
        t->right->left->right->left = new TreeNode(25);
        t->right->left->right->right = new TreeNode(29);
        t->right->left->right->left->left = new TreeNode(28);
        t->right->left->right->left->right = new TreeNode(24);
        // null, null
        t->right->left->right->left->right->left = new TreeNode(13);
        t->right->left->right->left->right->right = new TreeNode(17);
        assert(!isEvenOddTree(t));
        delete t;
    }
    return 0;
}
