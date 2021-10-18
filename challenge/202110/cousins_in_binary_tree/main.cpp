#include <cassert>
#include <functional>
#include <memory>

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

bool isCousins(TreeNode *root, int x, int y) {
    struct Data {
        TreeNode *parent;
        int depth;
    };

    std::function<Data *(TreeNode * node, int val, TreeNode *parent, int depth)> f;
    f = [&](TreeNode *node, int val, TreeNode *parent, int depth) -> Data * {
        if (node == nullptr) {
            return nullptr;
        }

        if (val == node->val) {
            return new Data{parent, depth};
        }

        auto ret = f(node->left, val, node, depth + 1);
        if (ret != nullptr) {
            return ret;
        }

        return f(node->right, val, node, depth + 1);
    };

    std::unique_ptr<Data> x_node(f(root, x, nullptr, 0));
    std::unique_ptr<Data> y_node(f(root, y, nullptr, 0));

    return x_node->parent != y_node->parent && x_node->depth == y_node->depth;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->right = new TreeNode(3);

        assert(!isCousins(r, 4, 3));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(5);
        assert(isCousins(r, 5, 4));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(3);

        assert(!isCousins(r, 2, 3));
        delete r;
    }
    return 0;
}