#include <cassert>
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

bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
        return false;
    }

    struct Data {
        TreeNode *node;
        int sum;
    };

    std::deque<Data> q;
    q.push_back({root, 0});

    while (!q.empty()) {
        Data d = q.front();
        q.pop_front();

        int sum = d.sum + d.node->val;
        if (d.node->left == nullptr && d.node->right == nullptr) {
            if (sum == targetSum) {
                return true;
            }

            continue;
        }

        if (d.node->left != nullptr) {
            q.push_back({d.node->left, sum});
        }
        if (d.node->right != nullptr) {
            q.push_back({d.node->right, sum});
        }
    }

    return false;
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(11);
        r->left->left->left = new TreeNode(7);
        r->left->left->right = new TreeNode(2);
        r->right = new TreeNode(8);
        r->right->left = new TreeNode(13);
        r->right->right = new TreeNode(4);
        r->right->right->right = new TreeNode(1);

        assert(hasPathSum(r, 22));

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);

        assert(!hasPathSum(r, 5));

        delete r;
    }
    { assert(!hasPathSum(nullptr, 0)); }
    return 0;
}
