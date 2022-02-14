#include <cassert>
#include <algorithm>
#include <queue>

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

int maxDepth(TreeNode *root) {
    struct Data {
        struct TreeNode *node;
        int depth;
    };

    int ret = 0;
    std::deque<Data> q;
    q.push_back({root, 1});

    while (!q.empty()) {
        Data d = q.front();
        q.pop_front();

        if (d.node == nullptr) {
            continue;
        }

        ret = std::max(ret, d.depth);

        q.push_back({d.node->left, d.depth + 1});
        q.push_back({d.node->right, d.depth + 1});
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(9);
        r->right = new TreeNode(20);
        r->right->left = new TreeNode(15);
        r->right->right = new TreeNode(7);
        assert(maxDepth(r) == 3);
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->right = new TreeNode(2);
        assert(maxDepth(r) == 2);
        delete r;
    }
    return 0;
}