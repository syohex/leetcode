#include <cassert>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    ~TreeNode() {
        delete left;
        delete right;
    }

    bool Equal(const TreeNode *other) const {
        if (other == nullptr) {
            return false;
        }

        if (val != other->val) {
            return false;
        }

        bool left_result;
        if (left == nullptr) {
            if (other->left == nullptr) {
                left_result = true;
            } else {
                left_result = left->Equal(other->left);
            }
        } else {
            left_result = left->Equal(other->left);
        }

        if (!left_result) {
            return false;
        }

        bool right_result;
        if (right == nullptr) {
            if (other->right == nullptr) {
                right_result = true;
            } else {
                right_result = right->Equal(other->right);
            }
        } else {
            right_result = right->Equal(other->right);
        }

        return right_result;
    }
};

TreeNode *bstFromPreorder(const std::vector<int> &preorder) {
    TreeNode *root = new TreeNode(preorder[0]);
    std::stack<TreeNode *> stack;
    stack.push(root);

    for (size_t i = 1; i < preorder.size(); ++i) {
        TreeNode *node = stack.top();
        TreeNode *next = new TreeNode(preorder[i]);

        while (!stack.empty() && stack.top()->val < next->val) {
            node = stack.top();
            stack.pop();
        }

        if (node->val > next->val) {
            node->left = next;
        } else {
            node->right = next;
        }

        stack.push(next);
    }

    return root;
}

int main() {
    {
        std::vector<int> preorder{8, 5, 1, 7, 10, 12};
        TreeNode *r = new TreeNode(8);
        r->left = new TreeNode(5);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(7);
        r->right = new TreeNode(10);
        r->right->right = new TreeNode(12);

        auto ret = bstFromPreorder(preorder);
        assert(ret->Equal(r));

        delete ret;
        delete r;
    }
    {
        std::vector<int> preorder{1, 3};
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(3);

        auto ret = bstFromPreorder(preorder);
        assert(ret->Equal(r));

        delete ret;
        delete r;
    }
    return 0;
}