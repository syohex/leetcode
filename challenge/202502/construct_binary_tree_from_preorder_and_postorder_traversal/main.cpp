#include <cassert>
#include <vector>
#include <functional>

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

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
    std::function<TreeNode*(size_t pre_start, size_t pre_end, size_t post_start)> f;
    f = [&](size_t pre_start, size_t pre_end, size_t post_start) -> TreeNode * {
        if (pre_start > pre_end) {
            return nullptr;
        }

        if (pre_start == pre_end) {
            return new TreeNode(preorder[pre_start]);
        }

        int child_nodes = 1;
        while (postorder[post_start + child_nodes - 1] != preorder[pre_start + 1]) {
            ++child_nodes;
        }

        TreeNode *ret = new TreeNode(preorder[pre_start]);
        ret->left = f(pre_start + 1, pre_start + child_nodes, post_start);
        ret->right = f(pre_start + child_nodes + 1, pre_end, post_start + child_nodes);
        return ret;
    };

    return f(0, preorder.size() - 1, 0);
}

int main() {
    {
        vector<int> preorder{1,2,4,5,3,6,7};
        vector<int> postorder{4,5,2,6,7,3,1};
        auto ret = constructFromPrePost(preorder, postorder);
        assert(ret->val == 1);
        assert(ret->left->val == 2);
        assert(ret->left->left->val == 4);
        assert(ret->left->right->val == 5);
        assert(ret->right->val == 3);
        assert(ret->right->left->val == 6);
        assert(ret->right->right->val == 7);
        delete ret;
    }
    {
        vector<int> preorder{1};
        vector<int> postorder{1};
        auto ret = constructFromPrePost(preorder, postorder);
        assert(ret->val == 1);
        delete ret;
    }
    return 0;
}
