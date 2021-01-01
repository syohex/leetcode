#include <cassert>
#include <functional>
#include <queue>

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

int kthSmallest(TreeNode *root, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    std::function<void(TreeNode * node)> f;
    f = [&f, &q](TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        q.push(node->val);
        f(node->left);
        f(node->right);
    };

    f(root);

    int ret = 0;
    for (int i = 0; i < k; ++i) {
        ret = q.top();
        q.pop();
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->right = new TreeNode(4);
        r->left->right = new TreeNode(2);
        assert(kthSmallest(r, 1) == 1);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->right = new TreeNode(6);
        r->left->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->left->left->left = new TreeNode(1);
        assert(kthSmallest(r, 3) == 3);
        delete r;
    }
    return 0;
}
