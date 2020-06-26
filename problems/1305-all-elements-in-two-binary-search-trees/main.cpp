#include <cassert>
#include <vector>
#include <functional>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }
};

std::vector<int> getAllelements(TreeNode *root1, TreeNode *root2) {
    std::function<void(TreeNode * node)> f;
    std::map<int, int> m;

    f = [&f, &m](TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            ++m[node->val];
            return;
        }

        f(node->left);
        f(node->right);

        ++m[node->val];
    };

    f(root1);
    f(root2);

    std::vector<int> ret;
    for (const auto &it : m) {
        for (int i = 0; i < it.second; ++i) {
            ret.push_back(it.first);
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *tree1 = new TreeNode(2);
        tree1->left = new TreeNode(1);
        tree1->right = new TreeNode(4);

        TreeNode *tree2 = new TreeNode(1);
        tree2->left = new TreeNode(0);
        tree2->right = new TreeNode(3);

        auto ret = getAllelements(tree1, tree2);
        assert((ret == std::vector<int>{0, 1, 1, 2, 3, 4}));
        delete tree1;
        delete tree2;
    }
    {
        TreeNode *tree1 = new TreeNode(0);
        tree1->left = new TreeNode(-10);
        tree1->right = new TreeNode(10);

        TreeNode *tree2 = new TreeNode(5);
        tree2->left = new TreeNode(1);
        tree2->right = new TreeNode(7);
        tree2->left->left = new TreeNode(0);
        tree2->left->right = new TreeNode(2);

        auto ret = getAllelements(tree1, tree2);
        assert((ret == std::vector<int>{-10, 0, 0, 1, 2, 5, 7, 10}));
        delete tree1;
        delete tree2;
    }
    {
        TreeNode *tree1 = nullptr;

        TreeNode *tree2 = new TreeNode(5);
        tree2->left = new TreeNode(1);
        tree2->right = new TreeNode(7);
        tree2->left->left = new TreeNode(0);
        tree2->left->right = new TreeNode(2);

        auto ret = getAllelements(tree1, tree2);
        assert((ret == std::vector<int>{0, 1, 2, 5, 7}));
        delete tree1;
        delete tree2;
    }
    {
        TreeNode *tree1 = new TreeNode(0);
        tree1->left = new TreeNode(-10);
        tree1->right = new TreeNode(10);

        TreeNode *tree2 = nullptr;

        auto ret = getAllelements(tree1, tree2);
        assert((ret == std::vector<int>{-10, 0, 10}));
        delete tree1;
        delete tree2;
    }
    {
        TreeNode *tree1 = new TreeNode(1);
        tree1->right = new TreeNode(8);

        TreeNode *tree2 = new TreeNode(8);
        tree2->left = new TreeNode(1);

        auto ret = getAllelements(tree1, tree2);
        assert((ret == std::vector<int>{1, 1, 8, 8}));
        delete tree1;
        delete tree2;
    }
    return 0;
}
