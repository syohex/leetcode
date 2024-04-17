#include <cassert>
#include <functional>
#include <string>
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

std::string smallestFromLeaf(TreeNode *root) {
    const auto is_small = [](const auto &a, const auto &b) -> bool {
        int len1 = a.size()- 1;
        int len2 = b.size()-1;

        while (len1 >= 0 && len2 >= 0) {
            if (a[len1] < b[len2]) {
                return true;
            }
            if (a[len1] > b[len2]) {
                return false;
            }

            --len1;
            --len2;
        }

        return len1 <= len2;
    };

    std::function<void(TreeNode * node, std::vector<char> & acc, std::vector<char> & ret)> f;
    f = [&](TreeNode *node, std::vector<char> &acc, std::vector<char> &ret) {
        if (node == nullptr) {
            return;
        }

        acc.push_back(node->val + 'a');
        if (node->left == nullptr && node->right == nullptr) {
            if (ret.empty() || is_small(acc, ret)) {
                ret = acc;
            }
        } else {
            f(node->left, acc, ret);
            f(node->right, acc, ret);
        }

        acc.pop_back();
    };

    std::vector<char> acc, ret;
    f(root, acc, ret);
    return std::string(ret.rbegin(), ret.rend());
}

int main() {
    {
        TreeNode *r = new TreeNode(0);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(3);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(3);
        r->right->right = new TreeNode(4);

        auto ret = smallestFromLeaf(r);
        assert(ret == "dba");
        delete r;
    }
    {
        TreeNode *r = new TreeNode(25);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(3);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(0);
        r->right->right = new TreeNode(2);

        auto ret = smallestFromLeaf(r);
        assert(ret == "adz");
        delete r;
    }
    return 0;
}
