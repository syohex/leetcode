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

std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }

    std::function<void(TreeNode * node, int acc, const std::vector<int> &v)> f;
    f = [&f, &ret, &sum](TreeNode *node, int acc, const std::vector<int> &v) {
        auto tmp = v;
        tmp.push_back(node->val);
        acc += node->val;

        if (node->left == nullptr && node->right == nullptr) {
            if (acc == sum) {
                ret.push_back(tmp);
            }
            return;
        }

        if (node->left != nullptr) {
            f(node->left, acc, tmp);
        }
        if (node->right != nullptr) {
            f(node->right, acc, tmp);
        }
    };

    f(root, 0, std::vector<int>{});
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->right = new TreeNode(8);
        r->left->left = new TreeNode(11);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(4);
        r->left->left->left = new TreeNode(7);
        r->left->left->right = new TreeNode(2);
        r->right->right->left = new TreeNode(5);
        r->right->right->right = new TreeNode(1);

        auto ret = pathSum(r, 22);
        assert(ret.size() == 2);
        assert((ret[0] == std::vector<int>{5, 4, 11, 2}));
        assert((ret[1] == std::vector<int>{5, 8, 4, 5}));
        delete r;
    }
    return 0;
}
