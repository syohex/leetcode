#include <cassert>
#include <map>
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

std::vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    std::map<int, int> m;
    std::function<void(TreeNode * node)> f;
    f = [&f, &m](TreeNode *node) {
        ++m[node->val];

        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            f(node->left);
        }
        if (node->right != nullptr) {
            f(node->right);
        }
    };

    if (root1 != nullptr) {
        f(root1);
    }
    if (root2 != nullptr) {
        f(root2);
    }

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
        TreeNode *input1 = new TreeNode(2);
        input1->left = new TreeNode(1);
        input1->right = new TreeNode(4);

        TreeNode *input2 = new TreeNode(1);
        input2->left = new TreeNode(0);
        input2->right = new TreeNode(3);
        std::vector<int> expected{0, 1, 1, 2, 3, 4};
        auto ret = getAllElements(input1, input2);
        assert(ret == expected);
        delete input1;
        delete input2;
    }
    {
        TreeNode *input1 = new TreeNode(0);
        input1->left = new TreeNode(-10);
        input1->right = new TreeNode(10);

        TreeNode *input2 = new TreeNode(5);
        input2->left = new TreeNode(1);
        input2->right = new TreeNode(7);
        input2->left->left = new TreeNode(0);
        input2->left->right = new TreeNode(2);
        std::vector<int> expected{-10, 0, 0, 1, 2, 5, 7, 10};
        auto ret = getAllElements(input1, input2);
        assert(ret == expected);
        delete input1;
        delete input2;
    }
    {
        TreeNode *input2 = new TreeNode(5);
        input2->left = new TreeNode(1);
        input2->right = new TreeNode(7);
        input2->left->left = new TreeNode(0);
        input2->left->right = new TreeNode(2);
        std::vector<int> expected{0, 1, 2, 5, 7};
        auto ret = getAllElements(nullptr, input2);
        assert(ret == expected);
        delete input2;
    }
    {
        TreeNode *input1 = new TreeNode(0);
        input1->left = new TreeNode(-10);
        input1->right = new TreeNode(10);

        std::vector<int> expected{-10, 0, 10};
        auto ret = getAllElements(input1, nullptr);
        assert(ret == expected);
        delete input1;
    }

    return 0;
}
