#include <cassert>
#include <string>
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

std::string tree2str(TreeNode *t) {
    if (t == nullptr) {
        return "";
    }

    std::function<std::string(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> std::string {
        auto val = std::to_string(node->val);
        if (node->left != nullptr) {
            val.push_back('(');
            val += f(node->left);
            val.push_back(')');
        }
        if (node->right != nullptr) {
            if (node->left == nullptr) {
                val += "()";
            }

            val.push_back('(');
            val += f(node->right);
            val.push_back(')');
        }

        return val;
    };

    return f(t);
}

int main() {
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(4);
        root->right = new TreeNode(3);

        auto ret = tree2str(root);
        assert(ret == "1(2(4))(3)");
        delete root;
    }
    {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->right = new TreeNode(3);

        auto ret = tree2str(root);
        assert(ret == "1(2()(4))(3)");
        delete root;
    }
    return 0;
}
