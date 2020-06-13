#include <cassert>
#include <vector>
#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    std::function<void(TreeNode * node, std::vector<int> & v)> f;
    f = [&f](TreeNode *node, std::vector<int> &v) {
        if (node->left == nullptr && node->right == nullptr) {
            v.push_back(node->val);
            return;
        }

        if (node->left != nullptr) {
            f(node->left, v);
        }
        if (node->right != nullptr) {
            f(node->right, v);
        }
    };

    std::vector<int> v1, v2;

    f(root1, v1);
    f(root2, v2);

    return v1 == v2;
}

int main() {
    {
        TreeNode *tree = new TreeNode(3);
        tree->left = new TreeNode(5);
        tree->left->left = new TreeNode(6);
        tree->left->right = new TreeNode(2);
        tree->left->right->left = new TreeNode(7);
        tree->left->right->right = new TreeNode(4);

        tree->right = new TreeNode(1);
        tree->right->left = new TreeNode(9);
        tree->right->right = new TreeNode(8);

        assert(leafSimilar(tree, tree));
        delete tree;
    }
    {
        TreeNode *tree1 = new TreeNode(3);
        tree1->left = new TreeNode(5);
        tree1->left->left = new TreeNode(6);
        tree1->left->right = new TreeNode(2);
        tree1->left->right->left = new TreeNode(7);
        tree1->left->right->right = new TreeNode(4);
        tree1->right = new TreeNode(1);
        tree1->right->left = new TreeNode(9);
        tree1->right->right = new TreeNode(8);

        TreeNode *tree2 = new TreeNode(3);
        tree2->left = new TreeNode(5);
        tree2->left->left = new TreeNode(6);
        tree2->left->right = new TreeNode(2);
        tree2->left->right->left = new TreeNode(7);
        tree2->left->right->right = new TreeNode(4);
        tree2->right = new TreeNode(1);
        tree2->right->right = new TreeNode(99);
        tree2->right->right->left = new TreeNode(9);
        tree2->right->right->right = new TreeNode(8);

        assert(leafSimilar(tree1, tree2));
        delete tree1;
        delete tree2;
    }
    return 0;
}
