#include <cassert>
#include <vector>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode *balanceBST(TreeNode *root) {
    std::function<void(TreeNode * node, std::vector<int> & acc)> collect_values;
    collect_values = [&](TreeNode *node, std::vector<int> &acc) {
        if (node == nullptr) {
            return;
        }

        collect_values(node->left, acc);
        acc.push_back(node->val);
        collect_values(node->right, acc);
    };

    std::function<TreeNode *(int left, int right, const std::vector<int> &v)> f;
    f = [&](int left, int right, const std::vector<int> &v) -> TreeNode * {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode *left_tree = f(left, mid - 1, v);
        TreeNode *right_tree = f(mid + 1, right, v);

        return new TreeNode(v[mid], left_tree, right_tree);
    };

    std::vector<int> v;
    collect_values(root, v);

    return f(0, v.size() - 1, v);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        r->right->right = new TreeNode(3);
        r->right->right->right = new TreeNode(4);

        auto *ret = balanceBST(r);
        assert(ret->val == 2);
        assert(ret->left->val == 1);
        assert(ret->right->val == 3);
        assert(ret->right->right->val == 4);

        delete r;
        delete ret;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(3);

        auto *ret = balanceBST(r);
        assert(ret->val == 2);
        assert(ret->left->val == 1);
        assert(ret->right->val == 3);

        delete r;
        delete ret;
    }
    return 0;
}
