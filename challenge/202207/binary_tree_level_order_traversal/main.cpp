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

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ret;
    if (root == nullptr) {
        return ret;
    }

    std::deque<TreeNode *> q;
    q.push_back(root);
    while (!q.empty()) {
        int len = q.size();
        std::vector<int> v;
        for (int i = 0; i < len; ++i) {
            TreeNode *node = q.front();
            q.pop_front();

            v.push_back(node->val);

            if (node->left != nullptr) {
                q.push_back(node->left);
            }
            if (node->right != nullptr) {
                q.push_back(node->right);
            }
        }

        ret.push_back(std::move(v));
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);

        std::vector<std::vector<int>> expected{{3}, {9, 20}, {15, 7}};
        auto ret = levelOrder(r);
        assert(ret == expected);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        std::vector<std::vector<int>> expected{{1}};
        auto ret = levelOrder(r);
        assert(ret == expected);

        delete r;
    }
    {
        auto ret = levelOrder(nullptr);
        assert(ret.empty());
    }

    return 0;
}