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

int goodNodes(TreeNode *root) {
    std::function<int(TreeNode * node, size_t depth, std::vector<int> & acc)> f;
    f = [&f](TreeNode *node, size_t depth, std::vector<int> &acc) -> int {
        if (node == nullptr) {
            return 0;
        }

        bool ok = true;
        for (size_t i = 0; i < depth; ++i) {
            if (acc[i] > node->val) {
                ok = false;
                break;
            }
        }

        int ret = ok ? 1 : 0;

        acc[depth] = node->val;
        ret += f(node->left, depth + 1, acc);
        ret += f(node->right, depth + 1, acc);
        return ret;
    };

    std::vector<int> acc(100'000);
    return f(root, 0, acc);
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->right = new TreeNode(4);
        r->left->left = new TreeNode(3);
        r->right->left = new TreeNode(1);
        r->right->right = new TreeNode(5);
        assert(goodNodes(r) == 4);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(2);
        assert(goodNodes(r) == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        assert(goodNodes(r) == 1);
        delete r;
    }
    return 0;
}
