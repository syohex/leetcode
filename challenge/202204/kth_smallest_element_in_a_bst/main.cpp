#include <cassert>
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

int kthSmallest(TreeNode *root, int k) {
    const auto cmp = [](int a, int b) { return a > b; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *t = q.front();
        q.pop();

        pq.push(t->val);

        if (t->left != nullptr) {
            q.push(t->left);
        }
        if (t->right != nullptr) {
            q.push(t->right);
        }
    }

    int ret = -1;
    for (int i = 0; i < k; ++i) {
        ret = pq.top();
        pq.pop();
    }

    return ret;
}

int main() {
    {
        TreeNode *r = new TreeNode(3);
        r->left = new TreeNode(1);
        r->left->right = new TreeNode(2);
        r->right = new TreeNode(4);

        assert(kthSmallest(r, 1) == 1);

        delete r;
    }
    {
        TreeNode *r = new TreeNode(5);
        r->left = new TreeNode(3);
        r->left->left = new TreeNode(2);
        r->left->left->left = new TreeNode(1);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(6);

        assert(kthSmallest(r, 3) == 3);

        delete r;
    }
    return 0;
}
