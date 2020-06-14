#include <cassert>
#include <functional>
#include <vector>
#include <map>
#include <algorithm>

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
    if (root == nullptr) {
        return std::vector<TreeNode *>{};
    }

    std::map<int, std::vector<TreeNode *>> v;
    std::function<int(TreeNode * node, int depth)> f;
    f = [&f, &v](TreeNode *node, int depth) -> int {
        if (node->left == nullptr && node->right == nullptr) {
            v[0].push_back(node);
            return depth;
        }

        int leftDepth = 0, rightDepth = 0;
        if (node->left != nullptr) {
            leftDepth = f(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            rightDepth = f(node->right, depth + 1);
        }

        int d = std::max(leftDepth, rightDepth);
        v[d - depth].push_back(node);
        return d;
    };

    f(root, 0);

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
    for (auto &it : v) {
        std::vector<TreeNode *> &nodes = it.second;
        if (nodes.size() <= 1) {
            continue;
        }
        for (size_t i = 0; i < nodes.size() - 1; ++i) {
            if (nodes[i] == nullptr) {
                continue;
            }
            bool hasMatch = false;
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                if (nodes[j] == nullptr) {
                    continue;
                }
                if (eq(nodes[i], nodes[j])) {
                    if (!hasMatch) {
                        ret.push_back(nodes[i]);
                        hasMatch = true;
                    }
                    nodes[j] = nullptr;
                }
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

        assert((Equal(ret[0], t1) || Equal(ret[0], t2)));
        assert((Equal(ret[1], t1) || Equal(ret[1], t2)));
        delete tree;
        delete t1;
        delete t2;
    }
    return 0;
}
