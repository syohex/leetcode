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

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    std::function<void(TreeNode * node, std::vector<int> & leaves)> f;
    f = [&f](TreeNode *node, std::vector<int> &leaves) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            leaves.push_back(node->val);
            return;
        }

        f(node->left, leaves);
        f(node->right, leaves);
    };

    std::vector<int> leaves1, leaves2;
    f(root1, leaves1);
    f(root2, leaves2);
    return leaves1 == leaves2;
}

int main() {
    {
        TreeNode *r1 = new TreeNode(3);
        r1->left = new TreeNode(5);
        r1->left->left = new TreeNode(6);
        r1->left->right = new TreeNode(2);
        r1->left->right->left = new TreeNode(7);
        r1->left->right->right = new TreeNode(4);
        r1->right = new TreeNode(1);
        r1->right->left = new TreeNode(9);
        r1->right->right = new TreeNode(8);

        TreeNode *r2 = new TreeNode(3);
        r2->left = new TreeNode(5);
        r2->left->left = new TreeNode(6);
        r2->left->right = new TreeNode(7);
        r2->right = new TreeNode(1);
        r2->right->left = new TreeNode(4);
        r2->right->right = new TreeNode(2);
        r2->right->right->left = new TreeNode(9);
        r2->right->right->right = new TreeNode(8);

        assert(leafSimilar(r1, r2));

        delete r1;
        delete r2;
    }
    {
        TreeNode *r1 = new TreeNode(1);
        r1->left = new TreeNode(2);
        r1->right = new TreeNode(3);

        TreeNode *r2 = new TreeNode(1);
        r2->left = new TreeNode(3);
        r2->right = new TreeNode(2);

        assert(!leafSimilar(r1, r2));

        delete r1;
        delete r2;
    }
    return 0;
}
