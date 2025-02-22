#include <cassert>
#include <string>
#include <functional>
#include <cctype>
#include <cstdio>

using namespace std;

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

TreeNode *recoverFromPreorder(const string &traversal) {
    function<TreeNode *(size_t next_depth, size_t &pos)> f;
    f = [&](size_t next_depth, size_t &pos) -> TreeNode * {
        size_t dashes = 0;
        size_t orig_pos = pos;
        while (pos < traversal.size() && traversal[pos] == '-') {
            ++dashes;
            ++pos;
        }

        if (dashes != next_depth) {
            pos = orig_pos;
            return nullptr;
        }

        int val = 0;
        while (pos < traversal.size() && isdigit(traversal[pos])) {
            val = val * 10 + traversal[pos] - '0';
            ++pos;
        }

        TreeNode *node = new TreeNode(val);
        node->left = f(next_depth + 1, pos);
        node->right = f(next_depth + 1, pos);
        return node;
    };

    size_t pos = 0;
    return f(0, pos);
}

int main() {
    {
        string traversal{"1-2--3--4-5--6--7"};
        auto ret = recoverFromPreorder(traversal);
        assert(ret->val == 1);
        assert(ret->left->val == 2);
        assert(ret->left->left->val == 3);
        assert(ret->left->right->val == 4);
        assert(ret->right->val == 5);
        assert(ret->right->left->val == 6);
        assert(ret->right->right->val == 7);

        delete ret;
    }
    {
        string traversal{"1-2--3---4-5--6---7"};
        auto ret = recoverFromPreorder(traversal);
        assert(ret->val == 1);
        assert(ret->left->val == 2);
        assert(ret->left->left->val == 3);
        assert(ret->left->left->left->val == 4);
        assert(ret->right->val == 5);
        assert(ret->right->left->val == 6);
        assert(ret->right->left->left->val == 7);

        delete ret;
    }
    {
        string traversal{"1-401--349---90--88"};
        auto ret = recoverFromPreorder(traversal);
        assert(ret->val == 1);
        assert(ret->left->val == 401);
        assert(ret->left->left->val == 349);
        assert(ret->left->right->val == 88);
        assert(ret->left->left->left->val == 90);

        delete ret;
    }
    return 0;
}
