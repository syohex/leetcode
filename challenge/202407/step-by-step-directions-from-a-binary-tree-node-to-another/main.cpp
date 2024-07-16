#include <cassert>
#include <string>
#include <functional>
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

std::string getDirections(TreeNode *root, int startValue, int destValue) {
    std::function<std::string(TreeNode * node, int val, std::string &acc)> f;
    f = [&](TreeNode *node, int val, std::string &acc) -> std::string {
        if (node == nullptr) {
            return "";
        }

        if (node->val == val) {
            return acc;
        }

        acc.push_back('L');
        std::string tmp = f(node->left, val, acc);
        if (!tmp.empty()) {
            return tmp;
        }
        acc.pop_back();

        acc.push_back('R');
        tmp = f(node->right, val, acc);
        if (!tmp.empty()) {
            return tmp;
        }
        acc.pop_back();

        return "";
    };

    std::string acc;
    std::string start = f(root, startValue, acc);
    acc.clear();
    std::string dest = f(root, destValue, acc);

    if (start.empty()) {
        return dest;
    }
    if (dest.empty()) {
        return std::string(start.size(), 'U');
    }

    size_t len = std::min(start.size(), dest.size());
    for (size_t i = 0; i < len; ++i) {
        if (start[i] != dest[i]) {
            std::string ret(start.size() - i, 'U');
            ret.append(dest.substr(i));
            return ret;
        }
    }

    if (start.size() > dest.size()) {
        return std::string(start.size() - dest.size(), 'U');
    } else if (start.size() < dest.size()) {
        return dest.substr(start.size());
    }

    return "";
}

int main() {
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(4);

        auto ret = getDirections(r, 3, 6);
        assert(ret == "UURL");
        delete r;
    }
    {
        TreeNode *r = new TreeNode(2);
        r->left = new TreeNode(1);
        auto ret = getDirections(r, 2, 1);
        assert(ret == "L");
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(4);

        auto ret = getDirections(r, 3, 5);
        assert(ret == "UU");
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(1);
        r->left->left = new TreeNode(3);
        r->right = new TreeNode(2);
        r->right->left = new TreeNode(6);
        r->right->right = new TreeNode(4);

        auto ret = getDirections(r, 6, 4);
        assert(ret == "UR");
        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(8);
        r->right = new TreeNode(3);
        r->left->left = new TreeNode(1);
        r->right->left = new TreeNode(4);
        r->right->right = new TreeNode(7);
        r->left->left->left = new TreeNode(6);
        auto ret = getDirections(r, 4, 3);
        assert(ret == "U");
        delete r;
    }
    return 0;
}
