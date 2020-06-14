#include <cassert>
#include <functional>
#include <vector>

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

std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    std::vector<TreeNode *> candidates;
    if (root == nullptr) {
        return candidates;
    }

    std::function<void(TreeNode * node, std::vector<TreeNode *> & v)> f;
    f = [&f](TreeNode *node, std::vector<TreeNode *> &v) {
        v.push_back(node);
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            f(node->left, v);
        }
        if (node->right != nullptr) {
            f(node->right, v);
        }
    };

    f(root, candidates);

    std::function<bool(TreeNode *, TreeNode *)> eq;
    eq = [&eq](TreeNode *n1, TreeNode *n2) {
        if (n1 == nullptr && n2 == nullptr) {
            return true;
        }
        if (n1 == nullptr && n2 != nullptr) {
            return false;
        }
        if (n1 != nullptr && n2 == nullptr) {
            return false;
        }

        if (n1->val != n2->val) {
            return false;
        }

        return eq(n1->left, n2->left) && eq(n1->right, n2->right);
    };

    std::vector<TreeNode *> ret;
    for (size_t i = 0; i < candidates.size() - 1; ++i) {
        if (candidates[i] == nullptr) {
            continue;
        }
        bool hasMatch = false;
        for (size_t j = i + 1; j < candidates.size(); ++j) {
            if (candidates[j] == nullptr) {
                continue;
            }
            if (eq(candidates[i], candidates[j])) {
                if (!hasMatch) {
                    ret.push_back(candidates[i]);
                    hasMatch = true;
                }
                candidates[j] = nullptr;
            }
        }
    }

    return ret;
}

bool Equal(TreeNode *n1, TreeNode *n2) {
    if (n1 == nullptr && n2 == nullptr) {
        return true;
    }
    if (n1 == nullptr && n2 != nullptr) {
        return false;
    }
    if (n1 != nullptr && n2 == nullptr) {
        return false;
    }

    if (n1->val != n2->val) {
        return false;
    }

    return Equal(n1->left, n2->left) && Equal(n1->right, n2->right);
}

int main() {
    {
        TreeNode *tree = new TreeNode(1);
        tree->left = new TreeNode(2);
        tree->left->left = new TreeNode(4);
        tree->right = new TreeNode(3);
        tree->right->left = new TreeNode(2);
        tree->right->right = new TreeNode(4);
        tree->right->left->left = new TreeNode(4);

        auto ret = findDuplicateSubtrees(tree);
        assert(ret.size() == 2);

        TreeNode *t1 = new TreeNode(2);
        t1->left = new TreeNode(4);
        TreeNode *t2 = new TreeNode(4);

        assert(Equal(ret[0], t1));
        assert(Equal(ret[1], t2));
        delete tree;
        delete t1;
        delete t2;
    }
    return 0;
}
