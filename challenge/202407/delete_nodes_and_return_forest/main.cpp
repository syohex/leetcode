#include <cassert>
#include <vector>
#include <functional>
#include <set>
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

std::vector<TreeNode *> delNodes(TreeNode *root, const std::vector<int> &to_delete) {
    std::function<TreeNode *(TreeNode * node, std::set<int> & deletes, std::vector<TreeNode *> & acc)> f;
    f = [&](TreeNode *node, std::set<int> &deletes, std::vector<TreeNode *> &acc) -> TreeNode * {
        if (node == nullptr) {
            return nullptr;
        }

        node->left = f(node->left, deletes, acc);
        node->right = f(node->right, deletes, acc);

        if (deletes.find(node->val) != deletes.end()) {
            deletes.erase(node->val);
            if (node->left != nullptr) {
                acc.push_back(node->left);
            }
            if (node->right != nullptr) {
                acc.push_back(node->right);
            }

            return nullptr;
        }

        return node;
    };

    std::set<int> deletes(to_delete.begin(), to_delete.end());
    std::vector<TreeNode *> acc;
    root = f(root, deletes, acc);
    if (root != nullptr) {
        acc.push_back(root);
    }
    return acc;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(7);
        std::vector<int> to_delete{3, 5};

        auto ret = delNodes(r, to_delete);
        assert(ret.size() == 3);
        assert(ret[0]->val == 6);
        assert(ret[1]->val == 7);
        assert(ret[2]->val == 1);
        assert(ret[2]->left->val == 2);
        assert(ret[2]->left->left->val == 4);
        assert(ret[2]->left->right == nullptr);
        assert(ret[2]->right == nullptr);
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(4);
        r->left->right = new TreeNode(3);
        std::vector<int> to_delete{3};

        auto ret = delNodes(r, to_delete);
        assert(ret.size() == 1);
        assert(ret[0]->val == 1);
        assert(ret[0]->left->val == 2);
        assert(ret[0]->left->left == nullptr);
        assert(ret[0]->left->right == nullptr);
        assert(ret[0]->right->val == 4);
    }
    return 0;
}
