#include <cassert>
#include <functional>
#include <vector>

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

std::vector<int> rightSideView(TreeNode *root) {
    std::vector<std::vector<int>> acc;
    std::function<void(TreeNode * node, size_t depth)> f;
    f = [&f, &acc](TreeNode *node, size_t depth) {
        if (node == nullptr) {
            return;
        }

        if (acc.size() < depth + 1) {
            acc.resize(depth + 1);
        }

        acc[depth].push_back(node->val);
        f(node->left, depth + 1);
        f(node->right, depth + 1);
    };

    f(root, 0);

    std::vector<int> ret;
    for (const auto &v : acc) {
        ret.push_back(v.back());
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

        auto ret = rightSideView(r);
        assert((ret == std::vector<int>{1, 3, 4}));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->left->right = new TreeNode(5);

        auto ret = rightSideView(r);
        assert((ret == std::vector<int>{1, 3, 5}));
        delete r;
    }
    {
        auto ret = rightSideView(nullptr);
        assert(ret.empty());
    }
    return 0;
}
