#include <cassert>
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

int averageOfSubtree(TreeNode *root) {
    struct Data {
        int sum;
        int nodes;
    };

    std::function<Data(TreeNode * node, int &ret)> f;
    f = [&f](TreeNode *node, int &ret) -> Data {
        if (node == nullptr) {
            return {0, 0};
        }

        Data left = f(node->left, ret);
        Data right = f(node->right, ret);

        int sum = node->val + left.sum + right.sum;
        int count = 1 + left.nodes + right.nodes;
        int average = sum / count;

        if (average == node->val) {
            ++ret;
        }

        return {sum, count};
    };

    int ret = 0;
    (void)f(root, ret);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(8);
        r->left->left = new TreeNode(0);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(5);
        r->right->right = new TreeNode(6);

        auto ret = averageOfSubtree(r);
        assert(ret == 5);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        auto ret = averageOfSubtree(r);
        assert(ret == 1);
        delete r;
    }
    return 0;
}
