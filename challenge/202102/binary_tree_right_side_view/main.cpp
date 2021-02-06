#include <cassert>
#include <vector>
#include <functional>

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

std::vector<int> rightSideVide(TreeNode *root) {
    std::vector<std::vector<int>> v;
    std::function<void(TreeNode * node, size_t depth)> f;
    f = [&f, &v](TreeNode *node, size_t depth) {
        if (node == nullptr) {
            return;
        }

        if (depth + 1 >= v.size()) {
            v.resize(depth + 1);
        }

        f(node->right, depth + 1);
        v[depth].push_back(node->val);
        f(node->left, depth + 1);
    };

    f(root, 0);

    std::vector<int> ret;
    for (const auto &w : v) {
        ret.push_back(w[0]);
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->right = new TreeNode(5);
        r->right->right = new TreeNode(4);
        auto ret = rightSideVide(r);
        assert((ret == std::vector<int>{1, 3, 4}));
        delete r;
    }

    return 0;
}
