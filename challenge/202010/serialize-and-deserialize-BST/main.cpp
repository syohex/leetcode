#include <cassert>
#include <functional>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

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

std::string serialize(TreeNode *root) {
    if (root == nullptr) {
        return "";
    }

    std::string ret;
    std::function<void(TreeNode * node)> f;
    f = [&f, &ret](TreeNode *node) {
        ret += std::to_string(node->val) + ",";
        if (node->left != nullptr) {
            f(node->left);
        }

        if (node->right != nullptr) {
            f(node->right);
        }
    };

    f(root);
    ret.resize(ret.size() - 1);
    return ret;
}

TreeNode *deserialize(std::string &data) {
    if (data == "") {
        return nullptr;
    }

    std::vector<int> v;
    char *p = &data[0];
    char *q = p;
    while (true) {
        while (*q != ',' && *q != '\0') {
            ++q;
        }

        int val = std::atoi(p);
        v.push_back(val);

        if (*q == '\0') {
            break;
        }

        *q = '\0';
        ++q;
        p = q;
    }

    std::function<void(TreeNode * node, int value)> insert;
    insert = [&insert](TreeNode *node, int value) {
        if (node->val > value) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
                return;
            }

            insert(node->left, value);
            return;
        }
        if (node->val < value) {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
                return;
            }

            insert(node->right, value);
        }
    };

    TreeNode *root = new TreeNode(v[0]);
    for (size_t i = 1; i < v.size(); ++i) {
        insert(root, v[i]);
    }

    return root;
}

int main() {
    {
        TreeNode *t = new TreeNode(2);
        t->left = new TreeNode(1);
        t->right = new TreeNode(3);
        auto ret = serialize(t);
        assert(ret == "2,1,3");

        auto tree = deserialize(ret);
        assert(tree->val == 2);
        assert(tree->left->val == 1);
        assert(tree->right->val == 3);
        delete t;
    }
    {
        TreeNode *t = new TreeNode(2);
        t->left = new TreeNode(1);
        auto ret = serialize(t);
        assert(ret == "2,1");

        auto tree = deserialize(ret);
        assert(tree->val == 2);
        assert(tree->left->val == 1);
        assert(tree->right == nullptr);
        delete t;
    }

    return 0;
}
