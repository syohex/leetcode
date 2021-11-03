#include <cassert>
#include <stack>
#include <cstdio>

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

int sumNumbers(TreeNode *root) {
    struct Data {
        TreeNode *node;
        long acc;
    };

    std::stack<Data> stack;
    stack.push({root, 0});
    long ret = 0;

    while (!stack.empty()) {
        Data d = stack.top();
        stack.pop();

        if (d.node == nullptr) {
            continue;
        }

        long val = d.acc * 10 + d.node->val;
        if (d.node->left == nullptr && d.node->right == nullptr) {
            ret += val;
        } else {
            stack.push({d.node->left, val});
            stack.push({d.node->right, val});
        }
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->right = new TreeNode(3);
        assert(sumNumbers(r) == 25);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(4);
        r->left = new TreeNode(9);
        r->left->left = new TreeNode(5);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(0);
        assert(sumNumbers(r) == 1026);
        delete r;
    }
    return 0;
}
