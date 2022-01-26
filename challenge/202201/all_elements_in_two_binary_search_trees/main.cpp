#include <cassert>
#include <vector>
#include <algorithm>

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

std::vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    std::vector<int> ret;

    const auto f = [&ret](TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        std::vector<TreeNode *> q;
        q.push_back(node);

        while (!q.empty()) {
            TreeNode *n = q.back();
            q.pop_back();

            ret.push_back(n->val);
            if (n->left != nullptr) {
                q.push_back(n->left);
            }
            if (n->right != nullptr) {
                q.push_back(n->right);
            }
        }
    };

    f(root1);
    f(root2);
    std::sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    {
        TreeNode *r1 = new TreeNode(2);
        r1->left = new TreeNode(1);
        r1->right = new TreeNode(4);

        TreeNode *r2 = new TreeNode(1);
        r2->left = new TreeNode(0);
        r2->right = new TreeNode(3);

        std::vector<int> expected{0, 1, 1, 2, 3, 4};
        auto ret = getAllElements(r1, r2);
        assert(ret == expected);

        delete r1;
        delete r2;
    }
    {
        TreeNode *r1 = new TreeNode(1);
        r1->right = new TreeNode(8);

        TreeNode *r2 = new TreeNode(8);
        r2->left = new TreeNode(1);

        std::vector<int> expected{1, 1, 8, 8};
        auto ret = getAllElements(r1, r2);
        assert(ret == expected);

        delete r1;
        delete r2;
    }
    return 0;
}
