#include <cassert>
#include <vector>
#include <functional>
#include <string>
#include <map>

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

std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    std::vector<TreeNode *> ret;
    std::map<std::string, int> m;

    std::function<std::string(TreeNode * node)> f;
    f = [&](TreeNode *node) -> std::string {
        if (node == nullptr) {
            return "";
        }

        std::string left = f(node->left);
        std::string right = f(node->right);
        std::string str = std::to_string(node->val) + "@" + left + "@" + right;
        if (m[str] == 1) {
            ret.push_back(node);
        }

        m[str] += 1;
        return str;
    };

    (void)f(root);
    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(2);
        r->right->left->left = new TreeNode(4);
        r->right->right = new TreeNode(4);

        auto ret = findDuplicateSubtrees(r);
        assert(ret.size() == 2);
        assert(ret[0]->val == 4);
        assert(ret[0]->left == nullptr);
        assert(ret[0]->right == nullptr);
        assert(ret[1]->val == 2);
        assert(ret[1]->left->val == 4);
        assert(ret[1]->left->left == nullptr);
        assert(ret[1]->left->right == nullptr);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        r->right = new TreeNode(1);

        auto ret = findDuplicateSubtrees(r);
        assert(ret.size() == 1);
        assert(ret[0]->val == 1);
        assert(ret[0]->left == nullptr);
        assert(ret[0]->right == nullptr);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);

        auto ret = findDuplicateSubtrees(r);
        assert(ret.size() == 2);
        assert(ret[0]->val == 3);
        assert(ret[0]->left == nullptr);
        assert(ret[0]->right == nullptr);
        assert(ret[1]->val == 2);
        assert(ret[1]->left->val == 3);
        assert(ret[1]->left->left == nullptr);
        assert(ret[1]->left->right == nullptr);

        delete r;
    }
    return 0;
}
