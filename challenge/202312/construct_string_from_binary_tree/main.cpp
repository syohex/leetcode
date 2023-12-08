#include <cassert>
#include <string>
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

std::string tree2str(TreeNode *root) {
    std::function<void(TreeNode * node, std::string & acc)> f;
    f = [&f](TreeNode *node, std::string &acc) {
        if (node == nullptr) {
            return;
        }

        acc += std::to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        acc += '(';
        f(node->left, acc);
        acc += ')';

        if (node->right == nullptr) {
            return;
        }

        acc += '(';
        f(node->right, acc);
        acc += ')';
    };

    std::string ret;
    f(root, ret);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->right = new TreeNode(3);

        auto ret = tree2str(r);
        assert(ret == "1(2(4))(3)");
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(3);

        auto ret = tree2str(r);
        assert(ret == "1(2()(4))(3)");
        delete r;
    }
    return 0;
}
