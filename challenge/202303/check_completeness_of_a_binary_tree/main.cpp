#include <cassert>
#include <functional>
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

bool isCompleteTree(TreeNode *root) {
    std::function<int(TreeNode *)> count_nodes = [&](TreeNode *node) -> int {
        if (node == nullptr) {
            return 0;
        }

        return 1 + count_nodes(node->left) + count_nodes(node->right);
    };

    int nodes = count_nodes(root);
    std::queue<std::pair<TreeNode *, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        auto [node, index] = q.front();
        q.pop();

        if (node == nullptr) {
            continue;
        }

        if (index > nodes) {
            return false;
        }

        q.push({node->left, 2 * index});
        q.push({node->right, 2 * index + 1});
    }

    return true;
}

int main() {
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->left = new TreeNode(6);

        assert(isCompleteTree(r));
        delete r;
    }
    {
        TreeNode *r = new TreeNode(1);
        r->left = new TreeNode(2);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(5);
        r->right = new TreeNode(3);
        r->right->right = new TreeNode(7);

        assert(!isCompleteTree(r));
        delete r;
    }
    return 0;
}
