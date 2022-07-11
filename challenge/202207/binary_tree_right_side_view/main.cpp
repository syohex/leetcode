#include <cassert>
#include <vector>
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

std::vector<int> rightSideView(TreeNode *root) {
    std::vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    std::deque<TreeNode *> q;
    q.push_back(root);
    while (!q.empty()) {
        size_t len = q.size();

        TreeNode *node = nullptr;
        for (size_t i = 0; i < len; ++i) {
            node = q.front();
            q.pop_front();

            if (node->left != nullptr) {
                q.push_back(node->left);
            }
            if (node->right != nullptr) {
                q.push_back(node->right);
            }
        }

        if (node != nullptr) {
            ret.push_back(node->val);
        }
    }
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(4);

        std::vector<int> expected{1, 3, 4};
        auto ret = rightSideView(r);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(3);

        std::vector<int> expected{1, 3};
        auto ret = rightSideView(r);
        assert(ret == expected);

        delete r;
    }
    {
        auto ret = rightSideView(nullptr);
        assert(ret.empty());
    }
    return 0;
}