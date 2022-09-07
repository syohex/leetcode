#include <cassert>
#include <functional>
#include <string>
#include <sstream>

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

std::string tree2str(TreeNode *root) {
    std::function<std::string(TreeNode * node)> f;
    f = [&f](TreeNode *node) -> std::string {
        if (node == nullptr) {
            return "";
        }

        std::stringstream ss;
        ss << node->val;

        std::string tmp_left = f(node->left);
        std::string tmp_right = f(node->right);

        if (!tmp_left.empty()) {
            ss << "(" << tmp_left << ")";
        }

        if (!tmp_right.empty()) {
            if (tmp_left.empty()) {
                ss << "()";
            }

            ss << "(" << tmp_right << ")";
        }

        return ss.str();
    };

    return f(root);
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->right = new TreeNode(3);

        std::string expected("1(2(4))(3)");
        auto ret = tree2str(r);
        assert(ret == expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(3);

        std::string expected("1(2()(4))(3)");
        auto ret = tree2str(r);
        assert(ret == expected);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(4);

        std::string expected("1(2)(3()(4))");
        auto ret = tree2str(r);
        assert(ret == expected);
        delete r;
    }
    return 0;
}
